#ifndef BLOOM_H
#define BLOOM_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>
#include <cstring>
using namespace std;


#define TABLE_SIZE 8000000
// size of table to hold the hashes for the dictionary
#define NUM_HASHES 12
// number of times murmurHash2 is called with different seeds
// (produces 12 different hashes)


class Bloom{
    
    private:
    bitset<TABLE_SIZE> hashTable;
    // a set of 800000 bits to correspond to the hashes of words
    
    public:
    Bloom(){
        bitset<TABLE_SIZE> hashTable;
    }
    unsigned int MurmurHash2(const void * key, int len, unsigned int seed);
    bool is_in(string key);
    void insert(string key);
    
};


#endif
