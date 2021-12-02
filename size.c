#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("int:\t%ld\nui:\t%ld\nshort:\t%ld\nus:\t%ld\nbool:\t%ld\n",
			sizeof(int), sizeof(unsigned int), sizeof(short),
			sizeof(unsigned short), sizeof(bool));
	return (0);
}
