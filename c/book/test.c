#include "headers.h"

#define BUFFSIZE 2

int main()
{
	char	s[BUFFSIZE];
	int n;

	while (n = GetLine(s, BUFFSIZE))
		printf("%s", s);
	printf("%d\n", n);
	return (0);
}
