This is a simple bloom filter program which functions as a spell checker.

The spell checker performs hashes of known words from a dictionary and sets the bit at the resulting index of each hash 
to '1'. After all bits from hashing the dictionary have been set, the dictionary has been effectively "loaded" into the 
filter. 

Once the dictionary is loaded, the program reads a txt file containing the words to be checked. If each hash of a checked 
word results in a bitset index with the bit set to '1', then the word is in the dictionary with very high probability (and 
thus is considered spelled correctly). If any the hashes result in an index with a bit set to '0', the word is considered 
mis-spelled. 

To run, use the included makefile (enter 'make' command in project directory)
Usage is: ./spell_check <file_to_check> <dictionary_to_use>
