#include <stdio.h>
#include <stdlib.h>

int partition(int* A,int low, int high){
    int i, j;
    j = low-1;
    int key = A[high-1];
    for(i=low;i<high-1;i++){
        if(A[i]<key){
            j++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[j+1];
    A[j+1] = A[high-1];
    A[high-1] = temp;
    return j+1;
}

void quicksort(int *A,int low, int high){
    if(low<high){
        int p = partition(A,low,high);
        quicksort(A,low,p-1);
        quicksort(A,p+1,high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    quicksort(A,0,n);
    for(i=0;i<n;i++){
        printf("(%d,%d) ",A[i],i);
    }
}
