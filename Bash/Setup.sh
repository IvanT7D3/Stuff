#!/bin/bash

if [ $EUID -ne 0 ]; then
  echo -e "Execute as Root!"
  exit 1
fi
apt-get update
apt-get upgrade -y
apt-get dist-upgrade -y
apt-get autoremove -y
apt-get clean -y
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
apt-get install steghide -y
apt-get install xxd -y
apt-get install hexedit -y
apt-get install seclists -y
#rustscan
#https://github.com/longld/peda
echo "Done"
