#include <iostream>

class Node {
    public:
        int value;
        Node* next = NULL;
};

Node* add(Node* head, int index, int valueInput)
{
    Node* current = head;
    
    // this also handles if head is null
    if(index == 0){
        Node* tmp = new Node;
        tmp->next = head;
        tmp->value = valueInput;
        return tmp;
    }
    int i = 0;
    while(i <= (index-1)&& current->next != NULL){
        current = current->next;
        i++;
    }
    if(i = (index-1)){
        Node* tmp = new Node;
        tmp->next = current->next;
        tmp->value = valueInput;
        current->next = tmp;
        return head;
    }
    if(current->next == NULL){
        // we have traversed the whole linked list and didn't find the index to insert, so we should return null
        return NULL;
    }
};

int main()
{
    int valueInput, currentValue, index;
    Node* result; 
    int listValues;
    char bleh;
    Node *node1, *node2, *node3, *node4;
    std::cin >> valueInput;
    std::cin >> index;
    std::cin >> currentValue;
    std::cin >> bleh;
    std::cin >> bleh;
    node1 = new Node();
    node2 = new Node();
    node3 = new Node();
    node4 = new Node();

    node1->value = currentValue;
    node1->next = node2;
    std::cin >> currentValue;
    std::cin >> bleh;
    std::cin >> bleh;
    node2->value = currentValue;
    node2->next = node3;
    std::cin >> currentValue;
    std::cin >> bleh;
    std::cin >> bleh;
    node3->value = currentValue;
    std::cin >> currentValue;
    std::cin >> bleh;
    std::cin >> bleh;
    node4->value = currentValue;
    node3->next = node4;

    result = add(node1, index, valueInput);
    Node* current;
    if (result == NULL)
        std::cout << "NULL";
    else
    {
        current = result;
        while (current->next != NULL)
        {
            std::cout << current->value;
            std::cout << "->";
            current = current->next;
        }
        std::cout << current->value;
    }



    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
};

/**

    int i = 0;
    while(i != (index)){ // think about this
         
        // if index is "out of bounds", then we will have reached the end of the linked list and now need to return NULL
        // since we did not find the index in the list
        if(current->next == NULL){
    
            return NULL;
        }
             
        // we want to keep moving forward
        current = current->next;
        // keeps track of the index we're currently on
        i++;
        if(i == (index-1)){
            // now i = index-1, so this is the node that we want to insert after
            // create a new node for our information/insert
            Node* tmp = new Node;
            tmp->value = valueInput;
            // updating our inserted node's pointers
            tmp->next = current->next;
            current->next = tmp;
            //return tmp;
            return head;
        }
    }
    **/
