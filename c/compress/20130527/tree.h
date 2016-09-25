#ifndef DEF_TREE
#define DEF_TREE

typedef struct node node;
struct node{
  int c;
  double per;
  node *left;
  node *right;
};

void InitNodeArr(unsigned long *);
node *MakeTree();
void MakeCodeArr(unsigned long *, unsigned char **);
int FindMin();
node *MakeNode(int, double, node *, node *);
void MakeCode(unsigned char **, node *);
int MakeCodeRec(int, int, node *);
void FreeTree(node *);

#endif
