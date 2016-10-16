#include "headers.h"

#define SIZE 800000

int main()
{
	int arr1[SIZE], arr2[SIZE + 1], i;

	for (i = 0; i < SIZE; ++i)
		arr1[i] = i;
	for (i = 0; i <= SIZE; ++i)
		arr2[i] = i;
	for (i = 0; i < SIZE; ++i)
		if (!BinSearch(i, arr1, ArrSize(arr1)))
			printf("FAIL\n");
	for (i = 0; i <= SIZE; ++i)
		if (!BinSearch(i, arr2, ArrSize(arr2)))
			printf("FAIL\n");
	if (BinSearch(-1, arr1, ArrSize(arr1)))
		printf("FAIL\n");
	if (BinSearch(SIZE, arr1, ArrSize(arr1)))
		printf("FAIL\n");
	if (BinSearch(-1, arr2, ArrSize(arr2)))
		printf("FAIL\n");
	if (BinSearch(SIZE + 1, arr2, ArrSize(arr2)))
		printf("FAIL\n");
	return (0);
}
