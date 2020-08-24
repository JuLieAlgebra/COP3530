#include <iostream>
#include <string>
#include <cstddef>
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


int countLeaves(Node* head)
{
    if(head->left == 0 && head->right == 0)
        return 1;
    if(head->left == 0)
        return countLeaves(head->right);
    if(head->right == 0)
        return countLeaves(head->left);
    return countLeaves(head->left) + countLeaves(head->right);
}


int main()
{
    Node* root=NULL;
    int x;
    int num;
    num = 10;
    int nums[10] = {9,4,10,11,6,1,3,7,5,8};
    for(int i=0;i<num;i++)
    {
         x = nums[i];

        root=insert(root,x);

    }


    std::cout << countLeaves(root);
}