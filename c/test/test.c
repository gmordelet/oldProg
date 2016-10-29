#include <stdio.h>
#include <unistd.h>

int	main()
{
	char buff[6];
	write(1, "salut\n", 7);
	lseek(1, 0, SEEK_SET);
	read(1, buff, 6);
	printf("%s\n", buff);
	
	return (0);
}
