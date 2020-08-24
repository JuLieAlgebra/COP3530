#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_
#endif

#include <iostream>
#include <unordered_map>

class huffman_tree {

	public:
		huffman_tree(const std::string &file_name);
		~huffman_tree();

        ////// variables ////////////////////
        huffman_tree::Node* root; // root of the hufftree
        std::unordered_map<char, std::string> map; //huffman Codes
        std::string file; // the content to be encoded
        //////////////////////////////////////


        struct comp; // comparing nodes

        struct Node;  // elements of the hufftree
        Node* getRoot() const; //utility
        void setRoot(Node* root); //utility
        Node* getNode(char ch, int freq, Node* left, Node* right); //creates new node


        ///// helper functions ////////////////////
        void build_encode(Node* root, std::string str);
		std::string it_decode(huffman_tree::Node* root, std::string str) const;
        ////////////////////////////////////////////
        
        std::string get_character_code(char character) const;
		std::string encode(const std::string &file_name) const;
		std::string decode(const std::string &string_to_decode) const;	
};

//#endif