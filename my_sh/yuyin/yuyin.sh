#! /bin/bash
#################################################################################
#     File Name           :     yuyin.sh
#     Created By          :     Aero
#     Creation Date       :     [2020-09-01 04:00]
#     Last Modified       :     [2020-09-01 04:45]
#     Description         :      
#################################################################################

#bin/bash
sleep 2s
mpg123 ~/Downloads/head.mp3 
sleep 2s
mpg123 ~/Downloads/ok.mp3 
sleep 3s
exec alacritty &
mpg123 ~/Downloads/alaclry.mp3
