# bloom-filter-spell-check
Repository for a simple spell checker program implemented with a bloom filter.

This hashes a bunch of words loaded from a dictionary with multiple hashes per word by using different seeds. The resulting index from the hash is set to 1 in a large bitset. Once the dictionary is loaded, the bloom filter can be used a spell checker. A word can be passed in and hashed multiple times. If each hash index results in a bit previously set to 1, then there is an extremely high likelihood the word was in the dictionary. This is a way to spell check that exchanges 100% reliability for performance. But if the hash function is good enough and the bitset is sufficiently large, for all practical purposes the spell checker will be correct.
