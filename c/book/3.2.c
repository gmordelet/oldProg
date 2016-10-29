#include "headers.h"

#define BUFFSIZE 1024

void	escape(char *s, char *t)
{
	int	i, j;

	for (i = 0, j = 0; (t[j] = s[i]) != '\0'; ++i)
		{
			switch(s[i])
				{
				case '\t':
					t[j++] = '\\';
					t[j++] = 't';
					break;
				case '\n':
					t[j++] = '\\';
					t[j++] = 'n';
					break;
				default:
					++j;
				}
		}
}

int		main()
{
	char s[BUFFSIZE], t[BUFFSIZE];

	while (GetLine(s, BUFFSIZE))
		{
			escape(s, t);
			printf("%s", t);
		}
	
	return (0);
}
