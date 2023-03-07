#!/bin/bash

NO_COLOR='\033[0m'
RED='\033[1;31m'
BLUE='\033[1;34m'
GREEN='\033[1;32m'
YLLW='\033[1;33m'
DETECTED_OS=$(uname)
NBR=1

ARGS=(	"2147483648"
		"2147483650"
		"-2147483658"
		"-2147483649"
		"8589934590"
		"9999999999"
   		"312421421342314 31 32"
	   	"31 32 312421421342314"
	   	"31 312421421342314 32"
	   	"321 54 320 321"
		"25 42a"
	   	"321 54a23 320 321"
	   	"342 4908 as 312"
	   	"sada 42 19 21"
	   	"42 19 21 sada")

clear
check_linux()
{
	RESULT=$(.././push_swap $i &> /dev/null | ./chcker_linux $i &> /dev/null)
	LEAKS=$(grep "LEAK" temp.txt | awk '{print $2}')
	if [[ $RESULT == "KO" ]]; then
		echo -e "$NBR-${RED}KO with argument {$i}${NO_COLOR} \c"
	elif [ -z "$LEAKS" ]; then
		echo -e "$NBR-${BLUE}OK${NO_COLOR} \c"
	else
		echo -e "$NBR-${RED}MKO with argument {$i}${NO_COLOR} \c"
	fi
}
check_mac()
{
	RESULT=$(.././push_swap $i &> /dev/null | ./checker_mac $i &> /dev/null)
	LEAKS=$(grep "bytes" temp.txt | tail -n 5 | head -n 4 | awk '{ print $4 }' | tr '\n' ' ')
	if [[ $RESULT == "KO" ]]; then
		echo -e "$NBR-${RED}KO with argument {$i}${NO_COLOR} \c"
	elif [ "$LEAKS" != "0 0 0 0 " ]; then
		echo -e "$NBR-${RED}MKO with argument {$i}${NO_COLOR} \c"
	else
		echo -e "$NBR-${BLUE}OK${NO_COLOR} \c"
	fi
}
echo -e "${GREEN}Argument validation ${NO_COLOR}\n"
for i in "${ARGS[@]}"
do
	timeout 2s ./../push_swap $ARGS &> /dev/null
	if [ $? -eq 124 ]; then
		echo -e "$NBR-${YLLW}TIMEOUT with {$i}${NO_COLOR}"
	elif [ $DETECTED_OS == "Linux" ]; then
		valgrind --log-file=temp.txt ./../push_swap $i &> /dev/null
		check_linux
	else
		valgrind --log-file=temp.txt ./../push_swap $i &> /dev/null
		check_mac
	fi
	NBR=`expr $NBR + 1` 
done

echo -e "\n"
