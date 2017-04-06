/**
 * @file	pci_device_base.h
 * @brief	PCI デバイスの基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"

/**
 * PCI デバイスの基底クラス宣言。
 */
class pci_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	pci_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~pci_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	pci_device_base(const pci_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	pci_device_base(pci_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	pci_device_base &operator=(const pci_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	pci_device_base &operator=(pci_device_base &&src) = delete;

	/**
	 *
	 */
	bool operator==(const pci_device_base &rhs);

	/**
	 *
	 */
	bool operator>(const pci_device_base &rhs);

	/**
	 *
	 */
	virtual void pci_init() = 0;

	/**
	 *
	 */
	void bus(sint16_t bus);

	/**
	 *
	 */
	sint16_t bus();

	/**
	 *
	 */
	void slot(sint16_t slot);

	/**
	 *
	 */
	sint16_t slot();

	/**
	 *
	 */
	uint32_t address(uint8_t function, uint8_t offset);

	/**
	 *
	 */
	uint8_t config_read_uint8(uint8_t function, uint8_t offset);

	/**
	 *
	 */
	void config_write_uint8(uint8_t function, uint8_t offset, uint8_t val);

	/**
	 *
	 */
	uint16_t config_read_uint16(uint8_t function, uint8_t offset);

	/**
	 *
	 */
	void config_write_uint16(uint8_t function, uint8_t offset, uint16_t val);

	/**
	 *
	 */
	uint32_t config_read_uint32(uint8_t function, uint8_t offset);

	/**
	 *
	 */
	void config_write_uint32(uint8_t function, uint8_t offset, uint32_t val);

	/**
	 *
	 */
	uint16_t vendor_id();

	/**
	 *
	 */
	uint16_t device_id();

	/**
	 *
	 */
	void command(uint16_t command);

	/**
	 *
	 */
	uint16_t command();

	/**
	 *
	 */
	void status(uint16_t status);

	/**
	 *
	 */
	uint16_t status();

	/**
	 *
	 */
	uint8_t revision_id();

	/**
	 *
	 */
	uint32_t class_code();

	/**
	 *
	 */
	void cacheline_size(uint8_t cacheline_size);

	/**
	 *
	 */
	uint8_t cacheline_size();

	/**
	 *
	 */
	void latency_timer(uint8_t latency_timer);

	/**
	 *
	 */
	uint8_t latency_timer();

	/**
	 *
	 */
	uint8_t header_type();

	/**
	 *
	 */
	void bist(uint8_t bist);

	/**
	 *
	 */
	uint8_t bist();

	/**
	 *
	 */
	void base_address_register_at(uint8_t index, uint32_t base_address_register);

	/**
	 *
	 */
	uint32_t base_address_register_at(uint8_t index);

	/**
	 *
	 */
	void base_address_register_0(uint32_t base_address_register_0);

	/**
	 *
	 */
	uint32_t base_address_register_0();

	/**
	 *
	 */
	void base_address_register_1(uint32_t base_address_register_1);

	/**
	 *
	 */
	uint32_t base_address_register_1();

	/**
	 *
	 */
	void base_address_register_2(uint32_t base_address_register_2);

	/**
	 *
	 */
	uint32_t base_address_register_2();

	/**
	 *
	 */
	void base_address_register_3(uint32_t base_address_register_3);

	/**
	 *
	 */
	uint32_t base_address_register_3();

	/**
	 *
	 */
	void base_address_register_4(uint32_t base_address_register_4);

	/**
	 *
	 */
	uint32_t base_address_register_4();

	/**
	 *
	 */
	void base_address_register_5(uint32_t base_address_register_5);

	/**
	 *
	 */
	uint32_t base_address_register_5();

	/**
	 *
	 */
	void cardbus_cis_pointer(uint32_t cardbus_cis_pointer);

	/**
	 *
	 */
	uint32_t cardbus_cis_pointer();

	/**
	 *
	 */
	uint16_t subsystem_vendor_id();

	/**
	 *
	 */
	uint16_t subsystem_id();

	/**
	 *
	 */
	void expansion_rom_base_address(uint32_t expansion_rom_base_address);

	/**
	 *
	 */
	uint32_t expansion_rom_base_address();

	/**
	 *
	 */
	uint8_t capabilities_pointer();

	/**
	 *
	 */
	void interrupt_line(uint8_t interrupt_line);

	/**
	 *
	 */
	uint8_t interrupt_line();

	/**
	 *
	 */
	uint8_t interrupt_pin();

	/**
	 *
	 */
	uint8_t min_gnt();

	/**
	 *
	 */
	uint8_t max_lat();

	/**
	 *
	 */
	bool msi_capable();

	/**
	 *
	 */
	uint8_t msi_capability_offset();

	/**
	 *
	 */
	void msi_enable(bool msi_enable);

	/**
	 *
	 */
	bool msi_enable();

	/**
	 *
	 */
	bool msi_per_vector_masking_capable();

	/**
	 *
	 */
	bool msi_64bit_address_capable();

	/**
	 *
	 */
	void msi_multiple_message_enable(sint8_t msi_multiple_message_enable);

	/**
	 *
	 */
	sint8_t msi_multiple_message_enable();

	/**
	 *
	 */
	sint8_t msi_multiple_message_capable();

	/**
	 *
	 */
	void msi_message_address(uint32_t msi_message_address);

	/**
	 *
	 */
	uint32_t msi_message_address();

	/**
	 *
	 */
	void msi_message_upper_address(uint32_t msi_message_upper_address);

	/**
	 *
	 */
	uint32_t msi_message_upper_address();

	/**
	 *
	 */
	void msi_message_data(uint16_t msi_message_data);

	/**
	 *
	 */
	uint16_t msi_message_data();

	/**
	 *
	 */
	void msi_mask_bits(uint32_t msi_mask_bits);

	/**
	 *
	 */
	uint32_t msi_mask_bits();

	/**
	 *
	 */
	uint32_t msi_pending_bits();

	/**
	 *
	 */
	bool msix_capable();

	/**
	 *
	 */
	uint8_t msix_capability_offset();

	/**
	 *
	 */
	void msix_enable(bool msix_enable);

	/**
	 *
	 */
	bool msix_enable();

	/**
	 *
	 */
	void msix_function_mask(bool msix_function_mask);

	/**
	 *
	 */
	bool msix_function_mask();

	/**
	 *
	 */
	uint16_t msix_table_size();

	/**
	 *
	 */
	uint32_t msix_table_offset();

	/**
	 *
	 */
	sint8_t msix_table_bir();

	/**
	 *
	 */
	uint32_t msix_pba_offset();

	/**
	 *
	 */
	sint8_t msix_pba_bir();

	/**
	 *
	 */
	void msix_message_address_at(uint16_t index, uint32_t msix_message_address);

	/**
	 *
	 */
	uint32_t msix_message_address_at(uint16_t index);

	/**
	 *
	 */
	void msix_message_upper_address_at(uint16_t index, uint32_t msix_message_upper_address);

	/**
	 *
	 */
	uint32_t msix_message_upper_address_at(uint16_t index);

	/**
	 *
	 */
	void msix_message_data_at(uint16_t index, uint32_t msix_message_data);

	/**
	 *
	 */
	uint32_t msix_message_data_at(uint16_t index);

	/**
	 *
	 */
	void msix_mask_bit_at(uint16_t index, bool msix_mask_bit);

	/**
	 *
	 */
	bool msix_mask_bit_at(uint16_t index);

	/**
	 *
	 */
	void msix_pending_bit_at(uint16_t index, bool msix_pending_bit);

	/**
	 *
	 */
	bool msix_pending_bit_at(uint16_t index);

	/**
	 *
	 */
	virtual utf8str pci_dump();

protected:
	/**
	 *
	 */
	sint16_t m_bus;

	/**
	 *
	 */
	sint16_t m_slot;

};

