all: pop_spec

pop_spec: popcnt.h popcnt_spec.c
	gcc -std=c11 popcnt_spec.c -o popcnt_spec
