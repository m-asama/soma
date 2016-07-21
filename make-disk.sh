#!/bin/sh

DEV=`sudo mdconfig -a -f disk.img`
sudo mount -t msdosfs /dev/${DEV}p1 hda
sudo mount -t msdosfs /dev/${DEV}p2 hdb
cp loader/loader.efi ./hda/efi/boot/BOOTx64.efi
#cp loader/loader.efi ./hda/efi/boot/BOOTaa64.efi
cp kernel/kernel.bin ./hdb/somakern.bin
sudo umount hda
sudo umount hdb
sudo mdconfig -d -u $DEV

