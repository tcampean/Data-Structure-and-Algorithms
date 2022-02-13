#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){

    this->posKey = 0;
    this->posValue = 0;

}
//Theta(1)

void SMMIterator::first() {
    if (this->map.tree->root != -1) {
        this->posKey = 0;
        this->posValue = 0;
    }
}
//Theta(1)

void SMMIterator::next(){
    if(!this->valid())
        throw exception();
    else
    {
        if(this->posValue < this->map.tree->keyValues[this->posKey].count-1)
            this->posValue++;
        else
        {
            this->posKey++;
            this->posValue = 0;

        }
    }

}
//Theta(1)


bool SMMIterator::valid() const{
    if(this->posKey>= this->map.count )
        return false;
    return true;
}
//Theta(1)

TElem SMMIterator::getCurrent() const{
    if(!this->valid())
        throw exception();
    else {
        TElem pair;
        pair.first = this->map.tree->key[this->posKey];
        pair.second = this->map.tree->keyValues[this->posKey].values[this->posValue];
        return pair;
    }
}
//Theta(1)


