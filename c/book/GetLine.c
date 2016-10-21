#include "headers.h"

size_t	GetLine(char *s, size_t max)
{
	size_t n;
	int c;

	n = 0;
	while (n < max - 1 && (c = getchar()) != EOF)
		{
			++n;
			*(s++) = c;
			if (c == '\n')
				break;
		}
	*s = '\0';
	return (n);
}
