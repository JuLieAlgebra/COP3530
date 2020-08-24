#include <list>   
#include <iostream>

int findInList(std::list<int> &myList, int valueToFind)
{
    std::list<int>::iterator i;
    for( i = myList.begin(); i != myList.end(); i++){
        if( *i == valueToFind){
            std::cout << "in find list " << *i << std::endl;
            return i->;
        }
    }
}

int main(){
    std::list<int> l = { 7, 5, 16, 8 };
    std::cout << findInList(l,5) << std::endl;
    return 0;
}