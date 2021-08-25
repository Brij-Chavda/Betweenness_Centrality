#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

y *insert1(y **ptr, int i)
{
	y *temp, *a = NULL;
	if (*ptr == NULL)
	{
		*ptr = (y *)malloc(sizeof(y));
		(*ptr)->next = NULL;
		(*ptr)->elements = i;
		a = *ptr;
	}
	else
	{
		while ((*ptr)->next != NULL)
		{
			*ptr = (*ptr)->next;
		}
		temp = (y *)malloc(sizeof(y));

		temp->next = NULL;
		temp->elements = i;
		(*ptr)->next = temp;
	}
	return a;
}
