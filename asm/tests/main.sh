#!/bin/bash

NB_ERROR=0

RED='\e[31m'
GREEN='\e[32m'
CYAN='\e[36m'
DEFAULT='\e[39m'

if [ ! -f ../asm ]; then
	echo "Make project"
	make -C ..
	echo ""; echo ""
fi

for FILENAME in $(find . -name "test_*.s")
do
	printf "Execute $FILENAME\n"

	printf $RED
		./../asm $FILENAME 2> error 1> /dev/null
		RESULT=$?
	printf $DEFAULT

	if [ $RESULT -eq 139 ]; then
		NB_ERROR=$((NB_ERROR+1))
	else
		if [[ $FILENAME =~ "_valid_" ]]; then
		    if [ $RESULT == 0 ]; then
		    	printf "${GREEN}SUCCESS ${DEFAULT}\n"
		    else
				printf "${RED}ERROR: Le programme CRASH\n"
				NB_ERROR=$((NB_ERROR+1))
		    fi
		else
		    if [ $RESULT == 0 ]; then
				printf "${RED}ERROR Le programme DEVRAIT crasher ${DEFAULT}\n"
				NB_ERROR=$((NB_ERROR+1))
		    else
		    	printf "${GREEN}SUCCESS ${DEFAULT}\n"
		    fi
		fi
	fi
	printf "${CYAN}$(cat error |grep "Segmentation") ${DEFAULT}\n"
done

echo ""

if [ $NB_ERROR -eq 0 ]; then
    printf "${GREEN}ALL TESTS PASSED ${DEFAULT}\n"
else
    printf "${RED}DANGER - $NB_ERROR ERRORS ${DEFAULT}\n"
fi