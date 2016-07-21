#
# Author:
#       Masakazu Asama <m-asama@ginzado.co.jp>
#

.include "soma.mk"

all: loader/loader.efi kernel/kernel.bin

loader/loader.efi:
	make -C loader loader.efi

kernel/kernel.bin:
	make -C kernel kernel.bin

clean:
	make -C loader clean
	make -C kernel clean

run: loader/loader.efi kernel/kernel.bin
	cp loader/loader.efi ./hda/efi/boot/BOOTx64.efi
	cp kernel/kernel.bin ./hdb/somakern.bin
	touch ./hdb/somaconf.txt
	qemu-system-x86_64 -smp 2 -m 1024 -serial stdio -bios OVMF.fd -hda fat:./hda -hdb fat:./hdb

