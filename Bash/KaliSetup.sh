#!/bin/bash

#Setup on Kali
apt-get update -y
apt-get upgrade -y
apt-get dist-upgrade -y
apt-get autoremove -y
apt-get clean -y
apt-get install gdb -y
apt-get install gdb-peda -y
apt-get install htop -y
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
echo "Script Executed"
