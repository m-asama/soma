/**
 * @file	spinlock.h
 * @brief	スピンロッククラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"

class spinlock {

public:
	/**
	 *
	 */
	spinlock();
	
	/**
	 *
	 */
	virtual ~spinlock();
	
	/**
	 *
	 */
	spinlock(const spinlock &src) = delete;
	
	/**
	 *
	 */
	spinlock(const spinlock &&src) = delete;
	
	/**
	 *
	 */
	spinlock &operator=(const spinlock &src) = delete;
	
	/**
	 *
	 */
	spinlock &operator=(const spinlock &&src) = delete;

	/**
	 *
	 */
	void acquire();

	/**
	 *
	 */
	void release();

private:
	/**
	 *
	 */
	uint64_t m_locked;

	/**
	 *
	 */
	uint64_t m_processor_id;

	/**
	 *
	 */
	uint64_t m_interrupts[256];

};

