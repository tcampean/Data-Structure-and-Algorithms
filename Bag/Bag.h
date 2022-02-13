#pragma once
#include <utility>
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
typedef int TFunction;
typedef int TFrequency;
typedef std::pair<TElem,TFrequency> TPair;
class BagIterator;


struct Node
{
    TPair key;
    Node *next;

};
class Bag {

private:
	Node **T;
	int m;
	int amount;

	//DO NOT CHANGE THIS PART
	friend class BagIterator;

private:
    void resize();

public:
	//constructor
	Bag();

	//Hash function
    TFunction h(TElem a) const
    {
        if(a<0)
            a = a - 2*a;
        return a % m;
    }
    //Best case = Worst case = Theta(1)


    int minFrequency() const;
	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};