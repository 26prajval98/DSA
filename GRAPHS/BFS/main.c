#include <stdio.h>
#include <stdlib.h>

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

void adjList(Node** graph,int i, int n){
    Node* temp = graph[i];
    while(1){
        printf("-1 to exit vertex number to make an edge\n");
        int edge;
        scanf("%d",&edge);
        if(edge <= -1)
            break;
        else if(edge >= n){
            printf("Enter a valid vertex number\n");
        }
        else{
            temp->next = createNode(graph[edge]);
            temp = temp->next;
        }
    }
}

int rear = -1,front = -1;
Node* Q[100];

void EnQ(Node* temp){
    Q[++rear] = temp;
}

Node* DeQ(){
    Node* temp = Q[++front];
    return temp;
}

void BFS(Node** graph, int i){
    graph[i]->visited = 1;
    EnQ(graph[i]);
    while(front != rear){
        Node* u = DeQ();
        printf("%d->",u->current->data);
        while(u!=NULL){
            if(u->current->visited == 0){
                u->current->visited = 1;
                EnQ(u->current);
            }
            u = u->next;
        }
    }
}

int main(){
    int n,i;
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    Node** graph = (Node**)malloc(n*sizeof(Node*));

    for(i=0;i<n;i++){
        graph[i] = (Node*)malloc(sizeof(Node));
        printf("Enter data for %d: ",i);
        scanf("%d",&(graph[i]->data));
        graph[i]->visited = 0;
        graph[i]->current = graph[i];
        graph[i]->next = NULL;
    }

    for(i=0;i<n;i++){
        printf("For %d\n",i);
        adjList(graph,i,n);
    }

    printf("Enter source: ");
    int s;
    scanf("%d",&s);
    BFS(graph,s);
}
