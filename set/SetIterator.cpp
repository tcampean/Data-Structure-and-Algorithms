#include "SetIterator.h"
#include "Set.h"
#include <exception>

using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->currentNode = this->set.head;
}
//Theta(1)

void SetIterator::first() {
	this->currentNode = this->set.head;
}
//Theta(1)

void SetIterator::next() {
    if(this->currentNode== nullptr)
        throw exception();
    this->currentNode = this->currentNode->next;
}
//Theta(1)

TElem SetIterator::getCurrent()
{
	if(this->currentNode== nullptr)
        throw exception();
	TElem e = this->currentNode->data;
	return e;
}
//Theta(1)
bool SetIterator::valid() const {
	if(this->currentNode == nullptr)
	    return false;
	else
	    return true;
}
//Theta(1)



