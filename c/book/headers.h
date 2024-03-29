#ifndef HEADERS_H
# define HEADERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define PrintToBaseN(n, base) PrintToBase(n, base); printf("\n");
# define ArrSize(arr) (sizeof(arr) / sizeof(arr[0]))
# define Max(a, b) ((a) > (b)) ? a : b

void	PrintToBase(unsigned n, unsigned base);
int		binsearch(int x, int v[], int len);
size_t	GetLine(char *s, size_t max);

#endif
