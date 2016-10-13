#include <stdio.h>
#include <stdlib.h>

void squeeze(char s[], char c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	squeeze(argv[1], *(argv[2]));
	printf("%s\n", argv[1]);
	exit(EXIT_SUCCESS);
}
