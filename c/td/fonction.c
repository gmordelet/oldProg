//fonction.c

#include<stdio.h>
#include<math.h>

int main(){
  int i,j;
  for(i=-20;i<=20;i++){
    for(j=20;j>=-20;j--){
      if (i==0||j==0){
	printf("O");continue;
      }
      if (i==round(1/2)){
	printf("X");continue;
      }
      printf(" ");
    }
    printf("\n");  
  }
  return 0;
}
