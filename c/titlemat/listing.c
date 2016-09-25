#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

void read_tree(char *, int);
void print_space(int);

int main(int argc, char *argv[])
{
  struct dirent *file;
  DIR *dir;

  printf("\n");

  read_tree(".", 0);

  printf("\n");

  return 0;
}

void read_tree(char *name, int space)
{
  struct dirent *dp;
  DIR *dfd;
  struct stat stbuf;

  printf("Arguments read_tree : name = %s space = %d\n", name, space);

  if((dfd = opendir(name)) == NULL)
    {
      printf("Erreur read_tree : opendir(\"%s\")\n", name);
    }
  while((dp = readdir(dfd)) != NULL)
    {
      if(strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0)
	{
	  print_space(space);
	  printf("%s\n", dp->d_name);
	  stat(dp->d_name, &stbuf);
	  if((stbuf.st_mode & S_IFMT) == S_IFDIR)
	    {
	      read_tree(dp->d_name, space + 1);
	    }
	}
    }
  closedir(dfd);
}

void print_space(int space)
{
  while(space-- > 0)
    putchar('-');
}
