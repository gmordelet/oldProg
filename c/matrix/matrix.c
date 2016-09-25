#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

#define pt printf("test\n")

/*
  Determinant
  Retourne le determinant d une matrice
*/
double Determinant(t_matrix matrix)
{
  int i, j, column, row, neg, err;
  double temp, tempArr[(matrix.row - 1) * (matrix.column - 1)];
  t_matrix tempMatrix;

  if(matrix.row != matrix.column)
    {
      fprintf(stderr, "Erreur Determinant : La matrice doit etre carree\n");
      return 0;
    }

  if(matrix.row == 2)
    {
      return matrix.arr[0][0] * matrix.arr[1][1] - matrix.arr[1][0] * matrix.arr[0][1];
    }

  temp = 0;
  for(i = 0; i < matrix.column; ++i)
    {
      column = 0;
      row = 1;
      j = 0;
      while(j < (matrix.column - 1) * (matrix.row - 1))
	{
	  if(column == matrix.column)
	    {
	      row++;
	      column = 0;
	    }
	  if(column == i)
	    {
	      ++column;
	      continue;
	    }
	  tempArr[j++] = matrix.arr[column][row];
	  ++column;
	}
      tempMatrix = SetMatrix(tempArr, sizeof(tempArr)/sizeof(tempArr[0]), matrix.column - 1, matrix.row - 1, &err);
      temp += ((i % 2) ? -1 : 1)
              * matrix.arr[i][0]
	      * Determinant(tempMatrix);
      FreeMatrix(tempMatrix);
    }

  return temp;
}

/*
FreeMatrix
Desalloue la memoire alloue au tableau de valeur d une matrice
 */
int FreeMatrix(t_matrix matrix)
{
  int i;
  if(matrix.arr != NULL)
    {
      for(i = 0; i < matrix.column; ++i)
	{
	  free(matrix.arr[i]);
	}
      free(matrix.arr);
      matrix.arr = NULL;
      return 0;
    }
  else
    {
      fprintf(stderr, "Erreur FreeMatrix : La matrice n a pas de valeurs a desallouees");
      return -1;
    }
}

/*
  SetMatrix
  Definie les valeurs d un matrice, retourne -1 si probleme, 0 sinon
*/
t_matrix SetMatrix(double *arr, int size,int row, int column, int *err)
{
  int i, j;
  t_matrix matrix;

  if(size != column * row)
    {
      fprintf(stderr, "Erreur SetMatrix : Mauvaise taille de matrix, column = %d, row = %d, taille du tableau = %d\n", column, row, size);
      *err = -1;
    }

  matrix.column = column;
  matrix.row = row;
  matrix.arr = (double**)malloc(row * sizeof(double*));
  for(i = 0; i < row; ++i)
    {
      matrix.arr[i] = (double*)malloc(column * sizeof(double));
    }
  for(i = 0; i < row; ++i)
    {
      for(j = 0; j < column; ++j)
	{
	  matrix.arr[i][j] = *arr++;
	}
    }

  *err = 0;
  return matrix;
}

/*
  PrintMatrix
  Affiche une matrice
  Retourne -1 si la matrice n'a pas de valeur, 0 sinon
*/
int PrintMatrix(t_matrix matrix)
{
  int i, j;

  if(matrix.arr == NULL)
    {
      fprintf(stderr, "Erreur PrintMatrix : La matrice n a pas de valeurs\n");
      return -1;
    }

  for(i = 0; i < matrix.row; ++i)
    {
      for(j = 0; j < matrix.column; ++j)
	{
	  printf("%6.2lf ", matrix.arr[i][j]);
	}
      printf("\n");
    }

  return 0;
}


t_matrix MatrixMultiplication1(t_matrix matrix1, t_matrix matrix2, int *err)
{
  int ai, aj, bi, bj, c;
  t_matrix result = {0, 0, NULL};
  double *arr, sum;
  int err1;

  if(matrix1.column != matrix2.row)
    {
      *err = -1;
      return result;
    }
  
  arr = (double *)malloc(sizeof(double)* matrix1.row * matrix2.column);
  c = 0;
  sum = 0;

  for(ai = 0; ai < matrix1.row; ++ai)
    {
      for(bj = 0; bj < matrix2.column; ++bj)
	{
	  for(sum = 0, aj = 0, bi = 0; aj < matrix1.column; ++aj, ++bi)
	    {
	      //printf("ai = %d, aj = %d, bi = %d, bj = %d\n", ai + 1, aj + 1, bi + 1, bj + 1);
	      sum += matrix1.arr[ai][aj] * matrix2.arr[bi][bj];
   	    }
	  arr[c] = sum;
	  ++c;
	}
    }

  result =  SetMatrix(arr, matrix1.row * matrix2.column, matrix2.column, matrix1.row, &err1);
  *err = err1;

  return result;
}

t_matrix RandMatrix(int row, int column, int max, int min)
{
  t_matrix matrix;
  double arr[row * column];
  int i, err;

  for(i = 0; i < row * column; ++i)
    arr[i] = rand() % (max - min) - min 
    + rand() % 11 / 10.0 * ((rand() % 2) ? -1 : 1)
    + rand() % 11 / 100.0 * ((rand() % 2) ? -1 : 1);

  matrix = SetMatrix(arr, row * column, row, column, &err);

  return matrix;
}

t_matrix MatrixAddition(t_matrix matrix1, t_matrix matrix2, int *err)
{
  t_matrix matrix = {0, 0, NULL};
  int i, j, c;
  double *arr;

  if(matrix1.row != matrix2.row || matrix2.column != matrix1.column) {
    *err = -1;
    return matrix;
  }

  c = 0;
  arr = (double *)malloc(sizeof(double) * matrix1.row * matrix2.column);
  for(i = 0; i < matrix1.row; ++i)
    for(j = 0; j < matrix1.column; ++j)
      arr[c++] = matrix1.arr[i][j] + matrix2.arr[i][j];

  matrix = SetMatrix(arr, matrix1.row * matrix1.column, matrix1.row, matrix1.column, err);
  *err = 0;

  return matrix;
}
