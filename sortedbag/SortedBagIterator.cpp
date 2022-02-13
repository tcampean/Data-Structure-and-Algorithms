#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->position = 0;
	this->count = 1;
	this->sum = 0;

}
//Theta(1)

TComp SortedBagIterator::getCurrent() {
    if(!this->valid()){
        throw exception();
    }
    return this->bag.objects[this->position];
}
//Theta(1)

bool SortedBagIterator::valid() {
	if(this->position < this->bag.length)
	    return true;
	return false;
}
//Theta(1)

void SortedBagIterator::next() {
	if(!this->valid()){
	    throw exception();
	}
	else
    {
	    this->sum = this->bag.frequency[this->position];
	    if(this->count< this->sum)
	        this->count++;
	    else{
	        this->position++;
	        this->count=1;
	    }
    }

}
//Theta(1)
void SortedBagIterator::first() {
	this->position = 0;
}
//Theta(1)
