#include <stdio.h>

int	match(char *s1, char *s2)
{
	int count = 0;
	
	if (*s2 == '*')
		{
			if (*s1 == 0)
				{
					if (*(s2 + 1) != 0)
						return (0);
					else
						{
							printf("+1\n");
						return (1);
						}
				}
			count += match(s1 + 1, s2 + 1) + match(s1 + 1, s2) + match(s1, s2 + 1);
		}
	else
		{
			if (*s1 != *s2)
				return (0);
			if (*s1 == 0)
				{
					printf("+1\n");
				return (1);
				}
			count += match(s1 + 1, s2 + 1);
		}
	return (count);
}

int	main(int argc, char *argv[])
{
	if(argc != 3)
		return (0);
	printf("%d\n", match(argv[1], argv[2]));
	return (0);
}
