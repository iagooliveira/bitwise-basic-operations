#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t* reg) {

	unsigned XOR;
	unsigned bit0 = *reg & 1;
	unsigned bit2 = (*reg >> 2) & 0x1;
	unsigned bit3 = (*reg >> 3) & 0x1;
	unsigned bit5 = (*reg >> 5) & 0x1;

	XOR = bit0 ^ bit2;
	XOR = XOR ^ bit3;
	XOR = XOR ^ bit5;

	*reg = (*reg >> 1);
	*reg = *reg | (XOR << 15);
}