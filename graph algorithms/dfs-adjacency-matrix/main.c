#include <stdio.h>
#include <stdlib.h>


void DFS(int **A, int *visited, int *data, int i, int n){
    visited[i] = 1;
    printf("%d->",data[i]);
    int j;
    for(j=1;j<n;j++){
        if(A[i][j]>0&&visited[j]==0){
            DFS(A,visited,data,j,n);
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    int n;
    scanf("%d",&n);
    int **A = (int **)malloc(n*sizeof(int*)),visited[n],data[n],i,j;
    for(i=0;i<n;i++){
        A[i] = (int*)malloc(sizeof(int));
    }
    printf("Adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
        visited[i] = 0;
    }
    printf("Data of each\n");
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",A[i][j]);
        }
        //visited[i] = 0;
    }*/
    for(i=0;i<n;i++){
        if(visited[i]==0){
            DFS(A,visited,data,i,n);
            printf("\n");
        }
    }
}
