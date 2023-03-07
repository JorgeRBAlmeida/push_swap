#!/bin/bash

NO_COLOR='\033[0m'
RED='\033[1;31m'
BLUE='\033[1;34m'
GREEN='\033[1;32m'
YLLW='\033[1;33m'
NBR=$((1))
DETECTED_OS=$(uname)
i=1

check_linux()
{
	RESULT=$(./../push_swap $ARGS | ./checker_linux $ARGS)
	valgrind --log-file=temp.txt ./../push_swap $ARGS > /dev/null 
	LEAKS=$(grep "LEAK" temp.txt | awk '{ print $2 }')
	LEAKS=""
	OPERATIONS=$(./../push_swap $ARGS | wc -l | tr -d ' ')
	if [[ $RESULT == "KO" ]]; then
		echo -e "$i-${RED}KO with { $ARGS}$NO_COLOR"
	elif [ -z "$LEAKS" ]; then
		echo -e "$i-${BLUE}OK with $OPERATIONS operations$NO_COLOR"
	else
		echo -e "$i-${RED}MKO with { $ARGS}$NO_COLOR"
	fi
}

check_mac()
{
	RESULT=$(./../push_swap $ARGS | ./checker_Mac $ARGS)
	valgrind --log-file=temp.txt ./../push_swap $ARGS > /dev/null
	LEAKS=$(grep "bytes" temp.txt | tail -n 5 | head -n 4 | awk '{ print $4 }' | tr '\n' ' ')
	OPERATIONS=$(./../push_swap $ARGS | wc -l | tr -d ' ')
	if [[ $RESULT == "KO" ]]; then
		echo -e "$i-${RED}KO with { $ARGS}$NO_COLOR"
	elif [ "$LEAKS" != "0 0 0 0 " ]; then
		echo -e "$i-${RED}MKO with { $ARGS}$NO_COLOR"
	else
		echo -e "$i-${BLUE}OK with $OPERATIONS operations$NO_COLOR"
	fi
}

echo -e "$GREEN$1:$NO_COLOR\n"

while [ $i -lt 21 ]
do
	if [ $DETECTED_OS == "Linux" ]; then
		ARGS=$(seq -999999 999999 | shuf -n $1 | tr '\n' ' ')
	else
		ARGS=$(seq -999999 999999 | gshuf -n $1 | tr '\n' ' ')
	fi
	timeout 5s ./../push_swap $ARGS > /dev/null
	if [ $? -eq 124 ]; then
		echo -e "$i-${YLLW}TIMEOUT with { $ARGS}${NO_COLOR}"
	elif [ $DETECTED_OS == "Linux" ]; then
		check_linux
	else
		check_mac
	fi
	i=`expr $i + 1`
done

echo -e "\n"


