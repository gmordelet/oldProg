#include <stdio.h>
#include <stdlib.h>

#define INC 20000

int main()
{
	unsigned long n = 0;
	int i = 0;
	void *p;
	while ((p = malloc(INC)) != NULL)
			n += INC;
	while (p == NULL)
			p = malloc(INC - ++i);
	n += INC + i;
	printf ("n = %ld\n", n);
	while (1)
		;
	return 0;
}
