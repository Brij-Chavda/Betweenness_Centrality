#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

void dfs(int i, int cn, int *counter, y **adjlist1, int *visited, int *component)
{
	y *h;
	visited[i] = 1;
	component[i] = cn;
	for (h = adjlist1[i]; h != NULL; h = h->next)
	{
		if (!visited[(h->elements)])
		{
			visited[(h->elements)] = 1;
			(*(counter + cn - 1)) = (*(counter + cn - 1)) + 1;
			dfs((h->elements), cn, counter, adjlist1, visited, component);
		}
	}
}

int inp1(int n, int *GI)
{
	FILE *fptr;
	char ch, filename[100];
	int i, k1, div[2], breakflag, cn = 0, *counter, temp, visited[n], component[n], index, maxcn, newn;
	y *header[n + 1], *a1, *a2, *adjlist1[n + 1];
	for (i = 0; i < n + 1; i++)
	{
		header[i] = NULL;
		adjlist1[i] = NULL;
		if (i != n)
		{
			*(GI + i) = -3;
		}
	}
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	while (1)
	{
		for (i = 0; i < 3; i++)
		{
			k1 = 0;
			while (1)
			{
				breakflag = 0;
				ch = fgetc(fptr);
				if (ch == EOF)
				{
					breakflag = 1;
					break;
				}
				if (i == 2 || ch == ' ')
				{
					if (i == 2)
					{
						while (ch != '\n')
						{
							ch = fgetc(fptr);
						}
					}
					break;
				}
				k1 = ((int)ch - 48) + (k1 * 10);
			}
			if (breakflag == 1)
			{
				break;
			}
			if (i == 2)
			{
				a1 = insert1(&header[div[i - 2]], div[i - 1]);
				a2 = insert1(&header[div[i - 1]], div[i - 2]);
				if (a1 != NULL)
				{
					adjlist1[div[i - 2]] = a1;
				}
				if (a2 != NULL)
				{
					adjlist1[div[i - 1]] = a2;
				}
				break;
			}
			div[i] = GetIndex(k1, GI, n);
		}
		if (breakflag == 1)
		{
			break;
		}
	}

	fclose(fptr);

	counter = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
		component[i] = 0;
		*(counter + i) = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			dfs(i, ++cn, counter, adjlist1, visited, component);
	}
	temp = *counter;
	index = 0;
	visited[0] = 0;
	for (int i = 1; i < n; i++)
	{
		visited[i] = 0;
		if (*(counter + i) > temp)
		{
			temp = *(counter + i);
			index = i;
		}
	}
	free(counter);
	printf("largest number is%d\n", temp);
	maxcn = component[index + 1];
	printf("\n maxcn and index is %d %d", maxcn, index);
	printf("\n");
	fptr = fopen("new.txt", "w");
	for (int i = 0; i < n; i++)
	{
		for (a2 = adjlist1[i]; a2 != NULL; a2 = a2->next)
		{
			visited[i] = 1;
			if (!visited[(a2->elements)])
			{
				if (component[(a2->elements)] == maxcn)
				{
					fprintf(fptr, "%d %d 9\n", i, a2->elements);
				}
			}
		}
	}
	fclose(fptr);
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	fptr = fopen("newg.txt", "w");
	for (int i = 0; i < n; i++)
	{
		for (a2 = adjlist1[i]; a2 != NULL; a2 = a2->next)
		{
			visited[i] = 1;
			if (!visited[(a2->elements)])
			{
				if (component[(a2->elements)] == maxcn)
				{
					fprintf(fptr, "%d %d 9\n", GenValue(i, GI), GenValue(a2->elements, GI));
				}
			}
		}
	}
	newn = 0;
	fclose(fptr);
	for (int i = 0; i < n; i++)
	{
		if (*(GI + i) == -3)
		{
			break;
		}
		else
		{
			newn++;
		}
	}

	return newn;
}
