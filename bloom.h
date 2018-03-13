#ifndef BLOOM_H
#define BLOOM_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>


#define TABLE_SIZE 8000000
// size of table to hold the hashes for the dictionary
#define NUM_HASHES 12
// number of times murmurHash2 is called with different seeds
// (produces NUM_HASHES different hashes)


class Bloom{
    
    private:
    std::bitset<TABLE_SIZE> hashTable;
    // a set of 800000 bits to correspond to the hashes of words
    
    public:
    Bloom(){
        std::bitset<TABLE_SIZE> hashTable;
    }
    unsigned int MurmurHash2(const void * key, int len, unsigned int seed);
    bool is_in(std::string key);
    void insert(std::string key);
    
};


#endif