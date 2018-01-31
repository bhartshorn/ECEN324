#include <stdio.h>

void main() {
	//int i = (1 >> 0xFFFFFFE0);
	int i = (1 >> 0x80000000);
	printf("i: %x\n", i);
}
