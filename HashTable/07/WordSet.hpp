#ifndef __WORD_SET_P4__HPP
#define __WORD_SET_P4__HPP
 
const int SIZES[] = { 11, 23, 41, 83, 163, 331, 641, 1283, 2579, 5147, 10243, 20483, 40961, 81929, 163847};
 
#include <string>
 
int hashFunction(std::string s, int base, int mod);
 
class WordSet
{
public:
	WordSet();
	~WordSet();
 
	void insert(std::string s);
 
	bool contains(std::string s) const;
 
	// return how many distinct strings are in the set
	int getCount() const;
 
	// return how large the underlying array is.
	int getCapacity() const;
 
private:
	std::string* wordArray; //underlying array
	int capacity; //total capacity of underlying array
	int wordNum; //number of words in table
	int sizesTracker; //tracks which part of SIZES array is currently being used
};
 
#endif

