#ifndef HEADERS_H
# define HEADERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define PrintToBaseN(n, base) PrintToBase(n, base); printf("\n");

void	PrintToBase(unsigned n, unsigned base);

#endif
