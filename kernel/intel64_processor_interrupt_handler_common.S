/**
 * @file	intel64_processor_interrupt_handler_entry.S
 * @brief	Intel64 CPU の割り込みハンドラ関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

	.code64

	.global	interrupt_handler_common
interrupt_handler_common:

	// RDI と RSI を使いたいのでスタックに退避
	pushq	%rdi
	pushq	%rsi

	// プロセッサ ID の取得
	movq	$0x00000000fee00020, %rsi
	movq	0(%rsi), %rdi
	shrq	$24, %rdi
	andq	$0xff, %rdi

	// プロセッサステートを格納する領域のアドレス計算
	shlq	$3, %rdi
	addq	$processor_state_storage, %rdi
	movq	0(%rdi), %rsi

	// RAX から RDX までを退避
	movq	%rax, 0x48(%rsi)
	movq	%rbx, 0x50(%rsi)
	movq	%rcx, 0x58(%rsi)
	movq	%rdx, 0x60(%rsi)

	// プロセッサステートを格納する領域のアドレスベースを RSI を RAX に切り
	// 替え
	movq	%rsi, %rax

	// スタックに退避しておいた RDI と RSI を復元
	popq	%rsi
	popq	%rdi

	// RDI と RSI を退避
	movq	%rdi, 0x68(%rax)
	movq	%rsi, 0x70(%rax)

	// interrupt_handler_0x** でスタックに退避した割り込み時に積まれたスタッ
	// クの大きさと GSI を RDI と RSI にポップ
	popq	%rdi			// 割り込みでスタックされた大きさ
	popq	%rsi			// GSI

	// 割り込み時に積まれたスタックの大きさと GSI を退避
	movq	%rdi, 0x08(%rax)	// 割り込みでスタックされた大きさ
	movq	%rsi, 0x00(%rax)	// GSI

	// RBP を退避
	movq	%rbp, 0x78(%rax)

	// R8 から R15 までを退避
	movq	%r8,  0x80(%rax)
	movq	%r9,  0x88(%rax)
	movq	%r10, 0x90(%rax)
	movq	%r11, 0x98(%rax)
	movq	%r12, 0xa0(%rax)
	movq	%r13, 0xa8(%rax)
	movq	%r14, 0xb0(%rax)
	movq	%r15, 0xb8(%rax)

	// 割り込み発生時にプロセッサがスタックしたレジスタの値を退避
	addq	%rdi, %rsp
	movq	-0x08(%rsp), %rbx	// SS
	movq	%rbx, 0x18(%rax)
	movq	-0x10(%rsp), %rbx	// RSP
	movq	%rbx, 0x20(%rax)
	movq	-0x18(%rsp), %rbx	// RFLAGS
	movq	%rbx, 0x28(%rax)
	movq	-0x20(%rsp), %rbx	// CS
	movq	%rbx, 0x30(%rax)
	movq	-0x28(%rsp), %rbx	// RIP
	movq	%rbx, 0x38(%rax)
	movq	-0x30(%rsp), %rbx	// Error Code
	movq	%rbx, 0x40(%rax)

	// ページテーブルへのポインタ退避
	movq	%cr3, %rbx
	movq	%rbx, 0x10(%rax)

	// C++ で書かれたコードを呼び出し
	callq	interrupt_handler_dispatcher

	// プロセッサ ID の取得
	movq	$0x00000000fee00020, %rsi
	movq	0(%rsi), %rdi
	shrq	$24, %rdi
	andq	$0xff, %rdi

	// プロセッサステートを格納する領域のアドレス計算
	shlq	$3, %rdi
	addq	$processor_state_storage, %rdi
	movq	0(%rdi), %rsi

	// ページテーブルすげ替えとスタック切り替え
	movq	0x10(%rsi), %rdi
	movq	%rdi, %cr3
	movq	0x20(%rsi), %rdi
	movq	%rdi, %rsp

	// 割り込み発生時にプロセッサがスタックしたレジスタの値を差し替え
	movq	0x18(%rsi), %rbx	// SS
	movq	%rbx, -0x08(%rsp)
	movq	0x20(%rsi), %rbx	// RSP
	movq	%rbx, -0x10(%rsp)
	movq	0x28(%rsi), %rbx	// RFLAGS
	movq	%rbx, -0x18(%rsp)
	movq	0x30(%rsi), %rbx	// CS
	movq	%rbx, -0x20(%rsp)
	movq	0x38(%rsi), %rbx	// RIP
	movq	%rbx, -0x28(%rsp)
	movq	0x40(%rsi), %rbx	// Error Code
	movq	%rbx, -0x30(%rsp)

	// RSP を割り込み発生後の状態に調整
	movq	0x08(%rsi), %rdi
	subq	%rdi, %rsp

	// RAX から RDX までを復元
	movq	0x48(%rsi), %rax
	movq	0x50(%rsi), %rbx
	movq	0x58(%rsi), %rcx
	movq	0x60(%rsi), %rdx

	// RDI から R15 までを復元
	pushq	%rax
	movq	%rsi, %rax
	movq	0x68(%rax), %rdi
	movq	0x70(%rax), %rsi
	movq	0x78(%rax), %rbp
	movq	0x80(%rax), %r8
	movq	0x88(%rax), %r9
	movq	0x90(%rax), %r10
	movq	0x98(%rax), %r11
	movq	0xa0(%rax), %r12
	movq	0xa8(%rax), %r13
	movq	0xb0(%rax), %r14
	movq	0xb8(%rax), %r15
	popq	%rax

	// EOI
	pushq	%rax
	movabsq	$0xfee000b0, %rax
	movl	$0x0, (%rax)
	popq	%rax

	iretq

