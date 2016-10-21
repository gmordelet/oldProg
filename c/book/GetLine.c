#include "headers.h"

size_t	GetLine(char *s, size_t max)
{
	size_t n;
	int c;

	n = 0;
	while ((c = getchar()) != EOF && n < max - 1)
		{
			++n;
			*(s++) = c;
			if (c == '\n')
				break;
		}
	*s = '\0';
	return (n);
}
