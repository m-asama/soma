#
# Author:
# 	Masakazu Asama <m-asama@ginzado.co.jp>
#

.include "../soma.mk"

CFLAGS	      = -Wall -O2 -pipe -fPIC -I. -I./include -ffreestanding \
                -mno-red-zone -mno-mmx -mno-sse -mno-aes -mno-avx -msoft-float \
                -std=c11 -Qunused-arguments

CXXFLAGS      = -Wall -O2 -pipe -fPIC -I. -I./include -ffreestanding \
                -mno-red-zone -mno-mmx -mno-sse -mno-aes -mno-avx -msoft-float \
                -std=c++11 -Qunused-arguments \
		-nostdinc -nostdlibinc -nobuiltininc \
		-fno-exceptions -fno-rtti -fno-use-cxa-atexit

OBJCOPYFLAGS  = -S \
		-O binary

OBJS	      = main.o \
		processor_base.o \
		processor_state_base.o \
		irqchip_base.o \
		acpi_management.o \
		acpi.o \
		memory_management.o \
		memory_block.o \
		thread_management.o \
		thread.o \
		console_management.o \
		console_base.o \
		font.o \
		font_data.o \
		unicode.o \
		print.o \
		string.o \
		spinlock.o \
		util.o

.if "${SOMA_TARGET}" == "x86_64"
OBJS	     += intel64_subsequent_processor.o \
		intel64_processor_management.o \
		intel64_processor.o \
		intel64_processor_state.o \
		intel64_processor_interrupt_handler.o \
		intel64_assembly.o \
		intel64_irqchip_management.o \
		intel64_ioapic.o \
		intel64_pci_management.o \
		intel64_display_console.o \
		intel64_serial_console.o \
		intel64_util.o
.endif

.if "${SOMA_TARGET}" == "aarch64"
OBJS	     += aarch64_subsequent_processor.o \
		aarch64_util.o
.endif

all: kernel.bin

kernel.bin: kernel
	${SOMA_TARGET}-freebsd-objcopy $(OBJCOPYFLAGS) kernel kernel.bin
	perl expand_kernel.pl

kernel: $(OBJS)
	${SOMA_TARGET}-freebsd-ld -nodefaultlibs -N -e main -Ttext 0x100000 -o kernel $(OBJS)

.S.o:
	cc -c -x assembler-with-cpp -DLOCORE -O2 -pipe -fno-strict-aliasing  -std=c99 -g -Wall -Wredundant-decls -Wnested-externs -Wstrict-prototypes  -Wmissing-prototypes -Wpointer-arith -Winline -Wcast-qual  -Wundef -Wno-pointer-sign -fformat-extensions  -Wmissing-include-dirs -fdiagnostics-show-option  -Wno-error-tautological-compare -Wno-error-empty-body  -Wno-error-parentheses-equality -Wno-error-unused-function -nostdinc -I/usr/include -D_KERNEL -DHAVE_KERNEL_OPTION_HEADERS -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -mno-aes -mno-avx -mcmodel=kernel -mno-red-zone -mno-mmx -mno-sse -msoft-float  -fno-asynchronous-unwind-tables -ffreestanding -fstack-protector -gdwarf-2 -no-integrated-as -Werror $<
#	clang -x assembler-with-cpp -no-integrated-as -c $<

.c.o:
	clang38 $(CFLAGS) -c $<

.cpp.o:
	clang++38 $(CXXFLAGS) -c $<

clean:
	rm -f *.o kernel.bin kernel

doxygen:
	doxygen doxygen.conf

