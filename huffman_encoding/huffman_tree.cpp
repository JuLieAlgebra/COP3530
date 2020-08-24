#include "huffman_tree.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo> 


/*
void print_map(std::unordered_map<char,std::string> const &m)
{

	std::cout << "this is the map " <<  std::endl;
  	for ( auto it = m.begin(); it != m.end(); ++it )
    	std::cout << " " << it->first << ":" << it->second << std::endl;
}

void print_map(std::unordered_map<char,int> const &m)
{

	std::cout << "this is the freq " <<  std::endl;
  	for ( auto it = m.begin(); it != m.end(); ++it )
    	std::cout << " " << it->first << ":" << it->second << std::endl;
}

*/
struct huffman_tree::Node
{
    char ch;
    int freq;
    Node *left, *right;
};


huffman_tree::Node* huffman_tree::getNode(char ch, int freq, Node* left, Node* right)
{
    huffman_tree::Node* node = new huffman_tree::Node();

    node->ch = ch;
    node->freq = freq;
    node->right = right;
    node->left = left;

    return node;
}

struct huffman_tree::comp
{
    bool operator()(huffman_tree::Node* one, huffman_tree::Node* two)
    {
        
        return one->freq > two->freq;
    }
};

void huffman_tree::build_encode(huffman_tree::Node* root, std::string str)
{
    if (root == nullptr)
        return;

    
    if (!root->left && !root->right) {
        huffman_tree::map[root->ch] = str;
    }

    build_encode(root->left, str + "0");
    build_encode(root->right, str + "1");
}

void huffman_tree::setRoot(Node* root){
	huffman_tree::root = root;
}

huffman_tree::Node* huffman_tree::getRoot() const{
	return huffman_tree::root;
}

/*
Preconditions: file_name is the name of (and possibly path to) a text file
Postconditions: Reads the contents of file_name and constructs a
                huffman tree based on the character frequencies of the file contents
*/
huffman_tree::huffman_tree(const std::string &file_name){
    std::ifstream ifs(file_name);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    //std::cout << "Content from file: " << content << std::endl;
    std::unordered_map<char, int> freq;
    for (char ch: content) {
        freq[ch]++;
    }
    //print_map(freq);
    std::priority_queue<huffman_tree::Node*, std::vector<huffman_tree::Node*>, comp> priorityq;
    for (auto pair: freq) {
        priorityq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (priorityq.size() != 1)
    {
        
        huffman_tree::Node *left = priorityq.top(); 
        priorityq.pop();
        huffman_tree::Node *right = priorityq.top(); 
        priorityq.pop();

        int sum = left->freq + right->freq;
        priorityq.push(getNode('\0', sum, left, right));
        
    }
    huffman_tree::Node* root = priorityq.top();
    if(!root->left && !root->right){
        huffman_tree::Node* tmp = new huffman_tree::Node();
        tmp->ch = root->ch;
        tmp->left = 0;
        tmp->right = 0;
        tmp->freq = root->freq;

        root->right = 0;
        root->left = tmp;
        
    }

    build_encode(root, "");
    
    huffman_tree::setRoot(root);
    huffman_tree::file = content;

}

huffman_tree::~huffman_tree(){

}

/*
Preconditions: Character is a character with an ASCII value
                between 0 and 127 (inclusive).
Postconditions: Returns the Huffman code for character if character is in the tree
                and an empty string otherwise.
*/
std::string huffman_tree::get_character_code(char character) const {
    if(huffman_tree::map.find(character) == huffman_tree::map.end()){
    	return "";
    }

    std::string val = huffman_tree::map.at(character);

    return val;
}

/*
Preconditions: file_name is the name of (and possibly path to) a text file
Postconditions: Returns the Huffman encoding for the contents of file_name
                if file name exists and an empty string otherwise.
                If the file contains letters not present in the huffman_tree,
                return an empty string
*/
std::string huffman_tree::encode(const std::string &file_name) const {
	std::ifstream ifs(file_name);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

    if(file_name == "")
        return "";

    if(content == "")
        return "";

    std::string encoded = "";
    for(int i = 0; i < content.size(); i++){
        
        std::string add = huffman_tree::get_character_code(content[i]);
        
        if(add == "")
            return "";
        encoded = encoded + add;
    }
    return encoded;
}


std::string huffman_tree::it_decode(huffman_tree::Node* root, std::string str) const{
    huffman_tree::Node* curr = root;
    std::string decoded_str = "";
    for(int i = 0; i < str.size(); i++){
		if(str[i]!= '0' && str[i] != '1')
			return "";

        if (str[i] == '0') 
           curr = curr->left; 
        else
           curr = curr->right; 

        if (curr->left==nullptr && curr->right==nullptr) 
        { 
            decoded_str += curr->ch; 
            curr = root; 
        } 
    }
    return decoded_str;
}


/*
Preconditions: string_to_decode is a string containing Huffman-encoded text
Postconditions: Returns the plaintext represented by the string if the string
                is a valid Huffman encoding and an empty string otherwise
*/
std::string huffman_tree::decode(const std::string &string_to_decode) const {
    if(string_to_decode == "")
    	return "";

    std::string decoded = "";
	huffman_tree::Node* root = huffman_tree::getRoot();
    
    return it_decode(root, string_to_decode);
}
