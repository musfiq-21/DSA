#include<stdio.h>
#include<stdlib.h>

struct graph{
    int numVertices;
    int adjMatrix[101][101];    //will support at most 100 vertices
};

struct graph* createGraph(int numVertices){
    struct graph* graph = (struct graph*)(malloc(sizeof(struct graph)));

    if(graph == NULL){
        return NULL;
    }
    graph->numVertices=numVertices;

    for(int i=1; i<=numVertices; i++){
        for(int j=1; j<=numVertices; j++){
            graph->adjMatrix[i][j]=0;
        }
    }
    
    return graph;
}

void addEdge(struct graph* graph, int src, int dst){
    
    graph->adjMatrix[src][dst] = 1;
    graph->adjMatrix[dst][src] = 1;
}

void printGraph(struct graph* graph){
    for(int i=1; i<=graph->numVertices; i++){
        for(int j=1; j<=graph->numVertices; j++)
            printf("%d ", graph->adjMatrix[i][j]);
        printf("\n");
    }
}

int main(){
    struct graph* g1 = createGraph(5);
    addEdge(g1, 2, 3);
    addEdge(g1, 1, 2);
    addEdge(g1, 4, 1);
    addEdge(g1, 2, 4);
    addEdge(g1, 2, 5);

    printGraph(g1);
}