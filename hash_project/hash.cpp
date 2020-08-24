#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
// Compile with:
// g++ hash.cpp -std=c++11 -o hash


//////////////////////////////////////////////////
void printvec(std::vector<int> vec){
    for (auto i: vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

struct node{
    int key;
    node *next;
    node *tail;
};  

struct collision_table{
    int collisions;
    std::vector<node*> vec_node;
    std::vector<int> vec_int;
};  

void printnode(std::vector<node*> vec){
    for (auto i: vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

double random_uniform() {
    static std::default_random_engine random_engine(std::time(0));
    static std::uniform_real_distribution<double> uniform(0.0, 1.0);
    return uniform(random_engine);
}

int mod_hash(int key, int size){
    //returns index of where the key should be inserted in
    // the hash table
    return key%size;
}

int mid_hash(int key, int size){
    int index = key*key;
    index = index%10; //removes one digit
    index = index%size; // removes the other
    return index;
}

/// THIS IS FOR SEPARATE
collision_table* open_collision(std::vector<int> vec, int index, int key, int collisions){
    // need to increase load factor, increase collisions outside of this func
    int size = vec.size(); 
    if(vec[index] != -1)
        collisions++;
    while(vec[index] != -1){
        if(index == size-1){ // looping back to the start
            index = 0;
        }
        else{
            index++;
        }
    }

    vec[index] = key;
    collision_table* table = new collision_table();
    table->collisions = collisions;
    table->vec_int = vec;
    return table;
};

collision_table* chain_collision(std::vector<node*> vec, int index, int key, int collisions){
    // need to increase load factor, increase collisions outside of this func
    if(vec[index] == nullptr){
        node* tmp = new node();
        vec[index] = tmp;
        vec[index]->key = key;

        node* next = new node();
        vec[index]->next = next;
        vec[index]->tail = next;
    }
    else{
        collisions++;
        node* next = new node();
        vec[index]->tail->key = key;
        vec[index]->tail->next = next;
        vec[index]->tail = next;
    }
    collision_table* table = new collision_table();
    table->collisions = collisions;
    table->vec_node = vec;
    return table; 
}

void record_data(std::string filename, int collisions_record[], int load_record[], int size) {
    std::ofstream stream;
    stream.open(filename);
    for(uint i=0; i<size; ++i) {
        stream << (load_record[i]/float(size)) << ',' << collisions_record[i] << std::endl;
    }
}


//////////////////////////////////////////////////

int main(){
    int const size = 480;

    int collisions = 0;
    int collisions_record[size];

    int load = 0;
    int load_record1[size];

    std::vector<node*> vec(size);
    
    // doing the separate chaining first
    // and the hash function mod table
    int i = 0;
    while(load < size){
        int key = (int) 3*size*random_uniform();
        int index = mod_hash(key, size);
        
        collision_table* table;
        table = chain_collision(vec, index, key, collisions);
        vec = table->vec_node;
        collisions = table->collisions;
        
        load++;
        collisions_record[i] = collisions;
        load_record1[i] = load;
        i++;
    }
    //std::cout << load << std::endl;
    //printnode(vec);



    
    ///// separate chaining with mid square
    collisions = 0;
    std::vector<node*> vec1(size);
    //std::cout << key << std::endl;
    load = 0;
    i = 0;
    int load_record2[size];
    int collisions_record2[size];
    // doing the separate chaining first
    // and the hash function mod table
    while(load < size){
        int key = (int) 3*size*random_uniform();
        int index = mid_hash(key, size);

        collision_table* table;
        table = chain_collision(vec1, index, key,collisions);
        vec1 = table->vec_node;
        collisions = table->collisions;

        load++;
        collisions_record2[i] = collisions;
        load_record2[i] = load;
        i++;
    }
    //std::cout << load << std::endl;
    //printnode(vec1);
    


    ///// open addressing with mid square
    collisions = 0;
    std::vector<int> vec2(size,-1);
    //std::cout << key << std::endl;
    load = 0;
    i = 0;
    int load_record3[size];
    int collisions_record3[size];
    while(load < size){
        int key = (int) 3*size*random_uniform();
        int index = mid_hash(key, size);

        collision_table* table;
        table = open_collision(vec2, index, key, collisions);
        vec2 = table->vec_int;
        collisions = table->collisions;

        load++;
        collisions_record3[i] = collisions;
        load_record3[i] = load;
        i++;
    }
    //std::cout << load << std::endl;
    //printvec(vec2);



    ///// open addressing with mod hashing
    collisions = 0;
    std::vector<int> vec3(size,-1);
    //std::cout << key << std::endl;
    load = 0;
    i = 0;
    int load_record4[size];
    int collisions_record4[size];
    //std::cout <<"in fourth one " << std::endl;
    while(load < size){
        int key = (int) 3*size*random_uniform();
        //std::cout << "key"<< key << std::endl;
        int index = mod_hash(key, size);
        collision_table* table;
        table = open_collision(vec3, index, key, collisions);
        vec3 = table->vec_int;
        collisions = table->collisions;
        
        load++;        
        collisions_record4[i] = collisions;
        load_record4[i] = load;
        //std::cout << "hey" << std::endl;
        i++;
    }
    //std::cout << "heyyy" << std::endl;
    record_data("hashrecord.txt", collisions_record, load_record1, size);
    record_data("hashrecord2.txt", collisions_record2,load_record2,size);
    record_data("hashrecord3.txt", collisions_record3, load_record3, size);
    record_data("hashrecord4.txt", collisions_record4,load_record4,size);
    return 0;
}