#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

int time = 0;

typedef struct vertex{
    int p;
    int i;
    int visited;
    int d;
    int f;
}Vertex;

void DFSvisit(int i, int n, Vertex *V, int **A){
    V[i].visited = 1;
    time++;
    V[i].d = time;
    int j;
    for(j=0;j<n;j++){
        if(A[i][j]>0 && V[j].visited == 0){
            V[j].p = i;
            DFSvisit(j,n,V,A);
        }
    }
    time++;
    V[i].f = time;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int **A = (int**)malloc(n*sizeof(int*)),i,j;
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }

    printf("Enter Adj matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    Vertex V[n];

    for(i=0;i<n;i++){
        V[i].i = i;
        V[i].p = -1;
        V[i].visited = 0;
    }

    for(i=0;i<n;i++){
        if(V[i].visited == 0){
            DFSvisit(i,n,V,A);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(V[j].f < V[j+1].f){
                Vertex temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("(%d,%d/%d,%d)",V[i].i,V[i].d,V[i].f,V[i].p);
    }
}
