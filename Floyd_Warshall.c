#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header1.h"

int f(int i, int j)
{
	return (i >= j) ? (((i * (i + 1)) / 2) + j) : (((j * (j + 1)) / 2) + i);
}

float *Floyd(y **adjlist, int n)
{
	y *h;
	clock_t start, end;
	double cputime;
	start = clock();
	int *p, *d;
	float *BetCe, l;
	p = (int *)malloc(((n * (n + 1)) / 2) * sizeof(int));
	d = (int *)malloc(((n * (n + 1)) / 2) * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			*(p + f(i, j)) = 0;
			if (i == j)
			{
				*(d + f(i, j)) = 0;
			}
			else
			{
				*(d + f(i, j)) = 99999;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (h = adjlist[i]; h != NULL; h = h->next)
		{
			*(d + f(i, h->elements)) = 1;
			*(p + f(i, h->elements)) = 1;
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (i != k && j != k)
				{
					if ((*(d + f(i, k)) + *(d + f(k, j))) < *(d + f(i, j)))
					{
						*(d + f(i, j)) = *(d + f(i, k)) + *(d + f(k, j));
					}
				}
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (i != k && j != k)
				{

					if (*(d + f(i, k)) + *(d + f(k, j)) == *(d + f(i, j)))
					{
						*(p + f(i, j)) = *(p + f(i, j)) + ((*(p + f(i, k))) * (*(p + f(k, j))));
					}
				}
			}
		}
	}
	printf("\n");
	printf("\n");

	BetCe = (float *)malloc((n) * sizeof(float));
	for (int k = 0; k < n; k++)
	{
		*(BetCe + k) = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{

				if (i != j && i != k && j != k)
				{
					if (*(d + f(i, k)) + *(d + f(k, j)) == *(d + f(i, j)))
					{
						if (*(p + f(i, j)) != 0)
						{
							l = ((float)((*(p + f(i, k))) * (*(p + f(k, j))))) / ((float)*(p + f(i, j)));
							*(BetCe + k) = (*(BetCe + k) + l);
						}
					}
				}
			}
		}
	}
	free(p);
	free(d);
	end = clock();
	cputime = ((end - start) / CLOCKS_PER_SEC);
	printf("\ncpu time is %e", cputime);
	return BetCe;
}
