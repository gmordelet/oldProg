#include<stdio.h>
#include"matrix.h"
#include<time.h>

#define pn printf("\n")
#define pt printf("test\n")

int main()
{
  t_matrix matrix1, matrix2, matrix3;
  int err, n;
  clock_t start, stop;
  double duration;

  srand(time(NULL));

  n = 1000;
  matrix1 = RandMatrix(n, n, -10, 10);
  matrix2 = RandMatrix(n, n, -10, 10);

  //  PrintMatrix(matrix1);
  pn;
  //PrintMatrix(matrix2);
  pn;
  start = clock();
  //matrix3 = MatrixAddition(matrix1, matrix2, &err);
  matrix3 = MatrixMultiplication1(matrix1, matrix2, &err);
  stop = clock();
  duration = (double)stop - start / CLOCKS_PER_SEC;
  duration /= 1000;
  printf("%lf\n", duration);
  //PrintMatrix(matrix3);

  return 0;
}
