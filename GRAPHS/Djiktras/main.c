#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

typedef struct vertex{
    int key;
    int d;
    int i;
}Vertex;

Vertex Q[100];

int front = -1, rear = -1;

void EnQ(Vertex u){
    Q[++rear] = u;
}

Vertex DeQ(){
    return Q[++front];
}

void sortQ(){
    int i,j;
    for(i=front+1;i<rear+1;i++){
        for(j=front+1;j<rear;j++){
            if(Q[j].key > Q[j+1].key){
                Vertex temp = Q[j];
                Q[j] = Q[j+1];
                Q[j+1] = temp;
            }
        }
    }
}

int findPos(int s){
    int i;
    for(i=front+1;i<=rear;i++){
        if(Q[i].i == s)
            return i;
    }
    return -1;
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int **A = (int**)malloc(n*sizeof(int*));
    int i,j;
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(n*sizeof(int*));
    }
    printf("Enter adjacency matrix: ")
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    Vertex V[n];
    for(i=0;i<n;i++){
        V[i].i = i;
        V[i].d = INFINITY;
        V[i].key = INFINITY;
    }
    i=0;
    printf("Enter source: ");
    int s;
    scanf("%d",&s);

    V[s].d = 0;
    V[s].key = 0;

    while(rear<=n-1){
        Q[++rear] = V[i++];
    }

    while(front!=rear){
        sortQ();
        Vertex u = DeQ();
        i = u.i;
        for(s=0;s<n;s++){
            int pos = findPos(s);
            if( A[i][s] > 0 && pos >= 0){
                if(V[s].d > V[i].d + A[i][s]){
                    V[s].d = V[i].d + A[i][s];
                    Q[pos].d = V[s].d;
                    V[s].key = A[i][s];
                    Q[pos].key = A[i][s];
                }
            }
        }
    }

    for(i=0;i<n;i++){
        printf("(%d,%d,%d) ",V[i].i,V[i].key,V[i].d);
    }
}
