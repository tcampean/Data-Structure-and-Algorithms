#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	this->currentElement = this->map.head;
}
//Theta(1)


void MapIterator::first() {
	this->currentElement = this->map.head;
}
//Theta(1)


void MapIterator::next() {
    if(this->currentElement==-1)
        throw exception();
	this->currentElement = this->map.next[currentElement];
}
//Theta(1)

TElem MapIterator::getCurrent(){
    if(this->currentElement==-1)
        throw exception();
	return this->map.elems[this->currentElement];
}
//Theta(1)


bool MapIterator::valid() const {
    if(this->currentElement==-1)
        return false;
	return true;
}
//Theta(1)


