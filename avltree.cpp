#include <iostream>
#include <string>

class Node
{
    public:
        int name;
        Node* left = NULL;
        Node* right = NULL;
};

Node* insert(Node* root, int key)
{
    if(root==NULL)
    {
        Node* temp=new Node();
        temp->name=key;
        return temp;
    }
    if (key < root->name)
        root->left  = insert(root->left, key);
    else if (key > root->name)
        root->right = insert(root->right, key);   

    return root;
}

std::string traverse(Node* head)
{
    std::string string1, string2, string3;

    if (head == NULL)
        return "";

    string1 = traverse(head->left);
    string2 = std::to_string(head->name);
    string3 = traverse(head->right);


    return string1 + " " + string2 + " " + string3;
}

int height(Node* head)
{
     if (head == NULL):
        return -1;
     if ((head->left == NULL) && (head->right == NULL))
        return 0;

     int heightLeft = 0;
     int heightRight = 0;

     if (head->left != NULL)
            heightLeft = height(head->left);
     if (head->right != NULL)
             heightRight = height(head->right);

     if (heightLeft>heightRight)
        return 1+heightLeft;
    else
        return 1+heightRight;

}


Node* rotateLeft(Node *node)
{
    Node* tmp;
    //your code here
}
Node* rotateRight(Node *node)
{
    
    Node* tmp;
    // copy of B
    tmp->left = (*node->left->left);
    tmp->right = (*node->left->right);
    // dealing with C
    *node->left = (*node->left->right);
    // dealing with B
    tmp->left->right = node;
    Node* ptr = *(tmp->left);
    return ptr;
    
}

Node* rotateRightLeft(Node *parent)
{
    if(parent == nullptr || parent->right == nullptr)
        return nullptr;
    
    Node* tmp = new Node(); // copy of z
    Node* newZ = new Node(); // the new z
    Node* newY = new Node();
    Node* newX = new Node();

    tmp->name = parent-> name;
    newZ->name = parent->name;
    newY->name = parent->right->name;
    
    if(parent->right->left != nullptr)
        newX->name = parent->right->left->name;
    if(parent->left != nullptr){
        tmp->left = parent->left;
        newZ->left = parent->left;
    }
    tmp->right = parent->right;
    
    if( ((parent->right)->left)->left != nullptr){
        newZ->right = ((parent->right)->left)->left;
    }   
    std::cout<<"hey"<<newX->name<<std::endl;
    newX->left = newZ;
    newX->right = newY;
    if( parent->right->left != nullptr){
        if(parent->right->left->right != nullptr){
        newY->left = parent->right->left->right; 
        }
    }
    
    if(parent->right->right != nullptr)
        newY->right = parent->right->right;
    return newX;
 
}

int main()
{
    Node* root=NULL;
    int x;
    int num;
    int arr[] = {10,20,15};
    root=insert(root,arr[0]);
    root=insert(root,arr[1]);
    root=insert(root,arr[2]);
    root=rotateRightLeft(root);
    std::cout << traverse(root) << std::endl;
    std::cout << height(root);
}
