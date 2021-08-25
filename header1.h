struct node
{
	int elements;
	struct node *next;
};

typedef struct node y;

void inp(y* *adjlist,int n);

int inp1(int n,int *GI);

float *Floyd(y* *adjlist,int n);

float *BFSalg(y* *adjlist,int n);

y* insert1(y** ptr,int i);

int GetIndex(int h, int *A,int n);

int GenValue(int i, int *A);

void PrintBetCe(float*,int*,int,int);



