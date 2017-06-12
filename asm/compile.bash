#!/bin/bash

for var in "$@"
do
	echo "TRY WITH $var"
	./asm "test/$var.s"
	hexdump -C "test/$var.cor" > "asmres/$var"
	diff "asmres/$var" "asm_res/$var"
done

