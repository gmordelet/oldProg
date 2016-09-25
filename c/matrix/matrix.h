typedef struct t_matrix t_matrix;
struct t_matrix
{
  int column;
  int row;
  double **arr;
};

double Determinant(t_matrix);
int PrintMatrix(t_matrix);
t_matrix SetMatrix(double *, int, int, int, int *);
t_matrix MatrixMultiplication1(t_matrix, t_matrix, int *);
t_matrix RandMatrix(int, int, int, int);
t_matrix MatrixAddition(t_matrix, t_matrix, int *);
