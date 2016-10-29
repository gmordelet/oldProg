#include "headers.h"

unsigned	invert(unsigned x, unsigned p, unsigned n)
{
	unsigned	xMask = ~(~0 << n) << p - n + 1;
	return (x ^ xMask);
}

int			main()
{
	unsigned	x	=  49281;
	unsigned	p	= 7;
	unsigned	n	= 5;
	PrintToBaseN(x, 2);
	PrintToBaseN(invert(x, p, n), 2);
	return (0);
}
