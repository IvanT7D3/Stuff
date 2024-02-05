#!/bin/bash
#Kali Linux Basic Setup

Color_Off='\033[0m'
Red='\033[1;31m'
Green='\033[1;92m'

if [ $EUID -ne 0 ]; then
	echo -e "${Red}Execute as Root!${Color_Off}"
	exit 1
fi

apt-get update
apt-get upgrade -y
apt-get dist-upgrade -y
apt-get autoremove -y
apt-get clean -y
apt-get install libreoffice -y
apt-get install gdb -y
apt-get install htop -y
apt-get install strace -y
apt-get install ltrace -y
apt-get install vlc -y
apt-get install gwenview -y
apt-get install ark -y
apt-get install tor -y
apt-get install virtualbox -y
apt-get install gobuster -y
apt-get install wifiphisher -y
apt-get install steghide -y
apt-get install xxd -y
apt-get install hexedit -y
#apt-get install seclists -y
apt-get install exifcleaner -y
apt-get install openjdk-11-jdk-headless -y
apt-get install poppler-utils -y
apt-get install mosquitto mosquitto-clients -y
apt-get install sshuttle -y
apt-get install chisel -y
pip3 install updog
#rustscan
#https://github.com/longld/peda
echo -e "${Green}All done. Please restart!${Color_Off}"
