//visual.c
//affichage du plateau

#include"headers.h"

char print_char(char c)
{
  switch(c)
    {
    case'X' : return 'X';
      break;
    case'0' : return 'O';
	break;
    case 0 : return ' ';
      break;
    }
}

void print_board(char array[])
{
  printf("\n");
  printf("_________\n");
  printf("%c | %c | %c\n",print_char(array[0]), print_char(array[1]), print_char(array[2]));
  printf("%c | %c | %c\n",print_char(array[3]), print_char(array[4]), print_char(array[5]));
  printf("%c | %c | %c\n",print_char(array[6]), print_char(array[7]), print_char(array[8]));  
  printf("_________\n");
  printf("\n");

}
