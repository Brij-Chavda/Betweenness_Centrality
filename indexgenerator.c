#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

int GetIndex(int h, int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (*(A + i) == -3)
        {
            *(A + i) = h;
            break;
        }
        else if (*(A + i) == h)
        {
            break;
        }
    }
    return i;
}

int GenValue(int i, int *A)
{
    return *(A + i);
}

void PrintBetCe(float *BetCe, int *GI, int n, int newn)
{
    int index;
    for (int i = 0; i < n + 1; i++)
    {
        index = 0;
        for (int j = 0; j < newn; j++)
        {
            if (i == GenValue(j, GI))
            {
                printf("\t %f", *(BetCe + j));
                index = 1;
            }
        }
        if (index == 0)
        {
            printf("\t 0.000000");
        }
    }
}