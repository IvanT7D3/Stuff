#!/bin/bash

if [ $EUID -ne 0 ]; then
	echo -e "Execute as Root!"
	exit 1
fi

fdisk -l
read -p "Give device to wipe. Example: sdb : " Device
read -p "Give device+partition to wipe. Example: sdb1 : " DevicePartition
umount /dev/$DevicePartition
dd if=/dev/urandom of=/dev/$Device bs=4096 status=progress
echo "[+] Device wiped!"
echo "[+] Creating new partition..."

#Adjust options to suit each need
fdisk /dev/$Device <<EEOF
n




p
t
b
a
w
EEOF

echo "[+] Created new partition!"
echo "[+] Formatting new partition..."
mkfs.ext4 /dev/$DevicePartition
echo "[+] All Done :)"
