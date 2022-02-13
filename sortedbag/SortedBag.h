#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111;

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;

private:
	//Representation
	TComp* objects;
	TComp* frequency;
	int length;
	int capacity;
	Relation relation;

private:
    //Extra functions

    //Insertion sort on the arrays of the sorted bag
    void sort();

    //resizes the arrays of the sorted bag
    void resize();

public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurrence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appears is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//Adds a given amount of occurrences of an existing elements
	//or adds a new element with the number of occurrences
    void addOccurrences(int nr, TComp elem);

	//destructor
	~SortedBag();
};