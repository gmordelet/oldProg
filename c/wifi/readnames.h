#define MAX_ARR 200

typedef struct t_name t_name;
struct t_name {
  char *name;
  unsigned long count;
  unsigned long pos; //position du premier byte de time
};


void ReadNames(t_name *);
char *AllocName(char *);
void PrintDates(t_name *);
