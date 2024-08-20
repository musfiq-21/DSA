#include<stdio.h>

#define MAXSIZE 100 //atmost 100 ta node store krbe
int matrix[MAXSIZE][MAXSIZE];
int start[MAXSIZE], end[MAXSIZE];
int topology[MAXSIZE];
int size=MAXSIZE;   //global krlm ta nahle dfs function a bar bar pass krte hbe
int visited[100];
int t=1;    //time

void dfs(int startPos){

    start[startPos]=t++;
    visited[startPos]=1;
    for(int j=0; j<size; j++){
        if(matrix[startPos][j]==1 && visited[j]==0){
            dfs(j);
        }
    }
    end[startPos]=t++;
}

int main(){
    int v;
    printf("Enter number of vertices and number of nodes: ");
    scanf("%d %d", &v, &size);

    for(int i=0; i<size; i++){
        visited[i]=0;
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            matrix[i][j]=0;
    }
    while(v--){
        int from, to;
        scanf("%d%d", &from, &to);

        matrix[from-1][to-1]=1;     //1 minus krlm cz indexing (0, size-1) theke krle easier
    }

    printf("Enter starting position of dfs: ");
    int pos;
    scanf("%d", &pos);

    dfs(pos-1);     //user (1-size) input dibe, 1 minus krte hbe amdr cz index(0-size-1)
    printf("      ");
    for(int i=1; i<=size; i++)
        printf("%d ", i);
    printf("\nstart:");
    for(int i=0; i<size; i++){
        printf("%d ", start[i]);
    }
    printf("\nend:");
    for(int i=0; i<size; i++){
        printf("%d ", end[i]);
    }
    printf("\n");
}