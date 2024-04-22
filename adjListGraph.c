#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Graph{
    int numVertices;
    struct Node** adjList;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));

    if(newNode==NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;    
    return newNode;
}

struct Graph* createGraph(int numVertices){
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->adjList = (struct Node**)(malloc((numVertices+1)* sizeof(struct Node)));
    if(graph == NULL)
        return NULL;

    graph->numVertices = numVertices;

    for(int i=1; i<=numVertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dst){

    struct Node* node = createNode(dst);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;

    node = createNode(src);
    node->next = graph->adjList[dst];
    graph->adjList[dst] = node;

}

void printGraph(struct Graph* graph){
    for(int i=1; i <= graph->numVertices; i++){
        struct Node* first = graph->adjList[i];

        while(first!=NULL){
            printf("%d ", first->data);
            first = first->next;
        }

        printf("\n");
    }
}

int main(){

    struct Graph* g1 = createGraph(5);
    addEdge(g1, 5, 1);
    addEdge(g1, 1, 2);
    addEdge(g1, 3, 1);
    addEdge(g1, 4, 2);
    addEdge(g1, 2, 3);

    printGraph(g1);
    
}