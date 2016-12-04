/**
 * @file	display_console.h
 * @brief	ディスプレイ・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "font_data.h"

#include "console_base.h"

/**
 * ディスプレイコンソールのクラス。
 */
class display_console : public console_base
{

public:
	/**
	 * コンストラクタ。
	 */
	display_console();

	/**
	 * デストラクタ。
	 */
	virtual ~display_console();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	display_console(const display_console &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	display_console(const display_console &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const display_console &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const display_console &&src) = delete;

	/**
	 * コンソールをリセットするための関数。
	 */
	virtual void reset();

	/**
	 * コンソールを再描画するための関数。
	 */
	virtual void refresh();

	/**
	 * コンソールから一文字入力するための関数。
	 * @return コンソールから得られた文字。
	 */
	virtual uint32_t getchar();

	/**
	 * コンソールへ一文字出力するための関数。
	 * @param c UNICODE で表現された一文字。
	 */
	virtual void putchar(uint32_t c);

	/**
	 * UEFI フレームバッファのベースアドレスを設定するための関数。
	 * @param uefifb_addr UEFI フレームバッファのベースアドレス。
	 */
	void uefifb_addr(uint64_t uefifb_addr);

	/**
	 * UEFI フレームバッファのベースアドレスを返す関数。
	 * @return UEFI フレームバッファのベースアドレス。
	 */
	uint64_t uefifb_addr();

	/**
	 * UEFI フレームバッファのサイズを設定するための関数。
	 * @param uefifb_size UEFI フレームバッファのサイズ。
	 */
	void uefifb_size(uint64_t uefifb_size);

	/**
	 * UEFI フレームバッファのサイズを返す関数。
	 * @return UEFI フレームバッファのサイズ。
	 */
	uint64_t uefifb_size();

	/**
	 * UEFI フレームバッファの横ピクセル数を設定するための関数。
	 * @param uefifb_width UEFI フレームバッファの横ピクセル数。
	 */
	void uefifb_width(int uefifb_width);

	/**
	 * UEFI フレームバッファの横ピクセル数を返す関数。
	 * @return UEFI フレームバッファの横ピクセル数。
	 */
	int uefifb_width();

	/**
	 * UEFI フレームバッファの縦ピクセル数を設定するための関数。
	 * @param uefifb_height UEFI フレームバッファの縦ピクセル数。
	 */
	void uefifb_height(int uefifb_height);

	/**
	 * UEFI フレームバッファの縦ピクセル数を返す関数。
	 * @return UEFI フレームバッファの縦ピクセル数。
	 */
	int uefifb_height();

	/**
	 * UEFI フレームバッファのストライドを設定するための関数。
	 * @param uefifb_stride UEFI フレームバッファのストライド。
	 */
	void uefifb_stride(int uefifb_stride);

	/**
	 * UEFI フレームバッファのストライドを返す関数。
	 * @return UEFI フレームバッファのストライド。
	 */
	int uefifb_stride();

	/**
	 * UEFI フレームバッファの赤を表すビットのマスクを設定するための関数。
	 * @param uefifb_mask_red UEFI フレームバッファの赤を表すビットのマスク。
	 */
	void uefifb_mask_red(uint32_t uefifb_mask_red);

	/**
	 * UEFI フレームバッファの赤を表すビットのマスクを返す関数。
	 * @return UEFI フレームバッファの赤を表すビットのマスク。
	 */
	uint32_t uefifb_mask_red();

	/**
	 * UEFI フレームバッファの緑を表すビットのマスクを設定するための関数。
	 * @param uefifb_mask_green UEFI フレームバッファの緑を表すビットのマスク。
	 */
	void uefifb_mask_green(uint32_t uefifb_mask_green);

	/**
	 * UEFI フレームバッファの緑を表すビットのマスクを返す関数。
	 * @return UEFI フレームバッファの緑を表すビットのマスク。
	 */
	uint32_t uefifb_mask_green();

	/**
	 * UEFI フレームバッファの青を表すビットのマスクを設定するための関数。
	 * @param uefifb_mask_blue UEFI フレームバッファの青を表すビットのマスク。
	 */
	void uefifb_mask_blue(uint32_t uefifb_mask_blue);

	/**
	 * UEFI フレームバッファの青を表すビットのマスクを返す関数。
	 * @return UEFI フレームバッファの青を表すビットのマスク。
	 */
	uint32_t uefifb_mask_blue();

	/**
	 * UEFI フレームバッファの予約領域ビットのマスクを設定するための関数。
	 * @param uefifb_mask_reserved UEFI フレームバッファの予約領域ビットのマスク。
	 */
	void uefifb_mask_reserved(uint32_t uefifb_mask_reserved);

	/**
	 * UEFI フレームバッファの予約領域ビットのマスクを返す関数。
	 * @return UEFI フレームバッファの予約領域ビットのマスク。
	 */
	uint32_t uefifb_mask_reserved();

private:
	/**
	 * 指定した位置に指定したフォントを表示する関数。
	 * @param x フォントを表示する横方向の位置。
	 * @param y フォントを表示する縦方向の位置。
	 * @param font 表示したいフォントへのポインタ。
	 */
	void plot_char(uint32_t x, uint32_t y, struct font_data *font);

	/**
	 * UEFI フレームバッファのベースアドレス。
	 */
	uint64_t m_uefifb_addr;

	/**
	 * UEFI フレームバッファのサイズ。
	 */
	uint64_t m_uefifb_size;

	/**
	 * UEFI フレームバッファの横のビット数。
	 */
	int m_uefifb_width;

	/**
	 * UEFI フレームバッファの縦のビット数。
	 */
	int m_uefifb_height;

	/**
	 * UEFI フレームバッファのストライド。
	 */
	int m_uefifb_stride;

	/**
	 * UEFI フレームバッファの赤を表すビットのマスク。
	 */
	uint32_t m_uefifb_mask_red;

	/**
	 * UEFI フレームバッファの緑を表すビットのマスク。
	 */
	uint32_t m_uefifb_mask_green;

	/**
	 * UEFI フレームバッファの青を表すビットのマスク。
	 */
	uint32_t m_uefifb_mask_blue;

	/**
	 * UEFI フレームバッファの予約領域ビットのマスク。
	 */
	uint32_t m_uefifb_mask_reserved;

};

