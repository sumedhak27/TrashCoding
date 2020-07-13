#!/bin/bash
set -x
usb_modeswitch -W -n -I -v 05c6 -p f000 -V 05c6 -P 0016 -M 55534243e0793c88000000000000061b000000020000000000000000000000 > /dev/null 2>&1
modprobe usb_wwan
modprobe option
echo 05C6 0016 > /sys/bus/usb-serial/drivers/option1/new_id
