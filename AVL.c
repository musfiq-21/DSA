#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)(malloc(sizeof(struct Node)));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    
    return node;
}

int max(int a, int b){
    return a>b?a:b;
}

int getHeight(struct Node* node){
    if(node==NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(struct Node* node){
    if(node == NULL)
        return 0;
    
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* rightRotation(struct Node* root){

    struct Node* leftChild = root->left;
    struct Node* lr = leftChild->right;

    leftChild->right = root;
    root->left = lr;

    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right))+1;

    return leftChild;
}

struct Node* leftRotation(struct Node* root){
    struct Node* rightChild = root->right;
    struct Node* rl = rightChild->left;

    rightChild->left = root;
    root->right = rl;

    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right))+1;
    
    return rightChild;
}

struct Node* insert(struct Node* root, int value){
    if(root==NULL)
        return createNode(value);
    
    if(value < root->value)
        root->left = insert(root->left, value);
    else if(value > root->value)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);

    if(balance > 1 && value < root->left->value){
        return rightRotation(root);
    }

    if(balance < -1 && value > root->right->value)
        return leftRotation(root);

    if(balance > 1 && value > root->left->value){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if(balance < -1 && value < root->right->value){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
    
    
}

void postOrder(struct Node* root){
    if(root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
    
}

void preOrder(struct Node* root){
    if(root == NULL)
        return;

    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    struct Node* root = createNode(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    
    postOrder(root);


}

