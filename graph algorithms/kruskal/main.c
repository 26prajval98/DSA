#include <stdio.h>
#include <stdlib.h>

typedef struct weight{
    int weight;
    int i;
    int j;
}Weight;

void sortWeight(struct weight **A,int e){
    int i,j;
    struct weight *temp;
    for(i=0;i<e;i++){
        for(j=0;j<e-1;j++){
            if(A[j]->weight > A[j+1]->weight){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int search(int *SET, int i, int j){
    if(SET[i]!=SET[j])
        return 1;
    else
        return 0;
}

void UNION(int *SET, int a, int b, int n){
    int i;
    for(i=0;i<n;i++){
        if(SET[i]==b){
            SET[i] = a;
        }
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int **A = (int**)malloc(n*sizeof(int*)),i,j,e,SET[n];
    Weight **W = (Weight **)malloc(100*sizeof(Weight*));
    for(i=0;i<100;i++){
        W[i] = (Weight*)malloc(sizeof(Weight));
    }
    //W[9]

    for(i=0;i<n;i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            A[i][j] = 0;
        }
        SET[i] = i;
    }
    e=0;
    while(1){
        printf("Enter weight,from,to (-1 -1 -1 to break) to exit:\n");
        int wgt;
        scanf("%d %d %d",&wgt,&i,&j);
        if(wgt == -1 && i == -1 && j == -1){
            break;
        }
        else{
            A[i][j] = wgt;
            printf("%d",e);
            W[e]->weight = wgt;
            printf("%d",e);
            W[e]->i = i;
            printf("%d",e);
            W[e]->j = j;
            printf("%d",e);
            e++;
            printf("%d\n",e);
        }
    }

    sortWeight(W,e);

    for(i=0;i<e;i++){
        printf("(%d,%d,%d) ", W[i]->weight, W[i]->i, W[i]->j);
    }
    int sum=0;

    printf("\n Adjacency matrix is\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",A[i][j]);
        }
        //SET[i] = 0;
        printf("\n");
    }
    printf("Adj matrix done\n");
    int k;
    for(k=0;k<e;k++){
        if(search(SET,W[k]->i,W[k]->j)){
            int a = SET[W[k]->i];
            int b = SET[W[k]->j];
            UNION(SET,a,b,n);
            sum+=W[k]->weight;
            printf("%d %d %d \n",W[k]->weight,W[k]->i,W[k]->j);
        }
    }
    printf("%d",sum);
    return 0;*/
}
