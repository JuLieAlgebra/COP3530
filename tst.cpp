#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;

    unsigned isEndOfString: 1;
    struct Node *left, *eq, *right;
};

struct Node* newNode(char data){
    Node* tmp;
    tmp->data = data;
    tmp->isEndOfString = 0;
    tmp->left = tmp->right = tmp->eq = NULL;
    return tmp;
};

int main(){
    
    return 0;
}