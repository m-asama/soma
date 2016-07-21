#
# Author:
#	Masakazu Asama <m-asama@ginzado.co.jp>
#

.include "../soma.mk"

CFLAGS	      = -Wall -O2 -pipe -fPIC -I. -I./include -I./include/${SOMA_TARGET} -I ../kernel -ffreestanding \
                -mno-red-zone -mno-mmx -mno-sse -mno-aes -mno-avx -msoft-float \
                -std=gnu99 -Qunused-arguments --target=${SOMA_TARGET}-unknown-freebsd10

CFLAGS_loader = -Wl,-T./ldscript.${SOMA_TARGET} -Wl,-Bsymbolic -shared \
                -Wl,-znocombreloc -nostdlib

OBJCOPYFLAGS  = -j .text \
		-j .sdata \
		-j .data  \
		-j .dynamic \
		-j .dynsym \
                -j .rel.dyn \
		-j .rela.dyn \
		-j .reloc \
		-j .eh_frame \
                -j set_Xcommand_set \
		--output-target=${OBJCOPY_TARGET}

OBJS	      = start_${SOMA_TARGET}.o \
		self_reloc.o \
		print.o \
		loader.o \
		main.o

all: loader.efi

loader.efi: loader
	${SOMA_TARGET}-freebsd-objcopy $(OBJCOPYFLAGS) loader loader.efi

loader: $(OBJS)
	#clang38 $(CFLAGS) $(CFLAGS_loader) -v -o loader $(OBJS)
	${SOMA_TARGET}-freebsd-ld --eh-frame-hdr -Bshareable --enable-new-dtags -o loader -L/usr/lib -T./ldscript.${SOMA_TARGET} -Bsymbolic -znocombreloc $(OBJS)

.S.o:
	clang38 $(CFLAGS) -c $<

.c.o:
	clang38 $(CFLAGS) -c $<

clean:
	rm -f *.o loader.efi loader

