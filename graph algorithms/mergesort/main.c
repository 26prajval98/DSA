#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int *P, int *Q, int a, int b){
    int i=0, j=0,k=0;
    while(i<a&&j<b){
        if(P[i]<Q[j]){
            A[k] = P[i];
            i++;k++;
        }
        else{
            A[k] = Q[j];
            j++;k++;
        }
    }
    while(i<a){
        A[k] = P[i];
        i++;k++;
    }
    while(j<b){
        A[k] = Q[j];
        j++;k++;
    }
}

void printArr(int *A, int l){
    int i=0;
    for(i=0;i<l;i++){
        printf("%d   ",A[i]);
    }
    printf("\n\n");
}

void mergeSort(int *A,int n){
        int m = n/2,i;
        if(n<2)
            return;
        int P[m], Q[n-m];
        printf("%d\n",m);
        for(i=0;i<m;i++){
            P[i] = A[i];
        }
        for(i=m;i<n;i++){
            Q[i-m] = A[i];
        }

        mergeSort(P,m);
        printArr(P,m);
        mergeSort(Q,n-m);
        printArr(Q,n-m);
        merge(A,P,Q,m,n-m);
        printArr(A,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    mergeSort(A,n);

    for(i=0;i<n;i++){
        printf("(%d,%d)",A[i],i);
    }
}
