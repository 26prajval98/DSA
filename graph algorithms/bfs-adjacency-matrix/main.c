#include <stdio.h>
#include <stdlib.h>

int Q[100],front,rear;

void EnQ(int u){
    Q[++rear] = u;
}

int DeQ(){
    return Q[++front];
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int **A = (int**)malloc(n*sizeof(int*)), visited[n],data[n],i,j;
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter data: ");
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
        visited[i] = 0;
    }
    printf("Enter adjacent matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter source: ");
    int s;
    scanf("%d",&s);
    EnQ(s);
    while(front!=rear){
        int u = DeQ();
        visited[u] = 1;
        printf("%d->",data[u]);
        for(i=0;i<n;i++){
            if(A[u][i] > 0 && visited[i]==0){
                EnQ(i);
            }
        }
    }
}
