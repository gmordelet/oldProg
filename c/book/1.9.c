#include <stdio.h>

int main()
{
	int c;
	
	c = getchar();
	while (c != EOF)
		{
			if (c == ' ')
				{
					putchar(c);
					c = getchar();
					while (c == ' ' && c != EOF)
							c = getchar();
				}
			else
				{
					putchar(c);
					c = getchar();
				}
		}
	return (0);
}
