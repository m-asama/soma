/**
 * @file	ring_buffer.cpp
 * @brief	リングバッファのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

template<class V>
ring_buffer<V>::ring_buffer(uint64_t size)
	: m_buffer(nullptr), m_size(0), m_next_read(0), m_next_write(0)
{
	uint64_t t = 1;
	while (t < size) {
		t <<= 1;
	}
	m_buffer = new V[t];
	m_size = t;
}

template<class V>
ring_buffer<V>::~ring_buffer()
{
	if (m_buffer != nullptr) {
		delete[] m_buffer;
		m_buffer = nullptr;
	}
	m_size = 0;
	m_next_read = 0;
	m_next_write = 0;
}

template<class V>
V
ring_buffer<V>::operator[](uint64_t i)
{
	return m_buffer[(m_next_read + i) & (m_size - 1)];
}

template<class V>
bool
ring_buffer<V>::read(V &d)
{
	if (readable()) {
		d = m_buffer[m_next_read & (m_size - 1)];
		m_next_read = (m_next_read + 1) & (m_size - 1);
		return true;
	} else {
		return false;
	}
}

template<class V>
bool
ring_buffer<V>::write(V &d)
{
	if (writeable()) {
		m_buffer[m_next_write & (m_size - 1)] = d;
		m_next_write = (m_next_write + 1) & (m_size - 1);
		return true;
	} else {
		return false;
	}
}

template<class V>
uint64_t
ring_buffer<V>::readable()
{
	return (m_next_write - m_next_read) & (m_size - 1);
}

template<class V>
uint64_t
ring_buffer<V>::writeable()
{
	return (m_next_read - m_next_write - 1) & (m_size - 1);
}

