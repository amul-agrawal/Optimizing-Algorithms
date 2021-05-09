#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000
#define BILLION 1000000000L
#define MAXN 5

typedef struct Matrix
{
	long long **matrix;
} Matrix;


Matrix *get_matrix(int rows, int columns)
{
	Matrix *M = (Matrix *)malloc(sizeof(Matrix));
	M->matrix = (long long **)malloc(rows * sizeof(long long *));
	for (int i = 0; i < rows; ++i)
	{
		M->matrix[i] = (long long *)malloc(columns * sizeof(long long));
	}
	return M;
}

void free_matrix(Matrix *M, int r, int c) 
{
	for(int i=0; i < r; ++i)
	{
		free(M->matrix[i]);
	}
	free(M->matrix);
	free(M);
	return;
}

Matrix **M;
int n;
int *rows, *columns, *dimensions;
long operations[6][6], opt[6][6];

int scan_d() { 
	int ip=getchar_unlocked(),ret=0,flag=1; 
	for(;ip<'0'||ip>'9';ip=getchar_unlocked()) 
	if(ip=='-'){ 
		flag=-1; 
		ip=getchar_unlocked(); 
		break; 
	} 
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked()) 
		ret=ret*10+ip-'0'; 
	return flag*ret; 
} 

void print_lld(long long n) { 
	if(n<0){ 
		n=-n; 
		putchar_unlocked('-'); 
	} 
	int i=21; 
	char output_buffer[21]; 
	do{ 
		output_buffer[--i]=(n%10)+'0'; 
		n/=10; 
	}while(n); 
	do{ 
		putchar_unlocked(output_buffer[i]); 
	}while(++i<21); 
} 

void print_d(int n) { 
	if(n<0){ 
		n=-n; 
		putchar_unlocked('-'); 
	} 
	int i=10; 
	char output_buffer[10]; 
	do{ 
		output_buffer[--i]=(n%10)+'0'; 
		n/=10; 
	}while(n); 
	do{ 
		putchar_unlocked(output_buffer[i]); 
	}while(++i<10); 
} 

Matrix *matrix_multiply(Matrix *restrict A, Matrix *restrict B,register int r1,register int r2,register int c2)
{
	Matrix *result = get_matrix(r1, c2);
	register int i, k, j;

	Matrix *B1 = get_matrix(c2, r2);

	// Transpose B. No need return back to original state as this matrix is used only once.
	for(i = 0; i < c2; ++i)
	{
		for(j=0; j < r2; ++j)
		{
			B1->matrix[i][j] = B->matrix[j][i];
		}
	}
	
	// A -> (r1, r2), B -> (c2, r2)

	register long long *restrict a, *restrict c, *restrict b;

	for (i = 0; i < r1; ++i)
	{
		a = *(A->matrix + i);
		c = *(result->matrix + i);
		for (j = 0; j < c2; ++j)
		{
			b = *(B1->matrix + j);
			for (k = 0; k < r2 - 15; k += 16)
			{
				*(c + j) += (
					*(a + k) * *(b + k) +
					*(a + k + 1) * *(b + k + 1) +
					*(a + k + 2) * *(b + k + 2) +
					*(a + k + 3) * *(b + k + 3) +
					*(a + k + 4) * *(b + k + 4) +
					*(a + k + 5) * *(b + k + 5) +
					*(a + k + 6) * *(b + k + 6) +
					*(a + k + 7) * *(b + k + 7) +
					*(a + k + 8) * *(b + k + 8) +
					*(a + k + 9) * *(b + k + 9) +
					*(a + k + 10) * *(b + k + 10) +
					*(a + k + 11) * *(b + k + 11) +
					*(a + k + 12) * *(b + k + 12) +
					*(a + k + 13) * *(b + k + 13) +
					*(a + k + 14) * *(b + k + 14) +
					*(a + k + 15) * *(b + k + 15) 
				);
			}
			for (; k < r2; ++k)
			{
				*(c + j) += (*(a + k) * *(b + k));
			}
		}
	}
	return result;
}

void print_matrix(Matrix *M, int r, int c)
{
	printf("%d %d\n", r, c);
	int i, j;
	for (i = 0; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			printf("%lld ", M->matrix[i][j]);
		}
		printf("\n");
	}
}

// 1 based indexing
Matrix *chain_multiply(int l, int r)
{
	if (l == r)
	{
		return *(M + l - 1);
	}
	int k = opt[l][r];
	return matrix_multiply(chain_multiply(l, k), chain_multiply(k + 1, r), *(dimensions+l - 1), *(dimensions+k), *(dimensions+r));
}

int main()
{

	// struct timespec begin, end;
	// if (clock_gettime(CLOCK_REALTIME, &begin) == -1)
	// {
	// 	perror("clock gettime");
	// 	return EXIT_FAILURE;
	// }

	n = scan_d();

	M = (Matrix **)malloc(n * sizeof(Matrix *));
	rows = (int *)malloc(n * sizeof(int));
	columns = (int *)malloc(n * sizeof(int));
	dimensions = (int *)malloc((n + 1) * sizeof(int));

	int i, r, c;
	Matrix *m_i;
	register long long *matrix_row;

	for (i = 0; i < n; ++i)
	{
		*(rows + i) = scan_d();
		*(columns + i) = scan_d();

		m_i = get_matrix(rows[i], columns[i]);
		*(M + i) = m_i;

		for (r = 0; r < *(rows+i); ++r)
		{
			matrix_row = *(m_i->matrix + r);
			for (c = 0; c < *(columns+i); ++c)
			{
				*(matrix_row + c) = scan_d();
			}
		}
	}

// 	N is at max 5. The following doesn't really count.
// --------------------------------------------------------
	dimensions[0] = rows[0];
	for (int i = 0; i < n; ++i)
	{
		dimensions[i + 1] = columns[i];
	}

	++n;
	for (int i = 1; i < n; ++i)
	{
		operations[i][i] = 0;
		opt[i][i] = i;
	}

	for (int L = 2; L < n; ++L)
	{
		for (int i = 1; i < n - L + 1; ++i)
		{
			int j = i + L - 1;
			operations[i][j] = (double)1e10;

			for (int k = i; k <= j - 1; ++k)
			{
				int q = operations[i][k] + operations[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];

				if (q < operations[i][j])
				{
					operations[i][j] = q;
					opt[i][j] = k;
				}
			}
		}
	}
	--n;
// -----------------------------------------------------------------

	Matrix *result = chain_multiply(1, n);
	print_matrix(result, rows[0], columns[n-1]);

	// if (clock_gettime(CLOCK_REALTIME, &end) == -1)
	// {
	// 	perror("clock gettime");
	// 	return EXIT_FAILURE;
	// }
	// double S = (end.tv_sec - begin.tv_sec);
	// double NS = (double)(end.tv_nsec - begin.tv_nsec) / (double)BILLION;

	// printf("%lf", S + NS);
}
