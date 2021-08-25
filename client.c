#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

void main()
{
	int n = 327, *GI, newn, index;

	y *adjlist[n + 1];

	float *BetCe, *BetCe1;

	GI = (int *)malloc(n * sizeof(int));

	newn = inp1(n, GI);

	printf("newn is %d\n", newn);

	inp(adjlist, newn);

	BetCe = Floyd(adjlist, newn);

	PrintBetCe(BetCe, GI, n, newn);

	free(BetCe);

	printf("\n\n\n\n");

	BetCe1 = BFSalg(adjlist, newn);

	PrintBetCe(BetCe1, GI, n, newn);

	free(BetCe1);
}
