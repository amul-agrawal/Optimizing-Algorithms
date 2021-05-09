#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 1000000000
#define BILLION 1000000000L

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

int **FloydWarshall(int **restrict dist,register int n)
{
	register int i, j, k;
	register int *restrict dist_i;
	register int *restrict dist_ij;
	register int *restrict dist_k;
	register int *restrict dist_kj;
	register int dist_ik;
	for (k = 0; k < n; ++k) 
	{
		dist_k = *(dist + k);
		for (i = 0; i < n; ++i) 
		{
			dist_i = *(dist + i);
			if (*(dist_i + k) != INF)
			{
				dist_ij = dist_i;
				dist_kj = dist_k;
				dist_ik = *(dist_i + k);
				for (j =  0; j < n - 15; j += 16) 
				{
					{
						if (dist_ik + *dist_kj <  *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if (  dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij =  dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}

					{
						if ( dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;
						}
						++dist_ij;
						++dist_kj;

					}
				}
				for(; j < n; ++j) 
				{
					{
						if (dist_ik + *dist_kj < *dist_ij) 
						{
							*dist_ij = dist_ik + *dist_kj;						
						}
						++dist_ij;
						++dist_kj;

					}
				}
			}
		}
	}
	return dist;
}

void print_distance(int **dist, int n)
{
	int *dist_i;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		dist_i = *(dist + i);
		for (j = 0; j < n - 15; j += 16)
		{
			printf("%d ", ((*(dist_i + j) == INF) ? -1 : *(dist_i + j)));
			printf("%d ", ((*(dist_i + j + 1) == INF) ? -1 : *(dist_i + j + 1)));
			printf("%d ", ((*(dist_i + j + 2) == INF) ? -1 : *(dist_i + j + 2)));
			printf("%d ", ((*(dist_i + j + 3) == INF) ? -1 : *(dist_i + j + 3)));
			printf("%d ", ((*(dist_i + j + 4) == INF) ? -1 : *(dist_i + j + 4)));
			printf("%d ", ((*(dist_i + j + 5) == INF) ? -1 : *(dist_i + j + 5)));
			printf("%d ", ((*(dist_i + j + 6) == INF) ? -1 : *(dist_i + j + 6)));
			printf("%d ", ((*(dist_i + j + 7) == INF) ? -1 : *(dist_i + j + 7)));
			printf("%d ", ((*(dist_i + j + 8) == INF) ? -1 : *(dist_i + j + 8)));
			printf("%d ", ((*(dist_i + j + 9) == INF) ? -1 : *(dist_i + j + 9)));
			printf("%d ", ((*(dist_i + j + 10) == INF) ? -1 : *(dist_i + j + 10)));
			printf("%d ", ((*(dist_i + j + 11) == INF) ? -1 : *(dist_i + j + 11)));
			printf("%d ", ((*(dist_i + j + 12) == INF) ? -1 : *(dist_i + j + 12)));
			printf("%d ", ((*(dist_i + j + 13) == INF) ? -1 : *(dist_i + j + 13)));
			printf("%d ", ((*(dist_i + j + 14) == INF) ? -1 : *(dist_i + j + 14)));
			printf("%d ", ((*(dist_i + j + 15) == INF) ? -1 : *(dist_i + j + 15)));
		}
		for(j; j < n; ++j)
		{
			printf("%d ", ((*(dist_i + j) == INF) ? -1 : *(dist_i + j)));
		}
		printf("\n");
	}
}

int main()
{

	// struct timespec begin, end;

	// if (clock_gettime(CLOCK_REALTIME, &begin) == -1)
	// {
	// 	perror("clock gettime");
	// 	return EXIT_FAILURE;
	// }

	// ----------- START CODE -----------------------------------

	int V, E;
	V = scan_d();
	E = scan_d();

	int **b = (int **)malloc(V * sizeof(int *));

	for (int i = 0; i < V; ++i)
	{
		*(b+i) = (int *)malloc(V * sizeof(int));
	}

	int *b_i;

	for (int i = 0; i < V; ++i)
	{
		b_i = *(b + i);
		int j = 0;
		for (; j < V - 15; j += 16)
		{
			*(b_i + j) = INF;
			*(b_i + j + 1) = INF;
			*(b_i + j + 2) = INF;
			*(b_i + j + 3) = INF;
			*(b_i + j + 4) = INF;
			*(b_i + j + 5) = INF;
			*(b_i + j + 6) = INF;
			*(b_i + j + 7) = INF;
			*(b_i + j + 8) = INF;
			*(b_i + j + 9) = INF;
			*(b_i + j + 10) = INF;
			*(b_i + j + 11) = INF;
			*(b_i + j + 12) = INF;
			*(b_i + j + 13) = INF;
			*(b_i + j + 14) = INF;
			*(b_i + j + 15) = INF;
		}
		for(;j < V; ++j)
		{
			*(b_i + j) = INF;
		}
		*(b_i + i) = 0;
	}

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		u = scan_d();
		v = scan_d();
		w = scan_d();

		--u; --v;
		*(*(b + u) + v) = (*(*(b + u) + v) ^ (*(*(b + u) + v) ^ w) & (-1 * (*(*(b + u) + v) > w)));
	}

	b = FloydWarshall(b, V);

	print_distance(b, V);


	// ------------ END CODE -------------------------------------

	// if (clock_gettime(CLOCK_REALTIME, &end) == -1)
	// {
	// 	perror("clock gettime");
	// 	return EXIT_FAILURE;
	// }

	// double S = (end.tv_sec - begin.tv_sec);
	// double NS = (double)(end.tv_nsec - begin.tv_nsec) / (double)BILLION;

	// printf("%lf", S + NS);
}


// Constraints
// 1. Vertices = 2500, Edges = 1e5
// 3. 1 <= W <= 1e5
// 2. Max Distance = (V - 1) * W = (2.5 * 1e3) * 1e5 = 2.5 * 1e8