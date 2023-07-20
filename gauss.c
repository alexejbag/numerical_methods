#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long double *slau(long n, long double (*matrix)[n+1]) //размер и указатель на СЛАУ
{
  long qn;
  long double matr_max = (long double)0;
  long double exch, temp;
  long double *res;
  long double *resh = malloc(n * sizeof(long double));
  //printf("SLAU!\n");
  for (int i = 0; i < n; i++)
  {
    fprintf(stderr, "%d\n", i);
    for (int q = i; q < n; q++)
    {
      if (fabs(matrix[q][i]) > matr_max)
      {
        matr_max = fabs(matrix[q][i]);
        qn = q;//номер строки, где максимальный главный элемент
      }
    }
    matr_max = 0;
    for (int u = 0; u <= n; u++)//перестановка строк
    {
      exch = matrix[i][u];
      matrix[i][u] = matrix[qn][u];
      matrix[qn][u] = exch;
    }
    temp = matrix[i][i];
    for (int j = i; j <= n; j++)
  	{
      matrix[i][j] /= temp;
  	}
  	for (int j = i + 1; j < n; j++)
  	{
  		temp = matrix[j][i];
  		for (int k = i; k <= n; k++)
  		{
  			matrix[j][k] -= temp * matrix[i][k]; //Обнуляем коэффициент при x
  		}
  	}
    for (int i = n - 1; i >= 0; i--)
  	{
  		resh[i] = matrix[i][n];
  		for (int j = i + 1; j < n; j++)
  			resh[i] -= matrix[i][j] * resh[j];
  	}
  }

  /*Check of result!!!
  for (int i = 0; i < n; i++)
  {
    printf("%.6Lf\n", resh[i]);
  }*/

  res = &resh[0];
  return res;
}

/*int main()
{
  long n = 5;
  long double *res;
  long double (*matrix)[n+1] = malloc((n + 1) * n * sizeof(long double));
  matrix[0][0] = (long double)1.05; matrix[0][1] = (long double)28; matrix[0][2] = (long double)3; matrix[0][3] = (long double)100.5; matrix[0][4] = (long double)1; matrix[0][5] = (long double)100.5;
	matrix[1][0] = (long double)33; matrix[1][1] = (long double)5; matrix[1][2] = (long double)7; matrix[1][3] = (long double)0; matrix[1][4] = (long double)7.8; matrix[1][5] = (long double)14.2;
	matrix[2][0] = (long double)1; matrix[2][1] = (long double)3; matrix[2][2] = (long double)0; matrix[2][3] = (long double)101; matrix[2][4] = (long double)25.6; matrix[2][5] = (long double)14;
  matrix[3][0] = (long double)3; matrix[3][1] = (long double)5; matrix[3][2] = (long double)0; matrix[3][3] = (long double)6; matrix[3][4] = (long double)9; matrix[3][5] = (long double)97;
	matrix[4][0] = (long double)1; matrix[4][1] = (long double)3; matrix[4][2] = (long double)40.48; matrix[4][3] = (long double)3; matrix[4][4] = (long double)10; matrix[4][5] = (long double)2;
/*
matrix[0][0] = (long double)10; matrix[0][1] = (long double)28; matrix[0][2] = (long double)3; matrix[0][3] = (long double)5; matrix[0][4] = (long double)20.5; matrix[0][5] = (long double)1.11;
matrix[0][6] = (long double)7.9;
matrix[1][0] = (long double)33; matrix[1][1] = (long double)5; matrix[1][2] = (long double)7; matrix[1][3] = (long double)0; matrix[1][4] = (long double)88; matrix[1][5] = (long double)2.5;
matrix[1][6] = (long double)2;
matrix[2][0] = (long double)1; matrix[2][1] = (long double)3; matrix[2][2] = (long double)0; matrix[2][3] = (long double)7; matrix[2][4] = (long double)3; matrix[2][5] = (long double)0.35;
matrix[2][6] = (long double)5;
matrix[3][0] = (long double)1.3; matrix[3][1] = (long double)9.34; matrix[3][2] = (long double)0; matrix[3][3] = (long double)37.1; matrix[3][4] = (long double)0; matrix[3][5] = (long double)7.66;
matrix[3][6] = (long double)(-4.36);
matrix[4][0] = (long double)10; matrix[4][1] = (long double)3; matrix[4][2] = (long double)8; matrix[4][3] = (long double)5; matrix[4][4] = (long double)9; matrix[4][5] = (long double)5;
matrix[4][6] = (long double)1;
matrix[5][0] = (long double)2.6; matrix[5][1] = (long double)3.4; matrix[5][2] = (long double)(-1.78); matrix[5][3] = (long double)(-4.4); matrix[5][4] = (long double)(-0.3);
matrix[5][5] = (long double)(-0.6);
matrix[5][6] = (long double)0.2;*/


/*  res = slau(n, matrix);
  //printf("%Lf\n", *res);
  return 0;
}*/
