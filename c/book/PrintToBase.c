#include <stdio.h>

void PrintToBase(unsigned int n, unsigned int base)
{
	char digits[] = "0123456789ABCDEF";

	if (n < base)
		printf("%c", digits[n]);
	else
		{
			PrintToBase(n / base, base);
			printf("%c", digits[n % base]);
		}
}
