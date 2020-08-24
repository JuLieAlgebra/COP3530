#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next = NULL;
};

int find(Node* node, int valueInput)
{
    int index = 0;
    while(node->next != NULL){
        if(node == NULL){
            cout<<"hi"<<endl;
            return -1;
        }
        if(node->value == valueInput){
            cout<<"foundit"<<endl;
            return index;  
        }
        index++;
        node = node->next;
    }
    //your code here
}

int main()
{
    int valueInput, currentValue; 
    int listValues;
    char junk;
    Node *node1, *node2, *node3;
    std::cin >> valueInput;
    std::cin >> currentValue;
    node1 = new Node();
    node2 = new Node();
    node3 = new Node();
    node1->value = currentValue;
    node1->next = node2;
    std::cin >> junk;
    std::cin >> junk;
    std::cin >> currentValue;
    node2->value = currentValue;
    node2->next = node3;
    std::cin >> junk;
    std::cin >> junk;
    std::cin >> currentValue;
    node3->value = currentValue;
    std::cout << find(node1, valueInput);

    delete node1;
    delete node2;
    delete node3;

}