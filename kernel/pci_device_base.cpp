/**
 * @file	pci_device_base.cpp
 * @brief	PCI デバイス基底クラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "pci_device_management.h"

#include "pci_device_base.h"

pci_device_base::pci_device_base()
	: m_bus(-1), m_slot(-1)
{
}

pci_device_base::~pci_device_base()
{
}

bool
pci_device_base::operator==(const pci_device_base &rhs)
{
	if ((m_bus == rhs.m_bus)
	 && (m_slot == rhs.m_slot)) {
		return true;
	}
	return false;
}

bool
pci_device_base::operator>(const pci_device_base &rhs)
{
	if ((m_bus > rhs.m_bus)
	 || ((m_bus == rhs.m_bus)
	  && (m_slot > rhs.m_slot))) {
		return true;
	}
	return false;
}

void
pci_device_base::bus(sint16_t bus)
{
	m_bus = bus;
}

sint16_t
pci_device_base::bus()
{
	return m_bus;
}

void
pci_device_base::slot(sint16_t slot)
{
	m_slot = slot;
}

sint16_t
pci_device_base::slot()
{
	return m_slot;
}

uint32_t
pci_device_base::address(uint8_t function, uint8_t offset)
{
	return pci_address(m_bus, m_slot, function, offset);
}

uint8_t
pci_device_base::config_read_uint8(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint8(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint8(uint8_t function, uint8_t offset, uint8_t val)
{
	pci_config_write_uint8(m_bus, m_slot, function, offset, val);
}

uint16_t
pci_device_base::config_read_uint16(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint16(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint16(uint8_t function, uint8_t offset, uint16_t val)
{
	pci_config_write_uint16(m_bus, m_slot, function, offset, val);
}

uint32_t
pci_device_base::config_read_uint32(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint32(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint32(uint8_t function, uint8_t offset, uint32_t val)
{
	pci_config_write_uint32(m_bus, m_slot, function, offset, val);
}

uint16_t
pci_device_base::vendor_id()
{
	return config_read_uint16(0, 0x00);
}

uint16_t
pci_device_base::device_id()
{
	return config_read_uint16(0, 0x02);
}

void
pci_device_base::command(uint16_t command)
{
	config_write_uint16(0, 0x04, command);
}

uint16_t
pci_device_base::command()
{
	return config_read_uint16(0, 0x04);
}

void
pci_device_base::status(uint16_t status)
{
	config_write_uint16(0, 0x06, status);
}

uint16_t
pci_device_base::status()
{
	return config_read_uint16(0, 0x06);
}

uint8_t
pci_device_base::revision_id()
{
	return config_read_uint8(0, 0x08);
}

uint32_t
pci_device_base::class_code()
{
	return config_read_uint32(0, 0x08) >> 8;
}

void
pci_device_base::cacheline_size(uint8_t cacheline_size)
{
	config_write_uint8(0, 0x0c, cacheline_size);
}

uint8_t
pci_device_base::cacheline_size()
{
	return config_read_uint8(0, 0x0c);
}

void
pci_device_base::latency_timer(uint8_t latency_timer)
{
	config_write_uint8(0, 0x0d, latency_timer);
}

uint8_t
pci_device_base::latency_timer()
{
	return config_read_uint8(0, 0x0d);
}

uint8_t
pci_device_base::header_type()
{
	return config_read_uint8(0, 0x0e);
}

void
pci_device_base::bist(uint8_t bist)
{
	config_write_uint8(0, 0x0f, bist);
}

uint8_t
pci_device_base::bist()
{
	return config_read_uint8(0, 0x0f);
}

void
pci_device_base::base_address_register_at(uint8_t index, uint32_t base_address_register)
{
	switch (index) {
	case 0:
		base_address_register_0(base_address_register);
		break;
	case 1:
		base_address_register_1(base_address_register);
		break;
	case 2:
		base_address_register_2(base_address_register);
		break;
	case 3:
		base_address_register_3(base_address_register);
		break;
	case 4:
		base_address_register_4(base_address_register);
		break;
	case 5:
		base_address_register_5(base_address_register);
		break;
	}
}

uint32_t
pci_device_base::base_address_register_at(uint8_t index)
{
	uint32_t ret = 0;
	switch (index) {
	case 0:
		ret = base_address_register_0();
		break;
	case 1:
		ret = base_address_register_1();
		break;
	case 2:
		ret = base_address_register_2();
		break;
	case 3:
		ret = base_address_register_3();
		break;
	case 4:
		ret = base_address_register_4();
		break;
	case 5:
		ret = base_address_register_5();
		break;
	}
	return ret;
}

void
pci_device_base::base_address_register_0(uint32_t base_address_register_0)
{
	config_write_uint32(0, 0x10, base_address_register_0);
}

uint32_t
pci_device_base::base_address_register_0()
{
	return config_read_uint32(0, 0x10);
}

void
pci_device_base::base_address_register_1(uint32_t base_address_register_1)
{
	config_write_uint32(0, 0x14, base_address_register_1);
}

uint32_t
pci_device_base::base_address_register_1()
{
	return config_read_uint32(0, 0x14);
}

void
pci_device_base::base_address_register_2(uint32_t base_address_register_2)
{
	config_write_uint32(0, 0x18, base_address_register_2);
}

uint32_t
pci_device_base::base_address_register_2()
{
	return config_read_uint32(0, 0x18);
}

void
pci_device_base::base_address_register_3(uint32_t base_address_register_3)
{
	config_write_uint32(0, 0x1c, base_address_register_3);
}

uint32_t
pci_device_base::base_address_register_3()
{
	return config_read_uint32(0, 0x1c);
}

void
pci_device_base::base_address_register_4(uint32_t base_address_register_4)
{
	config_write_uint32(0, 0x20, base_address_register_4);
}

uint32_t
pci_device_base::base_address_register_4()
{
	return config_read_uint32(0, 0x20);
}

void
pci_device_base::base_address_register_5(uint32_t base_address_register_5)
{
	config_write_uint32(0, 0x24, base_address_register_5);
}

uint32_t
pci_device_base::base_address_register_5()
{
	return config_read_uint32(0, 0x24);
}

void
pci_device_base::cardbus_cis_pointer(uint32_t cardbus_cis_pointer)
{
	config_write_uint32(0, 0x28, cardbus_cis_pointer);
}

uint32_t
pci_device_base::cardbus_cis_pointer()
{
	return config_read_uint32(0, 0x28);
}

uint16_t
pci_device_base::subsystem_vendor_id()
{
	return config_read_uint16(0, 0x2c);
}

uint16_t
pci_device_base::subsystem_id()
{
	return config_read_uint16(0, 0x2e);
}

void
pci_device_base::expansion_rom_base_address(uint32_t expansion_rom_base_address)
{
	config_write_uint32(0, 0x30, expansion_rom_base_address);
}

uint32_t
pci_device_base::expansion_rom_base_address()
{
	return config_read_uint32(0, 0x30);
}

uint8_t
pci_device_base::capabilities_pointer()
{
	return config_read_uint8(0, 0x34);
}

void
pci_device_base::interrupt_line(uint8_t interrupt_line)
{
	config_write_uint8(0, 0x3c, interrupt_line);
}

uint8_t
pci_device_base::interrupt_line()
{
	return config_read_uint8(0, 0x3c);
}

uint8_t
pci_device_base::interrupt_pin()
{
	return config_read_uint8(0, 0x3d);
}

uint8_t
pci_device_base::min_gnt()
{
	return config_read_uint8(0, 0x3e);
}

uint8_t
pci_device_base::max_lat()
{
	return config_read_uint8(0, 0x3f);
}

bool
pci_device_base::msi_capable()
{
	bool msi_capable = false;

	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		if (capid == 0x05) {
			msi_capable = true;
			break;
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	return msi_capable;
}

uint8_t
pci_device_base::msi_capability_offset()
{
	uint8_t msi_capability_offset = 0;

	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		if (capid == 0x05) {
			msi_capability_offset = capp;
			break;
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	return msi_capability_offset;
}

void
pci_device_base::msi_enable(bool msi_enable)
{
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0xfffe;
		if (msi_enable == true) {
			tmp |= 0x0001;
		}
		pci_config_write_uint16(m_bus, m_slot, 0, offset + 2, tmp);
	}
}

bool
pci_device_base::msi_enable()
{
	bool msi_enable = false;
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		if ((tmp & 0x0001) != 0x0000) {
			msi_enable = true;
		}
	}
	return msi_enable;
}

bool
pci_device_base::msi_per_vector_masking_capable()
{
	bool msi_per_vector_masking_capable = false;
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		if ((tmp & 0x0100) != 0x0000) {
			msi_per_vector_masking_capable = true;
		}
	}
	return msi_per_vector_masking_capable;
}

bool
pci_device_base::msi_64bit_address_capable()
{
	bool msi_64bit_address_capable = false;
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		if ((tmp & 0x0080) != 0x0000) {
			msi_64bit_address_capable = true;
		}
	}
	return msi_64bit_address_capable;
}

void
pci_device_base::msi_multiple_message_enable(sint8_t msi_multiple_message_enable)
{
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0xff8f;
		switch (msi_multiple_message_enable) {
		case 1:
			tmp |= 0x0000;
			break;
		case 2:
			tmp |= 0x0010;
			break;
		case 4:
			tmp |= 0x0020;
			break;
		case 8:
			tmp |= 0x0030;
			break;
		case 16:
			tmp |= 0x0040;
			break;
		case 32:
			tmp |= 0x0050;
			break;
		}
		pci_config_write_uint16(m_bus, m_slot, 0, offset + 2, tmp);
	}
}

sint8_t
pci_device_base::msi_multiple_message_enable()
{
	sint8_t msi_multiple_message_enable = -1;
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0xff8f;
		switch (tmp) {
		case 0x0000:
			msi_multiple_message_enable = 1;
			break;
		case 0x0010:
			msi_multiple_message_enable = 2;
			break;
		case 0x0020:
			msi_multiple_message_enable = 4;
			break;
		case 0x0030:
			msi_multiple_message_enable = 8;
			break;
		case 0x0040:
			msi_multiple_message_enable = 16;
			break;
		case 0x0050:
			msi_multiple_message_enable = 32;
			break;
		}
	}
	return msi_multiple_message_enable;
}

sint8_t
pci_device_base::msi_multiple_message_capable()
{
	sint8_t msi_multiple_message_capable = -1;
	uint8_t offset = msi_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0xfff1;
		switch (tmp) {
		case 0x0000:
			msi_multiple_message_capable = 1;
			break;
		case 0x0002:
			msi_multiple_message_capable = 2;
			break;
		case 0x0004:
			msi_multiple_message_capable = 4;
			break;
		case 0x0006:
			msi_multiple_message_capable = 8;
			break;
		case 0x0008:
			msi_multiple_message_capable = 16;
			break;
		case 0x000a:
			msi_multiple_message_capable = 32;
			break;
		}
	}
	return msi_multiple_message_capable;
}

void
pci_device_base::msi_message_address(uint32_t msi_message_address)
{
	uint8_t offset = msi_capability_offset();
	uint32_t tmp = msi_message_address & 0xfffffffc;
	pci_config_write_uint32(m_bus, m_slot, 0, offset + 4, tmp);
}

uint32_t
pci_device_base::msi_message_address()
{
	uint8_t offset = msi_capability_offset();
	uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 4);
	return tmp;
}

void
pci_device_base::msi_message_upper_address(uint32_t msi_message_upper_address)
{
	uint8_t offset = msi_capability_offset();
	if (msi_64bit_address_capable()) {
		uint32_t tmp = msi_message_upper_address;
		pci_config_write_uint32(m_bus, m_slot, 0, offset + 8, tmp);
	}
}

uint32_t
pci_device_base::msi_message_upper_address()
{
	uint8_t offset = msi_capability_offset();
	uint32_t msi_message_upper_address = 0;
	if (msi_64bit_address_capable()) {
		uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 8);
		msi_message_upper_address = tmp;
	}
	return msi_message_upper_address;
}

void
pci_device_base::msi_message_data(uint16_t msi_message_data)
{
	uint8_t offset = msi_capability_offset();
	offset += 8;
	if (msi_64bit_address_capable()) {
		offset += 4;
	}
	pci_config_write_uint16(m_bus, m_slot, 0, offset, msi_message_data);
}

uint16_t
pci_device_base::msi_message_data()
{
	uint8_t offset = msi_capability_offset();
	offset += 8;
	if (msi_64bit_address_capable()) {
		offset += 4;
	}
	return pci_config_read_uint16(m_bus, m_slot, 0, offset);
}

void
pci_device_base::msi_mask_bits(uint32_t msi_mask_bits)
{
	uint8_t offset = msi_capability_offset();
	if (msi_per_vector_masking_capable()) {
		offset += 12;
		if (msi_64bit_address_capable()) {
			offset += 4;
		}
		pci_config_write_uint32(m_bus, m_slot, 0, offset, msi_mask_bits);
	}
}

uint32_t
pci_device_base::msi_mask_bits()
{
	uint8_t offset = msi_capability_offset();
	if (msi_per_vector_masking_capable()) {
		offset += 12;
		if (msi_64bit_address_capable()) {
			offset += 4;
		}
		return pci_config_read_uint32(m_bus, m_slot, 0, offset);
	}
	return 0;
}

uint32_t
pci_device_base::msi_pending_bits()
{
	uint8_t offset = msi_capability_offset();
	if (msi_per_vector_masking_capable()) {
		offset += 16;
		if (msi_64bit_address_capable()) {
			offset += 4;
		}
		return pci_config_read_uint32(m_bus, m_slot, 0, offset);
	}
	return 0;
}

bool
pci_device_base::msix_capable()
{
	bool msix_capable = false;

	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		if (capid == 0x11) {
			msix_capable = true;
			break;
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	return msix_capable;
}

uint8_t
pci_device_base::msix_capability_offset()
{
	uint8_t msix_capability_offset = 0;

	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		if (capid == 0x11) {
			msix_capability_offset = capp;
			break;
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	return msix_capability_offset;
}

void
pci_device_base::msix_enable(bool msix_enable)
{
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0x7fff;
		if (msix_enable == true) {
			tmp |= 0x8000;
		}
		pci_config_write_uint16(m_bus, m_slot, 0, offset + 2, tmp);
	}
}

bool
pci_device_base::msix_enable()
{
	bool msix_enable = false;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		if ((tmp & 0x8000) != 0x0000) {
			msix_enable = true;
		}
	}
	return msix_enable;
}

void
pci_device_base::msix_function_mask(bool msix_function_mask)
{
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		tmp &= 0xbfff;
		if (msix_function_mask == true) {
			tmp |= 0x4000;
		}
		pci_config_write_uint16(m_bus, m_slot, 0, offset + 2, tmp);
	}
}

bool
pci_device_base::msix_function_mask()
{
	bool msix_function_mask = false;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		if ((tmp & 0x4000) != 0x0000) {
			msix_function_mask = true;
		}
	}
	return msix_function_mask;
}

uint16_t
pci_device_base::msix_table_size()
{
	uint16_t msix_table_size = 0;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint16_t tmp = pci_config_read_uint16(m_bus, m_slot, 0, offset + 2);
		msix_table_size = tmp & 0x07ff;
		++msix_table_size;
	}
	return msix_table_size;
}

uint32_t
pci_device_base::msix_table_offset()
{
	uint32_t msix_table_offset = 0;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 4);
		msix_table_offset = tmp & 0xfffffff8;
	}
	return msix_table_offset;
}

sint8_t
pci_device_base::msix_table_bir()
{
	sint8_t msix_table_bir = 0;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 4);
		msix_table_bir = tmp & 0x07;
	}
	return msix_table_bir;
}

uint32_t
pci_device_base::msix_pba_offset()
{
	uint32_t msix_pba_offset = 0;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 8);
		msix_pba_offset = tmp & 0xfffffff8;
	}
	return msix_pba_offset;
}

sint8_t
pci_device_base::msix_pba_bir()
{
	sint8_t msix_pba_bir = 0;
	uint8_t offset = msix_capability_offset();
	if (offset != 0) {
		uint32_t tmp = pci_config_read_uint32(m_bus, m_slot, 0, offset + 8);
		msix_pba_bir = tmp & 0x07;
	}
	return msix_pba_bir;
}

void
pci_device_base::msix_message_address_at(uint16_t index, uint32_t msix_message_address)
{
	if (index >= msix_table_size()) {
		return;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	p[index * 4] = msix_message_address;
}

uint32_t
pci_device_base::msix_message_address_at(uint16_t index)
{
	if (index >= msix_table_size()) {
		return 0;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	return p[index * 4];
}

void
pci_device_base::msix_message_upper_address_at(uint16_t index, uint32_t msix_message_upper_address)
{
	if (index >= msix_table_size()) {
		return;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	p[index * 4 + 1] = msix_message_upper_address;
}

uint32_t
pci_device_base::msix_message_upper_address_at(uint16_t index)
{
	if (index >= msix_table_size()) {
		return 0;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	return p[index * 4 + 1];
}

void
pci_device_base::msix_message_data_at(uint16_t index, uint32_t msix_message_data)
{
	if (index >= msix_table_size()) {
		return;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	p[index * 4 + 2] = msix_message_data;
}

uint32_t
pci_device_base::msix_message_data_at(uint16_t index)
{
	if (index >= msix_table_size()) {
		return 0;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	return p[index * 4 + 2];
}

void
pci_device_base::msix_mask_bit_at(uint16_t index, bool msix_mask_bit)
{
	if (index >= msix_table_size()) {
		return;
	}
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	uint32_t tmp = p[index * 4 + 3] & 0xfffffffe;
	if (msix_mask_bit == true) {
		tmp |= 0x00000001;
	}
	p[index * 4 + 3] = tmp;
}

bool
pci_device_base::msix_mask_bit_at(uint16_t index)
{
	if (index >= msix_table_size()) {
		return 0;
	}
	bool msix_mask_bit = false;
	uint64_t bar = base_address_register_at(msix_table_bir()) & 0xfffffff0;
	uint32_t *p = (uint32_t *)bar;
	if ((p[index * 4 + 3] & 0x00000001) == 0x00000001) {
		msix_mask_bit = true;
	}
	return msix_mask_bit;
}

void
pci_device_base::msix_pending_bit_at(uint16_t index, bool msix_pending_bit)
{
	if (index >= msix_table_size()) {
		return;
	}
	uint64_t bar = base_address_register_at(msix_pba_bir()) & 0xfffffff0;
	uint64_t *p = (uint64_t *)bar;
	uint64_t tmp = p[(index >> 6)];
	tmp &= ~(0x1ull << (index & 0x3f));
	if (msix_pending_bit == true) {
		tmp |= (0x1ull << (index & 0x3f));
	}
	p[(index >> 6)] = tmp;
}

bool
pci_device_base::msix_pending_bit_at(uint16_t index)
{
	if (index >= msix_table_size()) {
		return 0;
	}
	uint64_t bar = base_address_register_at(msix_pba_bir()) & 0xfffffff0;
	uint64_t *p = (uint64_t *)bar;
	uint64_t tmp = p[(index >> 6)];
	uint64_t mask = 0x1ull << (index & 0x3f);
	bool msix_pending_bit = false;
	if ((tmp & mask) == mask) {
		msix_pending_bit = true;
	}
	return msix_pending_bit;
}

utf8str
pci_device_base::pci_dump()
{
	utf8str s;
	s += "Bus: ";
	s.append_hex64(m_bus, 2);
	s += " Slot: ";
	s.append_hex64(m_slot, 2);
	s += "\n";
	s += "    Vendor ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x00), 4);
	s += " Device ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x02), 4);
	s += "\n";
	s += "    Command: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x04), 4);
	s += " Status: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x06), 4);
	s += "\n";
	s += "    Revision ID: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x08), 2);
	s += " Class Code: ";
	s.append_hex64((pci_config_read_uint32(m_bus, m_slot, 0, 0x08) >> 8), 6);
	s += "\n";
	s += "    Cacheline Size: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0c), 2);
	s += " Latency Timer: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0d), 2);
	s += " Header Type: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0e), 2);
	s += " BIST: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0f), 2);
	s += "\n";
	if (pci_config_read_uint8(m_bus, m_slot, 0, 0x0e) != 0x00) {
		return s;
	}
	s += "    Base Address Register 1: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x10), 8);
	s += "\n";
	s += "    Base Address Register 2: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x14), 8);
	s += "\n";
	s += "    Base Address Register 3: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x18), 8);
	s += "\n";
	s += "    Base Address Register 4: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x1c), 8);
	s += "\n";
	s += "    Base Address Register 5: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x20), 8);
	s += "\n";
	s += "    Base Address Register 6: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x24), 8);
	s += "\n";
	s += "    Cardbus CIS Pointer: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x28), 8);
	s += "\n";
	s += "    Subsystem Vendor ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x2c), 4);
	s += " Subsystem ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x2e), 4);
	s += "\n";
	s += "    Expansion ROM Base Address: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x30), 8);
	s += "\n";
	s += "    Capabilities Pointer: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x34), 2);
	s += " Reserved: ";
	s.append_hex64((pci_config_read_uint32(m_bus, m_slot, 0, 0x34) >> 8), 6);
	s += "\n";
	s += "    Reserved: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x38), 8);
	s += "\n";
	s += "    Interrupt Line: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3c), 2);
	s += " Interrupt Pin: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3d), 2);
	s += " Min_Gnt: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3e), 2);
	s += " Max_Lat: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3f), 2);
	s += "\n";

	s += "    Capabilities List:\n";
	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		s += "        Capability ID: ";
		s.append_hex64(capid, 2);
		switch (capid) {
		case 0x01: s += " (PCI Power Management Interface)\n"; break;
		case 0x02: s += " (AGP)\n"; break;
		case 0x03: s += " (VPD)\n"; break;
		case 0x04: s += " (Slot Identification)\n"; break;
		case 0x05: s += " (Message Signaled Interrupts)\n"; break;
		case 0x06: s += " (CompactPCI Hot Swap)\n"; break;
		case 0x07: s += " (PCI-X)\n"; break;
		case 0x08: s += " (HyperTransport)\n"; break;
		case 0x09: s += " (Vendor Specific)\n"; break;
		case 0x0a: s += " (Debug port)\n"; break;
		case 0x0b: s += " (CompactPCI central resource control)\n"; break;
		case 0x0c: s += " (PCI Hot-Plug)\n"; break;
		case 0x0d: s += " (PCI Bridge Subsystem Vendor ID)\n"; break;
		case 0x0e: s += " (AGP 8x)\n"; break;
		case 0x0f: s += " (Secure Device)\n"; break;
		case 0x10: s += " (PCI Express)\n"; break;
		case 0x11:
			s += " (MSI-X)\n";
			s += "            Message Control: ";
			s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, capp + 2), 4);
			s += "\n            Table Offset: ";
			s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, capp + 4), 8);
			s += "\n            PBA Offset: ";
			s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, capp + 8), 8);
			s += "\n";
			break;
		default:
			s += " (Unknown Capability)\n";
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	if (msi_capable()) {
		s += "    MSI:\n";
		s += "        Capability Offset: ";
		s.append_hex64(msi_capability_offset(), 1);
		s += "\n";
		s += "        MSI Enable: ";
		if (msi_enable()) {
			s += "TRUE\n";
		} else {
			s += "FALSE\n";
		}
	}

	if (msix_capable()) {
		s += "    MSI-X:\n";
		s += "        Capability Offset: ";
		s.append_hex64(msix_capability_offset(), 8);
		s += "\n";
		s += "        MSI-X Enable: ";
		if (msix_enable()) {
			s += "TRUE\n";
		} else {
			s += "FALSE\n";
		}
		s += "        MSI-X Table Size: ";
		s.append_hex64(msix_table_size(), 8);
		s += "\n";
		for (int i = 0; i < msix_table_size(); ++i) {
			s += "        ";
			s.append_hex64(i, 4);
			s += " ";
			s.append_hex64(msix_message_address_at(i), 8);
			s += " ";
			s.append_hex64(msix_message_upper_address_at(i), 8);
			s += " ";
			s.append_hex64(msix_message_data_at(i), 8);
			s += " ";
			if (msix_mask_bit_at(i) == true) {
				s += "T";
			} else {
				s += "F";
			}
			s += "\n";
		}
	}

	return s;
}

