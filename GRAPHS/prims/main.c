#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

typedef struct vert{
    int key;
    int p;
    int i;
}Vertex;

Vertex Q[100];

int front=-1,rear=-1;

void EnQ(Vertex  u){
    Q[++rear] = u;
}

Vertex DeQ(){
    return Q[++front];
}

void sortQ(){
    int i, j;
    Vertex temp;
    for(i=front+1;i<rear+1;i++){
        for(j=front+1;j<rear;j++){
            if(Q[j].key > Q[j+1].key ){
                temp = Q[j];
                Q[j] = Q[j+1];
                Q[j+1] = temp;
            }
        }
    }
}

int findJ(int j){
    int i;
    for(i=front+1;i<=rear;i++){
        if(Q[i].i == j)
            return j;
    }
    return -1;
}

void printQ(){
    int i;
    for(i=front+1;i<=rear;i++){
        printf("(%d,%d,%d)  ",Q[i].i,Q[i].p,Q[i].key);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int **A = (int**)malloc(n*sizeof(int *));
    int i,j;
    for(i=0;i<n;i++){
        A[i] =(int*)malloc(n*sizeof(int));
    }
    printf("Enter adj matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    Vertex V[n];
    for(i=0;i<n;i++){
        V[i].key = INFINITY;
        V[i].i = i;
        V[i].p = -1;
    }
    for(i=0;i<n;i++){
        EnQ(V[i]);
    }
    V[0].key = 0;
    V[i].i = 0;
    V[i].p = -1;
    while(front!=rear){
        sortQ();
        printQ();
        Vertex u = DeQ();
        i = u.i;
        for(j=0;j<n;j++){
            int pos = findJ(j);
            if(A[i][j] != 0 && A[i][j]<V[j].key && pos>=0){
                V[j].key = A[i][j];
                Q[pos].key = A[i][j];
                V[j].p = i;
                Q[pos].p = i;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("(%d,%d,%d)",V[i].i,V[i].p,V[i].key);
    }
    int sum = 0;

    for(i=0;i<n;i++){
        sum += V[i].key;
    }
    printf("Total path: %d",sum);
}
