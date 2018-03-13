#include <cstdlib>
#include <string>
#include <bitset>
#include "bloom.h" 



// a bloom filter is created as a bitset with TABLE_SIZE number of bits

void Bloom::insert(std::string key){
    unsigned int seed = 5;
    for (int i = 0; i < NUM_HASHES; i++){
        unsigned int hash = MurmurHash2(&*key.begin(), key.length(), seed);
        hashTable.set(hash,true);
        seed = seed * seed;
    }
}


bool Bloom::is_in(std::string key){
    unsigned int seed = 5;
    for (int i = 0; i < NUM_HASHES; i++){
        unsigned int hash = MurmurHash2(&*key.begin(), key.length(), seed);
        if (hashTable[hash] != 1){
            return false;
        }
        seed = seed * seed;
    }
    return true;
}


//***************************** HASH FUNCTIONS *********************************


//-----------------------------------------------------------------------------
// MurmurHash2, by Austin Appleby

unsigned int Bloom::MurmurHash2 (const void * key, int len, unsigned int seed )
{
	const unsigned int m = 0x5bd1e995;
	const int r = 24;
	unsigned int h = seed ^ len;
	const unsigned char * data = (const unsigned char *)key;
	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;
		k *= m; 
		k ^= k >> r; 
		k *= m; 
		h *= m; 
		h ^= k;
		data += 4;
		len -= 4;
	}
	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return h % TABLE_SIZE;
} 



