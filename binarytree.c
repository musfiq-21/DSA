#include<stdio.h>
#include<stdlib.h>

int binaryArray[1000005]={0};

void add(int root, int value){
    if(binaryArray[root] == NULL){
        binaryArray[root] = value;
        return;
    }

    if(binaryArray[root]>=value)
        add(2*root+1, value);
    else
        add(2*root + 2, value);
}

void preOrder(int root){
    if(binaryArray[root] == NULL)
        return;
    
    printf("%d ", binaryArray[root]);
    preOrder(2*root+1);
    preOrder(2*root+2);
}

void inOrder(int root){
    if(binaryArray[root] == NULL)
        return;
    
    inOrder(2*root+1);
    printf("%d ", binaryArray[root]);
    inOrder(2*root+2);
}

void postOrder(int root){
    if(binaryArray[root] == NULL)
        return;
    
    postOrder(2*root+1);
    postOrder(2*root+2);
    printf("%d ", binaryArray[root]);

}

int main(){
    add(0, 20);
    add(0, 10);
    add(0, 30);
    add(0, 5);
    add(0, 15);
    add(0, 25);
    add(0, 35);

    preOrder(0);
    printf("\n");

    inOrder(0);
    printf("\n");
    postOrder(0);
    printf("\n");
}
