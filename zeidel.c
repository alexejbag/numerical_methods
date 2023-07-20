#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int n = 7;
const long double eps = 0.001;

int norma(long double *x, long double *p)
{
	long double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (x[i] - p[i]) * (x[i] - p[i]);
	}
	sum = sqrt(sum);
	printf("%Lf\n", sum);
	if (sum < eps)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	long double (*matrix)[n] = malloc(n * n * sizeof(long double));
	long double *right = malloc(n * sizeof(long double));
	long double (*ld)[n] = malloc(n * n * sizeof(long double));
	long double (*u)[n] = malloc(n * n * sizeof(long double));
	long double *x = malloc(n * sizeof(long double));
	long double *p = malloc(n * sizeof(long double));
	long double *r2 = malloc(n * sizeof(long double));

	//input matrix

	FILE *fmatrix = fopen(argv[1], "w");
	FILE *fright = fopen(argv[2], "w");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = (rand() % 1000) / 7.0L;
			fprintf(fmatrix, "%Lf ", matrix[i][j]);
		}
		fprintf(fmatrix, "\n");
	}
	for (int i = 0; i < n; i++)
	{
		right[i] = (rand() % 1000) / 11.0L;
		fprintf(fright, "%Lf\n", right[i]);
	}
	fclose(fmatrix);
	fclose(fright);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= j)
			{
				ld[i][j] = matrix[i][j];
				u[i][j] = 0.0;
			}
			else
			{
				ld[i][j] = 0.0;
				u[i][j] = -matrix[i][j];
			}
		}
		x[i] = 0.0;
	}
	free(matrix);
	matrix = NULL;
	do
	{
		for (int i = 0; i < n; i++)
		{
			p[i] = x[i];
			r2[i] = 0.0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				r2[i] += u[i][j] * p[j];
			}
			r2[i] += right[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j < i)
				{
					r2[i] -= ld[i][j] * x[j];
				}
				else
				{
					x[j] = r2[i] / ld[j][j];
				}
			}
		}
	} while (norma(x, p));
	for (int i = 0; i < n; i++)
	{
		printf("%Lf\n", x[i]);
	}
	return 0;
}
