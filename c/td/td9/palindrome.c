//palindrome.c

#include<stdio.h>
#include<string.h>

int main(){
  printf("\n");
  int i,j,v=0,x=0;
  char tab[20];
  printf("chaine a tester ? ");scanf("%[^\n]",tab);
  for(i=0;i<strlen(tab);i++){
    if(tab[i]=='a'||tab[i]=='e'||tab[i]=='i'||tab[i]=='o'||tab[i]=='u'||tab[i]=='y')++v;
  }
  printf("%d voyelles dans la chaine\n",v);
  for(i=0,j=strlen(tab)-1;i<strlen(tab);i++,j--){
    if(tab[i]!=tab[j])x=1;
  }
  if(x) printf("Pas un palindrome\n");
  else printf("palindrome\n");
  printf("\n");
  return(0);
}
