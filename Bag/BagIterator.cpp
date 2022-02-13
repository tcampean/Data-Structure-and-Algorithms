#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->currentPosition = 0;
	while(this->currentPosition < bag.m && bag.T[this->currentPosition]== nullptr)
	    this->currentPosition++;
	if(this->currentPosition<bag.m)
	    this->currentNode = bag.T[this->currentPosition];
	else
	    this->currentNode = nullptr;
	this->total = 0;
	this->count = 1;
}
//Best case: Theta(1) when the the first slot of the hash table is not null
//Worst case: Theta(m) when the first non-null slot of the hash table is the last slot
//Total complexity: O(m)

void BagIterator::first() {
    this->currentPosition = 0;
    while(this->currentPosition < bag.m && bag.T[this->currentPosition]== nullptr)
        this->currentPosition++;
    if(this->currentPosition<bag.m)
        this->currentNode = bag.T[this->currentPosition];
    else
        this->currentNode = nullptr;

}
//Best case: Theta(1) when the the first slot of the hash table is not null
//Worst case: Theta(m) when the first non-null slot of the hash table is the last slot
//Total complexity: O(m)

void BagIterator::next() {
	if(!this->valid())
	    throw exception();
	else
    {
	    this->total = this->currentNode->key.second;
	    if(this->count <this->total)
	        this->count++;
	    else{
            if(this->currentNode->next != nullptr)
                this->currentNode = this->currentNode->next;
            else{
                this->currentPosition++;
                while(this->currentPosition < bag.m && bag.T[this->currentPosition]== nullptr)
                    this->currentPosition++;
                if(this->currentPosition<bag.m)
                    this->currentNode = bag.T[this->currentPosition];
                else
                    this->currentNode = nullptr;
            }
            this->count=1;
	    }
    }
}
//Best case: Theta(1) if the next node from the current element is not null
//Worst case: Theta(m) if the current node is on the first slot and the next non-null node is on the last slot of the table
//Total complexity: O(m)

bool BagIterator::valid() const {
    if(this->currentPosition == bag.m && this->currentNode == nullptr)
        return false;
    return true;
}
//Theta(1)



TElem BagIterator::getCurrent() const
{
    if(!this->valid())
        throw exception();
	return this->currentNode->key.first;
}
//Theta(1)
