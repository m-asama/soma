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

tests/main:
	make -C tests

clean:
	make -C loader clean
	make -C kernel clean
	make -C tests clean

run: loader/loader.efi kernel/kernel.bin
	cp loader/loader.efi ./hda/efi/boot/BOOTx64.efi
	cp kernel/kernel.bin ./hdb/somakern.bin
	touch ./hdb/somaconf.txt
	#qemu-system-x86_64 -smp 2 -m 1024 -k ja -vnc 0.0.0.0:0 -serial stdio -bios OVMF.fd -hda fat:./hda -hdb fat:./hdb
	#qemu-system-x86_64 -smp 2 -m 1024 -bios OVMF.fd \
	#	-hda fat:./hda -hdb fat:./hdb \
	#	-vnc 0.0.0.0:0,password -k ja \
	#	-chardev stdio,mux=on,id=char0 \
	#	-mon chardev=char0,mode=readline,default \
	#	-serial telnet:0.0.0.0:2300,server,nowait
	qemu-system-x86_64 -smp 2 -m 1024 -bios OVMF.fd \
		-hda fat:./hda -hdb fat:./hdb \
		-chardev socket,id=char0,server,host=0.0.0.0,port=2300,nowait,telnet \
		-mon chardev=char0,mode=readline,default \
		-vnc 0.0.0.0:0,password -k ja \
		-serial stdio

test: tests/main
	make -C tests test

