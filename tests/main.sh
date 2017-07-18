#!/bin/bash

NB_ERROR=0
NB=0
RED='\e[31m'
GREEN='\e[32m'
CYAN='\e[36m'
DEFAULT='\e[39m'

if [ ! -f ../asm/asm ]; then
	echo "Make project"
	make -C ../asm/
	echo ""; echo ""
fi

for FILENAME in $(find . -name "test_*.s")
do
	NB_=1
	IFS='='
	for test in $(cat $FILENAME); do
		printf "Execute $FILENAME #$NB_ \t"
		NB=$(($NB+1))
		NB_=$(($NB_+1))

		echo $test > .hidden.s

		printf $RED
			if [[ $FILENAME =~ "_asm_" ]]; then
				../asm/asm .hidden.s 2> error 1> result
			else
				../vm/corewar .hidden.s 2> error 1> result
			fi
			RESULT=$?
		printf $DEFAULT

		if [ $RESULT -eq 139 ]; then
			NB_ERROR=$((NB_ERROR+1))
			printf "$CYAN"
			echo "$(cat result |grep "Segmentation")"
			printf "$DEFAULT"
		else
			if [[ $FILENAME =~ "_valid_" ]]; then
			    if [ $RESULT == 0 ]; then
			    	printf "${GREEN}SUCCESS ${DEFAULT}\n"
			    else
					printf "${RED}ERROR: Le programme CRASH${DEFAULT}\n"
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

		rm -f .hidden.s error result	
	done
done


if [ $NB_ERROR -eq 0 ]; then
    printf "\n${GREEN}ALL ($NB) TESTS PASSED ${DEFAULT}\n"
else
    printf "\n${RED}DANGER - $NB_ERROR ERRORS ${DEFAULT}\n"
fi