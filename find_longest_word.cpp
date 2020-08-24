#include <iostream>
using String = std::string;


String find_longest_word(String sentence);
bool is_letter(uint c);


int main(int argc, char** argv) {
    std::cout << find_longest_word(gets(stdin));
    return 0;
}


String find_longest_word(String sentence) {
    sentence += '.';
    String current = "";
    String longest = "";
    for(char const c : sentence) {
        if(is_letter(c)) {
            current += c;
        } else {
            if(current.size() > longest.size()) {
                longest = current;
            }
            current = "";
        }
    }
    return longest;
}


bool is_letter(uint c) {
    return ((65 <= c) and (c <= 90)) or ((97 <= c) and (c <= 122));
}
