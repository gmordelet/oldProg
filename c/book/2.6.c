#include <stdio.h>

void		PrintToBase(unsigned, unsigned);

unsigned	setbits(unsigned x, int p, int n, unsigned y)
{
	/* unsigned	x_mask	= (~0 << p + 1) | ~(~0 << p - n + 1); */
	/* x &= x_mask; */
	/* y <<= p - n + 1; */
	/* y &= ~(~0 << p + 1); */
	/* return (x | y); */
	unsigned	x_mask	= ~(~(~0 << n) << (p - n + 1));
	x &= x_mask;
	y &= ~(~0 << n);
	y <<= p - n + 1;
	return (x | y);
}

int main()
{
	int	x	= 0;
	int	y	= 0xFFF;
	printf("x = ");
	PrintToBase(x, 2);
	printf("\n");
	printf("y = ");
	PrintToBase(y, 2);
	printf("\n");
	x = setbits(x, 4, 3, y);
	printf("setbits = ");
	PrintToBase(x, 2);
	printf("\n");
	return (0);
}
	
