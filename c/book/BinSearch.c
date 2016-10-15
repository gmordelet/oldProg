#include "headers.h"

int	BinSearch(int x, int v[], int len)
{
	int low, mid, high;
	
	low = 0;
	high = len - 1;
	mid = high / 2;
	while (low <= high)
		{
			if (v[mid] == x)
				return (1);
			else if (v[mid] < x)
				{
					low = mid + 1;
					mid = (low + high) / 2;
				}
			else
				{
					high = mid - 1;
					mid = (low + high) / 2;
				}
		}
	return (0);
}
