#include "headers.h"

/* int	BinSearch(int x, int v[], int len) */
/* { */
/* 	int low, mid, high; */
	
/* 	low = 0; */
/* 	high = len - 1; */

/* 	while (low <= high) */
/* 		{ */
/* 			mid = (low + high) / 2; */
/* 			if (v[mid] == x) */
/* 				return (1); */
/* 			else if (v[mid] < x) */
/* 				low = mid + 1; */
/* 			else */
/* 				high = mid - 1; */
/* 		} */
/* 	return (0); */
/* } */

int	BinSearch(int x, int v[], int len)
{
	int low, mid, high;
	
	low = 0;
	high = len - 1;

	mid = high / 2;
	while (low <= high && v[mid] != x)
		{
			if (v[mid] < x)
				low = mid + 1;
			else
				high = mid - 1;
			mid = (low + high) / 2;
		}
	if (v[mid] == x)
		return (1);
	return (0);
}
