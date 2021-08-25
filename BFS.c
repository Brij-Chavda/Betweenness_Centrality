#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header1.h"

int g;

struct Queue
	{
	int front;
	int rear;
	int *w;
	};
typedef struct Queue q;


void makenull(q *qw)
{       
        qw->front=0;
        qw->rear=g-1; 
}
int addone( int i )
{ 
        return ((i+1) % g);
}
int f1(int i,int j)
{
	return (i>=j) ? (((i*(i+1))/2)+j) : (((j*(j+1))/2)+i);
}

int empty(q *qw)
{
        if(addone(qw->rear)==qw->front)
        {
                return 1;
        } 
        else
        return 0;
}

void enqueue(int j,q *qw)
{
        if(addone(addone(qw->rear))==qw->front)
        {
                printf("queue is full");    
        }  
        else
        {
                qw->rear=addone(qw->rear);
                (qw->w)[qw->rear]=j;
        }   
}

int dequeue(q *qw)
{
        int x;
        if(!(empty(qw)))
        {  
                x=(qw->w)[qw->front];
                qw->front=addone(qw->front);
                return x; 
        }
        else
        return 99999;  
}

void BFS(y* *adjlist,int s,int *p, int *d,int n)
{
	int visited[n+1],temp;
        y*  h;	
	q *qw;
        qw = (q*)malloc(sizeof(q));
	(qw->w)=(int*)malloc(n*sizeof(int));	
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	d[f1(s,s)]=0;
	p[f1(s,s)]=1;
        makenull(qw);	
	enqueue(s,qw);
	visited[s]=1;
	while(!empty(qw))
	{
	        temp=dequeue(qw);
	        for(h=adjlist[temp];h!=NULL;h=h->next)
	          {
	                if(visited[(h->elements)]==0)
	                {
	                        visited[(h->elements)]=1;
	                        enqueue((h->elements),qw);
	                }
	                if(*(d+f1(s,(h->elements)))>(*(d+f1(temp,s))+1))
	                {
	                        *(d+f1(s,(h->elements)))=(*(d+f1(temp,s))+1);
	                       	if(s<((h->elements)))
	                        {	
	                                *(p+f1(s,(h->elements)))=*(p+f1(temp,s));
	                        } 
	                }
	               else if(*(d+f1(s,(h->elements)))==(*(d+f1(temp,s))+1))
	                {
	                        if(s<((h->elements)))
	                        { 
	                                *(p+f1(s,(h->elements)))+= *(p+f1(temp,s));
	                        } 
	                }
	          }
	}
	free(qw->w);
}

float *BFSalg(y* *adjlist,int n)
{ 
	clock_t start,end;
 	double cputime;
 	start = clock();      
	g=n;
        int *p,*d;
        float l,*BetCe; 
        y *h; 
	p = (int*) malloc(((n*(n+1))/2)*sizeof(int));
	d = (int*) malloc(((n*(n+1))/2)*sizeof(int));
        for(int i=0;i<n;i++)
	{
                for(int j=0;j<i+1;j++)
	        {
	                if(i!=j)
	                {  	
                        *(d+f1(i,j))=99999;
                        *(p+f1(i,j))=0; 
                    } 
                    else 
                    {  	
                        *(d+f1(i,j))=0;
                        *(p+f1(i,j))=1; 
                    }  
                } 
        }
        for(int i=0;i<n;i++)
        {
               BFS(adjlist,i,p,d,n);	
        }
	
	BetCe = (float*) malloc((n)*sizeof(float));
	int i=0;
    for(int k=0;k<n;k++)
	{
		*(BetCe+k)=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i+1;j++)
			{
				
				if(i!=j && i!=k && j!=k)
				{
					if((*(d+f1(i,k))+*(d+f1(k,j)))==*(d+f1(i,j)))
					{
						if(*(p+f1(i,j))!=0)
						{	
							l=((float)((*(p+f1(i,k)))*(*(p+f1(k,j)))))/((float)*(p+f1(i,j)));
							*(BetCe+k)=(float)(*(BetCe+k)+l);
						}
					}	
					
				}
			}
		}
	}	
	free(p);
	free(d);
	end = clock();
	cputime=((end-start)/CLOCKS_PER_SEC);		
	printf("\ncpu time is %e",cputime);
	return BetCe;
}      
