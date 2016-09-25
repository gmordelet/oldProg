#include<stdio.h>

void shell(int tab[], int n);
void aff_tab(int tab[], int n);

int main()
{
  int tab[11] = {7,12,10,4,2,14,13,1,9,6,15};
  aff_tab(tab,10);
  shell(tab,12);
  aff_tab(tab,12);
  return 0;
}

void shell(int tab[], int n)
{
  int gap, temp, i, j;
  
  for(gap = n/2; gap > 0; gap /= 2)
    {
      for(i = gap; i < n; ++i)
	for(j = i-gap; j >= 0 && tab[j] > tab[j+gap]; j -= gap)
	  {
	    temp = tab[j];
	    tab[j] = tab[j+gap];
	    tab[j+gap] = temp;
	    printf("i = %d j = %d gap = %d\n",i,j,gap);
	  }
    }
}

/*void shell(int tab[], int n)
{
  int gap, temp, i, j;
  
  for(gap = n/2; gap > 0; gap /= 2)
    {
      for(i = gap; i < n; ++i)
	for(j = i-gap; j >= 0 && tab[j] > tab[j+gap]; j -= gap)
	  {
	    temp = tab[j];
	    tab[j] = tab[j+gap];
	    tab[j+gap] = temp;
	    printf("i = %d j = %d gap = %d\n",i,j,gap);
	  }
    }
    }*/

void aff_tab(int tab[], int n)
{
  int i;
  for(i = 0; i < n; ++i)
    printf("tab[%d]=%d, ",i,tab[i]);
  printf("\n");
}

int next_gap()
{
  static gap = 5;
  

}
