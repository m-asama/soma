/**
 * @file	intel64_processor_interrupt_handler_entry.S
 * @brief	Intel64 CPU の割り込みハンドラ関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

	.code64

	.global	interrupt_handler_0x00
interrupt_handler_0x00:
	pushq	$0x00
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x01
interrupt_handler_0x01:
	pushq	$0x01
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x02
interrupt_handler_0x02:
	pushq	$0x02
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x03
interrupt_handler_0x03:
	pushq	$0x03
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x04
interrupt_handler_0x04:
	pushq	$0x04
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x05
interrupt_handler_0x05:
	pushq	$0x05
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x06
interrupt_handler_0x06:
	pushq	$0x06
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x07
interrupt_handler_0x07:
	pushq	$0x07
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x08
interrupt_handler_0x08:
	pushq	$0x08
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x09
interrupt_handler_0x09:
	pushq	$0x09
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0a
interrupt_handler_0x0a:
	pushq	$0x0a
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0b
interrupt_handler_0x0b:
	pushq	$0x0b
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0c
interrupt_handler_0x0c:
	pushq	$0x0c
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0d
interrupt_handler_0x0d:
	pushq	$0x0d
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0e
interrupt_handler_0x0e:
	pushq	$0x0e
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x0f
interrupt_handler_0x0f:
	pushq	$0x0f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x10
interrupt_handler_0x10:
	pushq	$0x10
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x11
interrupt_handler_0x11:
	pushq	$0x11
	pushq	$48
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x12
interrupt_handler_0x12:
	pushq	$0x12
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x13
interrupt_handler_0x13:
	pushq	$0x13
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x14
interrupt_handler_0x14:
	pushq	$0x14
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x15
interrupt_handler_0x15:
	pushq	$0x15
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x16
interrupt_handler_0x16:
	pushq	$0x16
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x17
interrupt_handler_0x17:
	pushq	$0x17
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x18
interrupt_handler_0x18:
	pushq	$0x18
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x19
interrupt_handler_0x19:
	pushq	$0x19
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1a
interrupt_handler_0x1a:
	pushq	$0x1a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1b
interrupt_handler_0x1b:
	pushq	$0x1b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1c
interrupt_handler_0x1c:
	pushq	$0x1c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1d
interrupt_handler_0x1d:
	pushq	$0x1d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1e
interrupt_handler_0x1e:
	pushq	$0x1e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x1f
interrupt_handler_0x1f:
	pushq	$0x1f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x20
interrupt_handler_0x20:
	pushq	$0x20
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x21
interrupt_handler_0x21:
	pushq	$0x21
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x22
interrupt_handler_0x22:
	pushq	$0x22
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x23
interrupt_handler_0x23:
	pushq	$0x23
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x24
interrupt_handler_0x24:
	pushq	$0x24
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x25
interrupt_handler_0x25:
	pushq	$0x25
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x26
interrupt_handler_0x26:
	pushq	$0x26
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x27
interrupt_handler_0x27:
	pushq	$0x27
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x28
interrupt_handler_0x28:
	pushq	$0x28
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x29
interrupt_handler_0x29:
	pushq	$0x29
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2a
interrupt_handler_0x2a:
	pushq	$0x2a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2b
interrupt_handler_0x2b:
	pushq	$0x2b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2c
interrupt_handler_0x2c:
	pushq	$0x2c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2d
interrupt_handler_0x2d:
	pushq	$0x2d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2e
interrupt_handler_0x2e:
	pushq	$0x2e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x2f
interrupt_handler_0x2f:
	pushq	$0x2f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x30
interrupt_handler_0x30:
	pushq	$0x30
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x31
interrupt_handler_0x31:
	pushq	$0x31
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x32
interrupt_handler_0x32:
	pushq	$0x32
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x33
interrupt_handler_0x33:
	pushq	$0x33
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x34
interrupt_handler_0x34:
	pushq	$0x34
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x35
interrupt_handler_0x35:
	pushq	$0x35
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x36
interrupt_handler_0x36:
	pushq	$0x36
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x37
interrupt_handler_0x37:
	pushq	$0x37
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x38
interrupt_handler_0x38:
	pushq	$0x38
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x39
interrupt_handler_0x39:
	pushq	$0x39
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3a
interrupt_handler_0x3a:
	pushq	$0x3a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3b
interrupt_handler_0x3b:
	pushq	$0x3b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3c
interrupt_handler_0x3c:
	pushq	$0x3c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3d
interrupt_handler_0x3d:
	pushq	$0x3d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3e
interrupt_handler_0x3e:
	pushq	$0x3e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x3f
interrupt_handler_0x3f:
	pushq	$0x3f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x40
interrupt_handler_0x40:
	pushq	$0x40
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x41
interrupt_handler_0x41:
	pushq	$0x41
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x42
interrupt_handler_0x42:
	pushq	$0x42
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x43
interrupt_handler_0x43:
	pushq	$0x43
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x44
interrupt_handler_0x44:
	pushq	$0x44
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x45
interrupt_handler_0x45:
	pushq	$0x45
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x46
interrupt_handler_0x46:
	pushq	$0x46
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x47
interrupt_handler_0x47:
	pushq	$0x47
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x48
interrupt_handler_0x48:
	pushq	$0x48
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x49
interrupt_handler_0x49:
	pushq	$0x49
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4a
interrupt_handler_0x4a:
	pushq	$0x4a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4b
interrupt_handler_0x4b:
	pushq	$0x4b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4c
interrupt_handler_0x4c:
	pushq	$0x4c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4d
interrupt_handler_0x4d:
	pushq	$0x4d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4e
interrupt_handler_0x4e:
	pushq	$0x4e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x4f
interrupt_handler_0x4f:
	pushq	$0x4f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x50
interrupt_handler_0x50:
	pushq	$0x50
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x51
interrupt_handler_0x51:
	pushq	$0x51
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x52
interrupt_handler_0x52:
	pushq	$0x52
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x53
interrupt_handler_0x53:
	pushq	$0x53
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x54
interrupt_handler_0x54:
	pushq	$0x54
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x55
interrupt_handler_0x55:
	pushq	$0x55
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x56
interrupt_handler_0x56:
	pushq	$0x56
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x57
interrupt_handler_0x57:
	pushq	$0x57
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x58
interrupt_handler_0x58:
	pushq	$0x58
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x59
interrupt_handler_0x59:
	pushq	$0x59
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5a
interrupt_handler_0x5a:
	pushq	$0x5a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5b
interrupt_handler_0x5b:
	pushq	$0x5b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5c
interrupt_handler_0x5c:
	pushq	$0x5c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5d
interrupt_handler_0x5d:
	pushq	$0x5d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5e
interrupt_handler_0x5e:
	pushq	$0x5e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x5f
interrupt_handler_0x5f:
	pushq	$0x5f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x60
interrupt_handler_0x60:
	pushq	$0x60
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x61
interrupt_handler_0x61:
	pushq	$0x61
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x62
interrupt_handler_0x62:
	pushq	$0x62
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x63
interrupt_handler_0x63:
	pushq	$0x63
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x64
interrupt_handler_0x64:
	pushq	$0x64
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x65
interrupt_handler_0x65:
	pushq	$0x65
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x66
interrupt_handler_0x66:
	pushq	$0x66
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x67
interrupt_handler_0x67:
	pushq	$0x67
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x68
interrupt_handler_0x68:
	pushq	$0x68
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x69
interrupt_handler_0x69:
	pushq	$0x69
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6a
interrupt_handler_0x6a:
	pushq	$0x6a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6b
interrupt_handler_0x6b:
	pushq	$0x6b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6c
interrupt_handler_0x6c:
	pushq	$0x6c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6d
interrupt_handler_0x6d:
	pushq	$0x6d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6e
interrupt_handler_0x6e:
	pushq	$0x6e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x6f
interrupt_handler_0x6f:
	pushq	$0x6f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x70
interrupt_handler_0x70:
	pushq	$0x70
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x71
interrupt_handler_0x71:
	pushq	$0x71
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x72
interrupt_handler_0x72:
	pushq	$0x72
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x73
interrupt_handler_0x73:
	pushq	$0x73
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x74
interrupt_handler_0x74:
	pushq	$0x74
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x75
interrupt_handler_0x75:
	pushq	$0x75
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x76
interrupt_handler_0x76:
	pushq	$0x76
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x77
interrupt_handler_0x77:
	pushq	$0x77
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x78
interrupt_handler_0x78:
	pushq	$0x78
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x79
interrupt_handler_0x79:
	pushq	$0x79
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7a
interrupt_handler_0x7a:
	pushq	$0x7a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7b
interrupt_handler_0x7b:
	pushq	$0x7b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7c
interrupt_handler_0x7c:
	pushq	$0x7c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7d
interrupt_handler_0x7d:
	pushq	$0x7d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7e
interrupt_handler_0x7e:
	pushq	$0x7e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x7f
interrupt_handler_0x7f:
	pushq	$0x7f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x80
interrupt_handler_0x80:
	pushq	$0x80
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x81
interrupt_handler_0x81:
	pushq	$0x81
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x82
interrupt_handler_0x82:
	pushq	$0x82
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x83
interrupt_handler_0x83:
	pushq	$0x83
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x84
interrupt_handler_0x84:
	pushq	$0x84
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x85
interrupt_handler_0x85:
	pushq	$0x85
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x86
interrupt_handler_0x86:
	pushq	$0x86
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x87
interrupt_handler_0x87:
	pushq	$0x87
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x88
interrupt_handler_0x88:
	pushq	$0x88
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x89
interrupt_handler_0x89:
	pushq	$0x89
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8a
interrupt_handler_0x8a:
	pushq	$0x8a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8b
interrupt_handler_0x8b:
	pushq	$0x8b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8c
interrupt_handler_0x8c:
	pushq	$0x8c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8d
interrupt_handler_0x8d:
	pushq	$0x8d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8e
interrupt_handler_0x8e:
	pushq	$0x8e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x8f
interrupt_handler_0x8f:
	pushq	$0x8f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x90
interrupt_handler_0x90:
	pushq	$0x90
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x91
interrupt_handler_0x91:
	pushq	$0x91
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x92
interrupt_handler_0x92:
	pushq	$0x92
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x93
interrupt_handler_0x93:
	pushq	$0x93
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x94
interrupt_handler_0x94:
	pushq	$0x94
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x95
interrupt_handler_0x95:
	pushq	$0x95
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x96
interrupt_handler_0x96:
	pushq	$0x96
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x97
interrupt_handler_0x97:
	pushq	$0x97
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x98
interrupt_handler_0x98:
	pushq	$0x98
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x99
interrupt_handler_0x99:
	pushq	$0x99
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9a
interrupt_handler_0x9a:
	pushq	$0x9a
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9b
interrupt_handler_0x9b:
	pushq	$0x9b
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9c
interrupt_handler_0x9c:
	pushq	$0x9c
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9d
interrupt_handler_0x9d:
	pushq	$0x9d
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9e
interrupt_handler_0x9e:
	pushq	$0x9e
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0x9f
interrupt_handler_0x9f:
	pushq	$0x9f
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa0
interrupt_handler_0xa0:
	pushq	$0xa0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa1
interrupt_handler_0xa1:
	pushq	$0xa1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa2
interrupt_handler_0xa2:
	pushq	$0xa2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa3
interrupt_handler_0xa3:
	pushq	$0xa3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa4
interrupt_handler_0xa4:
	pushq	$0xa4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa5
interrupt_handler_0xa5:
	pushq	$0xa5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa6
interrupt_handler_0xa6:
	pushq	$0xa6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa7
interrupt_handler_0xa7:
	pushq	$0xa7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa8
interrupt_handler_0xa8:
	pushq	$0xa8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xa9
interrupt_handler_0xa9:
	pushq	$0xa9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xaa
interrupt_handler_0xaa:
	pushq	$0xaa
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xab
interrupt_handler_0xab:
	pushq	$0xab
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xac
interrupt_handler_0xac:
	pushq	$0xac
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xad
interrupt_handler_0xad:
	pushq	$0xad
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xae
interrupt_handler_0xae:
	pushq	$0xae
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xaf
interrupt_handler_0xaf:
	pushq	$0xaf
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb0
interrupt_handler_0xb0:
	pushq	$0xb0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb1
interrupt_handler_0xb1:
	pushq	$0xb1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb2
interrupt_handler_0xb2:
	pushq	$0xb2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb3
interrupt_handler_0xb3:
	pushq	$0xb3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb4
interrupt_handler_0xb4:
	pushq	$0xb4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb5
interrupt_handler_0xb5:
	pushq	$0xb5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb6
interrupt_handler_0xb6:
	pushq	$0xb6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb7
interrupt_handler_0xb7:
	pushq	$0xb7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb8
interrupt_handler_0xb8:
	pushq	$0xb8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xb9
interrupt_handler_0xb9:
	pushq	$0xb9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xba
interrupt_handler_0xba:
	pushq	$0xba
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xbb
interrupt_handler_0xbb:
	pushq	$0xbb
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xbc
interrupt_handler_0xbc:
	pushq	$0xbc
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xbd
interrupt_handler_0xbd:
	pushq	$0xbd
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xbe
interrupt_handler_0xbe:
	pushq	$0xbe
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xbf
interrupt_handler_0xbf:
	pushq	$0xbf
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc0
interrupt_handler_0xc0:
	pushq	$0xc0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc1
interrupt_handler_0xc1:
	pushq	$0xc1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc2
interrupt_handler_0xc2:
	pushq	$0xc2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc3
interrupt_handler_0xc3:
	pushq	$0xc3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc4
interrupt_handler_0xc4:
	pushq	$0xc4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc5
interrupt_handler_0xc5:
	pushq	$0xc5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc6
interrupt_handler_0xc6:
	pushq	$0xc6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc7
interrupt_handler_0xc7:
	pushq	$0xc7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc8
interrupt_handler_0xc8:
	pushq	$0xc8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xc9
interrupt_handler_0xc9:
	pushq	$0xc9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xca
interrupt_handler_0xca:
	pushq	$0xca
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xcb
interrupt_handler_0xcb:
	pushq	$0xcb
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xcc
interrupt_handler_0xcc:
	pushq	$0xcc
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xcd
interrupt_handler_0xcd:
	pushq	$0xcd
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xce
interrupt_handler_0xce:
	pushq	$0xce
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xcf
interrupt_handler_0xcf:
	pushq	$0xcf
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd0
interrupt_handler_0xd0:
	pushq	$0xd0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd1
interrupt_handler_0xd1:
	pushq	$0xd1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd2
interrupt_handler_0xd2:
	pushq	$0xd2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd3
interrupt_handler_0xd3:
	pushq	$0xd3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd4
interrupt_handler_0xd4:
	pushq	$0xd4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd5
interrupt_handler_0xd5:
	pushq	$0xd5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd6
interrupt_handler_0xd6:
	pushq	$0xd6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd7
interrupt_handler_0xd7:
	pushq	$0xd7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd8
interrupt_handler_0xd8:
	pushq	$0xd8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xd9
interrupt_handler_0xd9:
	pushq	$0xd9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xda
interrupt_handler_0xda:
	pushq	$0xda
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xdb
interrupt_handler_0xdb:
	pushq	$0xdb
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xdc
interrupt_handler_0xdc:
	pushq	$0xdc
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xdd
interrupt_handler_0xdd:
	pushq	$0xdd
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xde
interrupt_handler_0xde:
	pushq	$0xde
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xdf
interrupt_handler_0xdf:
	pushq	$0xdf
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe0
interrupt_handler_0xe0:
	pushq	$0xe0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe1
interrupt_handler_0xe1:
	pushq	$0xe1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe2
interrupt_handler_0xe2:
	pushq	$0xe2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe3
interrupt_handler_0xe3:
	pushq	$0xe3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe4
interrupt_handler_0xe4:
	pushq	$0xe4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe5
interrupt_handler_0xe5:
	pushq	$0xe5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe6
interrupt_handler_0xe6:
	pushq	$0xe6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe7
interrupt_handler_0xe7:
	pushq	$0xe7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe8
interrupt_handler_0xe8:
	pushq	$0xe8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xe9
interrupt_handler_0xe9:
	pushq	$0xe9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xea
interrupt_handler_0xea:
	pushq	$0xea
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xeb
interrupt_handler_0xeb:
	pushq	$0xeb
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xec
interrupt_handler_0xec:
	pushq	$0xec
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xed
interrupt_handler_0xed:
	pushq	$0xed
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xee
interrupt_handler_0xee:
	pushq	$0xee
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xef
interrupt_handler_0xef:
	pushq	$0xef
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf0
interrupt_handler_0xf0:
	pushq	$0xf0
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf1
interrupt_handler_0xf1:
	pushq	$0xf1
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf2
interrupt_handler_0xf2:
	pushq	$0xf2
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf3
interrupt_handler_0xf3:
	pushq	$0xf3
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf4
interrupt_handler_0xf4:
	pushq	$0xf4
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf5
interrupt_handler_0xf5:
	pushq	$0xf5
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf6
interrupt_handler_0xf6:
	pushq	$0xf6
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf7
interrupt_handler_0xf7:
	pushq	$0xf7
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf8
interrupt_handler_0xf8:
	pushq	$0xf8
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xf9
interrupt_handler_0xf9:
	pushq	$0xf9
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xfa
interrupt_handler_0xfa:
	pushq	$0xfa
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xfb
interrupt_handler_0xfb:
	pushq	$0xfb
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xfc
interrupt_handler_0xfc:
	pushq	$0xfc
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xfd
interrupt_handler_0xfd:
	pushq	$0xfd
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xfe
interrupt_handler_0xfe:
	pushq	$0xfe
	pushq	$40
	jmp	interrupt_handler_common

	.global	interrupt_handler_0xff
interrupt_handler_0xff:
	pushq	$0xff
	pushq	$40
	jmp	interrupt_handler_common
