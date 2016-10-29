#include <stdio.h>

int	match(char *s1, char *s2)
{
	if (*s2 == '*')
		{
			if (*s1 == 0)
				{
					if (*(s2 + 1) != 0)
						return (0);
					else
						return (1);
				}
			return (match(s1 + 1, s2 + 1) || match(s1 + 1, s2) || match(s1, s2 + 1));
		}
	if (*s1 != *s2)
		return (0);
	if (*s1 == 0)
		return (1);
	return match(s1 + 1, s2 + 1);
}

int	main(int argc, char *argv[])
{
	if(argc != 3)
		return (0);
	printf("%d\n", match(argv[1], argv[2]));
	return (0);
}
