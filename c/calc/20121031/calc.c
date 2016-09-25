#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXLENGTH 100

typedef struct node node;
struct node
{
  float num;
  node *p_next;
};

void add_node(float num);
node *access_node(int);
void rm_node(int n);
void display(void);
void getstring(char *);
float calc(char *s);

int main()
{
  char s[MAXLENGTH];
  printf("String : ");
  getstring(s);
  printf("Result = %f\n",calc(s));
  return 0;
}

node *p_init = NULL;

void add_node(float num)
{
  node *p_new, *p_temp;
  p_new = malloc(sizeof(node));

  if(p_new == NULL)
    {
      printf("Erreur : add_node : malloc\n");
      exit(EXIT_FAILURE);
    }
  if(p_init == NULL)
    {
      p_init = p_new;
      p_new->p_next = NULL;
      p_new->num = num;
    }
  else
    {
      p_temp = p_init;
      while(p_temp->p_next != NULL)
	p_temp = p_temp->p_next;
      p_temp->p_next = p_new;
      p_new->p_next = NULL;
      p_new->num = num;
    }
}

node *access_node(int n)
{
  node *p_node = p_init;
  if(p_node == NULL)
    {
      printf("Erreur : acces_node\n");
      exit(EXIT_FAILURE);
    }
  while(n--)
    {
      p_node = p_node->p_next;
      if(p_node == NULL)
	{
	  printf("Erreur : acces_node\n");
	  exit(EXIT_FAILURE);
	}
    }
  return p_node;
}

void rm_node(int n)
{
  node *p_rm, *p_previous, *p_next;
  p_rm = access_node(n);
  if(!n)
    {
      p_init = p_init->p_next;
      free(p_rm);
    }
  else if(p_rm->p_next == NULL)
    {
      p_previous = access_node(n-1);
      p_previous->p_next = NULL;
      free(p_rm);
    }
  else
    {
      p_previous = access_node(n-1);
      p_next = access_node(n+1);
      p_previous->p_next = p_next;
      free(p_rm);
    }
}

void display()
{
  node *p_temp = p_init;
  int i = 0;
  printf("\n");
  while(p_temp != NULL)
    {
      printf("node %d : %f\n", i++, p_temp->num);
      p_temp = p_temp->p_next;
    }
    printf("\n");
}

void getstring(char *s)
{
  char c;
  while((c = getchar()) != '\n')
    {
      if(c == ' ')
	continue;
      *s++ = c;
    }
  s = '\0';
}

float calc(char *s)
{
  char buff[MAXLENGTH], *p_buff;
  float result, temp, exp;
  node *p_node, *p_node_previous, *p_node_next;
  int i = 1;
  p_buff = buff;
  while(*s)
    {
      while(isxdigit(*s) || *s == '.')
	*(p_buff++) = *(s++);
      *p_buff = '\0';
      p_buff = buff;
      temp = (float)atof(buff);
      if(*s == '^') //exposant
	{
	  ++s;
	  while(isxdigit(*s) || *s == '.')
	    *(p_buff++) = *(s++);
	  *p_buff = '\0';
	  p_buff = buff;
	  exp = (float)atof(buff);
	  temp = powf(temp, exp);
	}
      add_node(temp);
      if(*s)
	add_node((float)*s++);
    }
  while(p_init->p_next != NULL)
    {
      p_node = access_node(i);
      if(p_node->num == '*')
	{
	  p_node_previous = access_node(i-1);
	  p_node_next = access_node(i+1);
	  p_node_previous->num = p_node_previous->num * p_node_next->num;
	  rm_node(i);
	  rm_node(i);//node'i + 1' devient node'i'
	  p_node = access_node(i-1);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}
      if(p_node->num == '/')
	{
	  p_node_previous = access_node(i-1);
	  p_node_next = access_node(i+1);
	  p_node_previous->num = p_node_previous->num / p_node_next->num;
	  rm_node(i);
	  rm_node(i);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}
      if(p_node->p_next->p_next == NULL)
	break;
      i += 2;
    }
  i = 1;
  while(p_init->p_next != NULL)
    {
      p_node = access_node(i);
      if(p_node->num == '+')
	{
	  p_node_previous = access_node(i-1);
	  p_node_next = access_node(i+1);
	  p_node_previous->num = p_node_previous->num + p_node_next->num;
	  rm_node(i);
	  rm_node(i);
	  p_node = access_node(i-1);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}
      if(p_node->num == '-')
	{
	  p_node_previous = access_node(i-1);
	  p_node_next = access_node(i+1);
	  p_node_previous->num = p_node_previous->num - p_node_next->num;
	  rm_node(i);
	  rm_node(i);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}
      if(p_node->p_next->p_next == NULL)
	break;
      i += 2;
    }
  return p_init->num;
}
