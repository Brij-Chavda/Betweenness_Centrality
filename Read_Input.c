#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

void inp(y **adjlist, int n)
{
	FILE *fptr;
	char ch, filename[100];
	int i, k1, div[2], breakflag;
	y *header[n + 1], *a1, *a2;
	for (i = 0; i < (n + 1); i++)
	{
		header[i] = NULL;
		adjlist[i] = NULL;
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
					adjlist[div[i - 2]] = a1;
				}
				if (a2 != NULL)
				{
					adjlist[div[i - 1]] = a2;
				}
				break;
			}
			div[i] = k1;
		}
		if (breakflag == 1)
		{
			break;
		}
	}

	fclose(fptr);
}
