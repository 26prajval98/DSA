#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

typedef struct node{
    int data;
    int visited;
    struct node* current;
    struct node* next;

}Node;

Node* createNode(Node* current){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->current = current;
    temp->next = NULL;
    return temp;
}

void createList(Node** graph, int i){
    Node* temp = graph[i];
    while(1){
        printf("-1 to exit and v to add edge \n");
        int edge;
        scanf("%d",&edge);
        if(edge <= -1) break;
        else{
            temp->next = createNode(graph[edge]);
            temp = temp->next;
        }
    }
    return;
}

Node* stack[5];
int top = -1;

void push(Node* data){
    stack[++top] = data;
}

Node* pop(){
    Node* temp = stack[top];
    top--;
    return temp;
}

void DFS(Node* graph){
    Node* u = graph;
    printf("%d->",u->current->data);
    u->current->visited = 1;
    while(u!=NULL){
        if(u->current->visited == 0){
            DFS(u->current);
        }
        u = u->next;
    }
}

int main(){
    int n;
    printf("Enter number of vertices:   ");
    scanf("%d",&n);
    Node **graph = (Node**)malloc(n*sizeof(Node*));
    int i;

    for(i=0;i<n;i++){
        graph[i] = (Node*)malloc(sizeof(Node));
    }

    for(i=0;i<n;i++){
        int data;
        printf("Enter data of vertex %d:  ",i);
        scanf("%d",&data);
        graph[i]->data = data;
        graph[i]->visited = 0;
        graph[i]->current = graph[i];
        graph[i]->next = NULL;
    }

    for(i=0;i<n;i++){
        printf("Edges for List %d\n",i);
        createList(graph,i);
    }
    for(i=0;i<n;i++){
        if(graph[i]->visited == 0){
            DFS(graph[i]);
        }
    }
}
