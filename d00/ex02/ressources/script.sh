#!/bin/bash

#this script shall be placed in the root repo


# $BOT_DIR="."

# BLUE        =   \033[0;94m
# YELLOW      =   \033[0;33m
# LIGHT       =   \033[0;5m
# COLOR_OFF   =   \033[0m
# GREEN       =   \033[0;32m
# PURPLE      =   \033[0;35m
# CYAN        =   \033[0;36m

# RED         =   \033[0;31m 

make re && ./account > "logfile.log"



echo "\033[1;36m"


diff logfile.log 19920104_091532.log >> difference.txt

if [ -s difference.txt ]
then
	echo  "Logfiles differ: " 
else
	# echo difference.txt
	echo "Logfiles don't differ"

fi

cat difference.txt
rm -rf difference.txt
make fclean
