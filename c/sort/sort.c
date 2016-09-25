#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TabSize(tab) (sizeof(tab) / sizeof(*tab))

void TabInitRand(int *, int);
void TabPrint(int *, int);
void InsertionSort(int *, int);
void TestSort(int *, int, void (*)(int *, int));

int main()
{
  int tab[1000];
  //  TabInitRand(tab, TabSize(tab));
  TestSort(tab, TabSize(tab), InsertionSort);

  return 0;
}

void TabInitRand(int *tab, int size)
{
  srand(time(NULL));
  while(size > 0)
    {
      tab[size--] = rand();
    }
}

void TabPrint(int *tab, int size)
{
  int i;

  for(i = 0; i < size; ++i)
    {
      printf("[%d] -> %d\n", i, tab[i]);
    }
}

void InsertionSort(int *tab, int size)
{
  int j, i;
  for(j = 1; j < size; ++j)
    {
      i = j - 1;
      while(i >= 0 && tab[i] > tab[j])
	{
	  tab[i + 1] = tab[i];
	  --i;
	}
      tab[i + 1] = tab[j];
    }
}

void MergeSort(int *tab, int size)
{
  
}

void _MergeSort(int *tab, int left, int right)
{
  if(left == right)
    return;
  _MergeSort(tab, left, (left + right) / 2);
  _MergeSort(tab, (left + right) / 2 + 1, right);
  Merge(tab, left, right);
}

void Merge(int *tab, int left, int right)
{
  int tab1[(left + right) / 2], tab2[right - ((left + right) / 2)], i;
  


}

void TestSort(int *tab, int size, void (*func)(int *, int))
{
  long i = 0;
  int timeBegin, timeEnd;
  timeBegin = time(NULL);

  while(i++ < 1000000)
    {
      TabInitRand(tab, size);
      (*func)(tab, size);
    }

  timeEnd = time(NULL);

  printf("i = %ld, size = %d, time = %d\n", i - 1, size, timeEnd - timeBegin);

}


