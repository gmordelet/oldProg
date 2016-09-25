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

void add_node(node **, float );
node *access_node(node *, int);
void rm_node(node *, int );
void display(node *);
void rm_node_all(node **);
void getstring(char *);
float calc(char *);

int main()
{
  char s[MAXLENGTH];
  printf("String : ");
  getstring(s);
  printf("Result = %f\n",calc(s));
  return 0;
}

void add_node(node **p_init, float num)
{
  node *p_new, *p_temp;
  p_new = malloc(sizeof(node));

  if(p_new == NULL)
    {
      printf("Erreur : add_node : malloc\n");
      exit(EXIT_FAILURE);
    }

  if(*p_init == NULL)
    {
      *p_init = p_new;
      p_new->p_next = NULL;
      p_new->num = num;
    }
  else
    {
      p_temp = *p_init;
      while(p_temp->p_next != NULL)
	p_temp = p_temp->p_next;
      p_temp->p_next = p_new;
      p_new->p_next = NULL;
      p_new->num = num;
    }
}

node *access_node(node *p_init, int n)
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

void rm_node(node *p_init, int n)
{
  node *p_rm, *p_previous, *p_next;

  p_rm = access_node(p_init, n);

  if(!n)
    {
      p_init = p_init->p_next;
      free(p_rm);
    }
  else if(p_rm->p_next == NULL)
    {
      p_previous = access_node(p_init, n-1);
      p_previous->p_next = NULL;
      free(p_rm);
    }
  else
    {
      p_previous = access_node(p_init, n-1);
      p_next = access_node(p_init, n+1);
      p_previous->p_next = p_next;
      free(p_rm);
    }
}

void rm_full_node(node *p_init)
{
  node *p_temp1, *p_temp2;
  p_temp1 = p_init;
  
  do
    {
      p_temp2 = p_temp1->next;
      free(p_temp1);
      p_temp1 = p_temp2;
    }while(p_temp2 != NULL);
}

void display(node *p_init)
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
  node *p_node, *p_node_previous, *p_node_next, *p_init;
  int i, par;
  
  p_init = NULL;
  i = 1;
  p_buff = buff;
  while(*s)
    {
      if(*s == '(')
	{
	  ++s;
	  par = 0;
	  while(1)
	    {
	      if(*s == ')')
		  ++par;
	      if(*s == '(')
		--par;
	      *(p_buff++) = *(s++);
	      if(par == 1)
		break;
	    }
	  *(--p_buff) = '\0';
	  add_node(&p_init, (float)calc(buff));
	  if(*s)
	    add_node(&p_init, (float)*s++);
	  p_buff = buff;
	  continue;
	}
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
      add_node(&p_init, temp);

      if(*s)
	add_node(&p_init, (float)*s++);
    }


  while(p_init->p_next != NULL)
    {
      p_node = access_node(p_init, i);
      if(p_node->num == '*')
	{
	  p_node_previous = access_node(p_init, i-1);
	  p_node_next = access_node(p_init, i+1);
	  p_node_previous->num = p_node_previous->num * p_node_next->num;
	  rm_node(p_init, i);
	  rm_node(p_init, i);//node'i + 1' devient node'i'
	  p_node = access_node(p_init, i-1);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}
      if(p_node->num == '/')
	{
	  p_node_previous = access_node(p_init, i-1);
	  p_node_next = access_node(p_init, i+1);
	  p_node_previous->num = p_node_previous->num / p_node_next->num;
	  rm_node(p_init, i);
	  rm_node(p_init, i);
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
      p_node = access_node(p_init, i);

      if(p_node->num == '+')
	{
	  p_node_previous = access_node(p_init, i-1);
	  p_node_next = access_node(p_init, i+1);
	  p_node_previous->num = p_node_previous->num + p_node_next->num;
	  rm_node(p_init, i);
	  rm_node(p_init, i);
	  p_node = access_node(p_init, i-1);
	  if(p_node->p_next == NULL)
	    break;
	  continue;
	}

      if(p_node->num == '-')
	{
	  p_node_previous = access_node(p_init, i-1);
	  p_node_next = access_node(p_init, i+1);
	  p_node_previous->num = p_node_previous->num - p_node_next->num;
	  rm_node(p_init, i);
	  rm_node(p_init, i);
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
