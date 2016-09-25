#include"headers.h"

static node *nodeArr[0xFF + 1];//contient les branches de l'arbre

void InitCodeArr(unsigned char **codeArr)
{
  int i;

  for(i = 0; i <= 0xFF; ++i)
    {
      codeArr[i] = NULL;
    }
}

void FreeCodeArr(unsigned char **codeArr)
{
  int i;

  for(i = 0; i <= 0xFF; ++i)
    {
      if(codeArr[i] != NULL)
	{
	  free(codeArr[i]);
	}
    }
}

//MakeCodeArr
/*
  Crée le codage de Huffman dans codeArr, à partir du tableau de bytes byteArr
*/
node *MakeCodeArr(unsigned long *byteArr, unsigned char **codeArr)
{
  node *root;

  InitNodeArr(byteArr);
  root = MakeTree();
  MakeCode(codeArr, root);
 
  return root;

}

//MakeTree
/*
  Crée l'arbre de Huffman, renvoie la case de nodeArr qui correspond au premier embranchement de l'abre
*/
node *MakeTree()
{
  int i, i1, i2;
  double temp;
  node *root, *pnode;

  for(i = 0; i < 0xFF; ++i)
    {
      i1 = FindMin();
      temp = nodeArr[i1]->per;
      pnode = nodeArr[i1];
      nodeArr[i1]->per = 1.1;
      i2 = FindMin();
      nodeArr[i1] = MakeNode(
			     -1,
			     nodeArr[i2]->per + temp,
			     MakeNode(nodeArr[i1]->c, temp, nodeArr[i1]->left, nodeArr[i1]->right),
			     nodeArr[i2]
			     );
      free(pnode);
      nodeArr[i2] = NULL;
      if(i == 0xFE)
	{
	  root = nodeArr[i1];
	}
    }  
  return root;
}

//InitNodeArr
/*
  Initialise nodeArr à partir du tableau de bytes byteArr, chaque case de nodeArr contient 
  un pointeur vers une structure node contenant le byte correspondant 
  à l'indice de la case, son pourcentage d'apparition et deux pointeurs left et right nulls
*/
void InitNodeArr(unsigned long *byteArr)
{
  int i;
  unsigned long total;

  for(i = 0, total = 0; i <= 0xFF; ++i)
    {
      total += byteArr[i];
    }
  for(i = 0; i <= 0xFF; ++i)
    {
      nodeArr[i] = MakeNode(i, byteArr[i] / (double)total, NULL, NULL);
    }
}

//FindMin
/*
  Cherche la case de nodeArr qui contient le plus petit pourcentage, et renvoie son indice
*/
int FindMin()
{
  double min;
  int iMin, i;
  for(i = 0, min = 1.1; i <= 0xFF; ++i)
    {
      if(nodeArr[i] != NULL)
	{
	  if(nodeArr[i]->per < min)
	    {
	      min = nodeArr[i]->per;
	      iMin = i;
	    }
	}
    }
  return iMin;
}

//MakeNode
/*
  Alloue de la mémoire pour une structure node, lui attribue c, per, left, et right ; puis renvoie un pointeur vers cette structure
*/
node *MakeNode(int c, double per, node *left, node *right)
{
  node *temp = malloc(sizeof(node));
  
  temp->c = c;
  temp->per = per;
  temp->left = left;
  temp->right = right;

  return temp;
}

static unsigned char buff[0xFF + 1]; //contient le buffer pour MakeCode et MakeCodeRec

//MakeCode
/*
  Crée le code de Huffman à partir du premier embranchement de l'arbre, chaque case du tableau code contient
  un pointeur correspondant au byte de l'indice de la case. Le pointeur pointe vers un tableau ayant pour premiere case 
  le nombre de caracteres du code, puis le code
*/
void MakeCode(unsigned char **code, node *root)
{
  int n, i, j;
  
  for(i = 0; i <= 0xFF; ++i)
    {
      buff[0] = 0;
      n = MakeCodeRec(i, 1, root->left);
      if(n > 0)
	{
	  code[i] = malloc(sizeof(char) * (n + 1));
	  code[i][0] = n;
	  for(j = 0; n-- > 0; ++j)
	    {
	      code[i][j + 1] = buff[j];
	    }
	  continue;
	}
      buff[0] = 1;
      n = MakeCodeRec(i, 1, root->right);
      if(n > 0)
	{
	  code[i] = malloc(sizeof(char) * (n + 1));
	  code[i][0] = n;
	  for(j = 0; n-- > 0; ++j)
	    {
	      code[i][j + 1] = buff[j];
	    }
	}
    }
}

int MakeCodeRec(int c, int n, node *node)
{
  int nReturn;

  if(node->left == NULL)
    {
      if(node->c == c)
	{
	  return n;
	}
      return 0;
    }
  buff[n] = 0;
  if((nReturn = MakeCodeRec(c, n + 1, node->left)) > 0)
    {
      return nReturn;
    }
  buff[n] = 1;
  return MakeCodeRec(c, n + 1, node->right);
}

//FreeTree
/*
  Libère la mémoire allouée pour l'arbre
*/
void FreeTree(node *node)
{
  if(node->left == NULL)
    {
      free(node);
      return;
    }
  FreeTree(node->left);
  FreeTree(node->right);
  free(node);
}
