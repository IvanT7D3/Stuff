#!/bin/bash

Color_Off='\033[0m'
Red='\033[1;31m'
Green='\033[1;92m'

if [ $EUID -ne 0 ]; then
	echo -e "${Red}Execute as Root!${Color_Off}"
	exit 1
fi

if ! id kali > /dev/null 2>&1 ; then
	echo -e "${Red}User 'kali' doesn't exist!${Color_Off}"
	exit 1
fi

cd /home/kali/Desktop

echo -e "${Green}Upgrading${Color_Off}"
apt-get update && apt-get upgrade -y && apt-get dist-upgrade -y && apt-get autoclean -y && apt-get autoremove -y && apt-get upgrade --fix-missing -y

echo -e "${Green}Installing main stuff${Color_Off}"
apt-get install python3 python3-pip python3-dev python3-pwntools git libssl-dev libffi-dev build-essential libreoffice htop gdb strace ltrace vlc gwenview rustup docker.io jd-gui ark tor wifiphisher gobuster feroxbuster steghide xxd lynx hexedit seclists openjdk-11-jdk.headless poppler-utils mosquitto mosquitto-clients sshuttle chisel ghidra golang bloodhound neo4j vbindiff jq linux-headers-generic gcc-mingw-w64 -y

echo -e "${Green}Installing bluetooth stuff${Color_Off}"
apt-get install bluelog blueranger btscanner redfang -y

echo -e "${Green}Installing canutils and modbus-cli${Color_Off}"
apt-get install can-utils -y
gem install modbus-cli

apt-get install virtualbox virtualbox-ext-pack virtualbox-dkms
usermod -a -G vboxusers kali

bash -c "$(curl -fsSL https://gef.blah.cat/sh)"

chown -R kali:kali *
updatedb

echo -e "${Green}All done. Please restart!${Color_Off}"
