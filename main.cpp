#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "bloom.h"


// Takes a file to check and a dictionary to build the filter with:
// usage is: ./spell_check <file_to_check> <dictionary_to_use>
int main(int argc, char** argv){
    // Using murmurHash2 with 12 different seed values
    if (argc != 3){
        fprintf(stderr,"Error: usage is './spell_check <file_to_check> <dictionary_to_use>' \n");
        exit(EXIT_FAILURE);
    }
    
    
    // load the dictionary into the bitset (hashMap)
    Bloom mybloom;
    std::string word;
    //std::ifstream infile("dictionary.txt");
    std::ifstream infile(argv[2]);
    
    while (getline(infile,word)){
        // this is getting all the words from the dictionary and setting the 
        // corresponding indices from each hash to true
        mybloom.insert(word);
    }
    infile.close();
    // close dictionary
    
    //std::ifstream itfile("testWords.txt");
    std::ifstream itfile(argv[1]);
    // load test words and "check spelling"
    std::string test_word;
    while (getline(itfile, test_word)){
        if (mybloom.is_in(test_word)){
            std::cout << test_word << " is in the dictionary." << std::endl;
        } else {
            std::cout << test_word << " is NOT in the dictionary." << std::endl;
        }
    }
    itfile.close(); 
    
    
    return 0;
}