#include "headers.h"

int main()
{
	int arr1[1000], arr2[1001], i;

	for (i = 0; i < 1000; ++i)
		arr1[i] = i;
	for (i = 0; i < 1001; ++i)
		arr2[i] = i;
	for (i = 0; i < 1000; ++i)
		if (!BinSearch(i, arr1, ArrSize(arr1)))
			printf("FAIL\n");
	for (i = 0; i < 1001; ++i)
		if (!BinSearch(i, arr2, ArrSize(arr2)))
			printf("FAIL\n");
	if (BinSearch(-1, arr1, ArrSize(arr1)))
		printf("FAIL\n");
	if (BinSearch(1001, arr1, ArrSize(arr1)))
		printf("FAIL\n");
	if (BinSearch(-1, arr2, ArrSize(arr2)))
		printf("FAIL\n");
	if (BinSearch(1002, arr2, ArrSize(arr2)))
		printf("FAIL\n");
	

	return (0);
}
