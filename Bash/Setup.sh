#!/bin/bash

Color_Off='\033[0m'
Red='\033[1;31m'
Green='\033[1;92m'

if [ $EUID -ne 0 ]; then
	echo -e "${Red}Execute as Root!${Color_Off}"
	exit 1
fi

apt-get update -y
apt-get upgrade -y
apt-get dist-upgrade -y
apt-get autoremove -y
apt-get install htop gdb strace ltrace vlc gwenview ark tor virtualbox wifiphisher gobuster feroxbuster steghide xxd hexedit seclists openjdk-11-jdk.headless poppler-utils mosquitto mosquitto-clients sshuttle chisel ghidra golang bloodhound neo4j
pip3 install updog
pip3 install bpytop
echo -e "${Green}All done. Please restart!${Color_Off}"
