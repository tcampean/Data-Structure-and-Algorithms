#include "Set.h"
#include "SetITerator.h"
#include <cstdlib>

Set::Set() {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}
//Theta(1)

bool Set::add(TElem elem) {
	node *new_node = new node;
	new_node->data = elem;
	new_node->next = nullptr;
	if(search(elem))
	    return false;
	if(this->head == nullptr)
    {
	    this->head = new_node;
	    this->tail = new_node;
	    this->length++;
	    return true;
    }
	else
    {
	    this->tail->next = new_node;
	    this->tail = this->tail->next;
	    this->length++;
	    return true;
    }
}
//Best case:Theta(1): When the element already exists in the set and it is on the first position
//Worst case:Theta(n): When the element doesn't exist in the list and we have to add them
// =>Total complexity: O(n)


bool Set::remove(TElem elem) {
	if(!search(elem))
	    return false;
	node *currentNode,*prevNode;
	currentNode = this->head;
	prevNode = nullptr;
	while(currentNode != nullptr && currentNode->data != elem)
    {
	    prevNode = currentNode;
	    currentNode = currentNode->next;
    }
	if(currentNode != nullptr && prevNode == nullptr)
	    this->head = this->head->next;
	else if(currentNode != nullptr)
    {
	    prevNode->next = currentNode->next;
	    currentNode->next = nullptr;
    }
	delete currentNode;
	this->length--;
	return true;

}
//Best case: Theta(1): When the element to be deleted is on the first position
//Worst case: Theta(n): When the element to be deleted is at the last position
// =>Total complexity: O(n)
bool Set::search(TElem elem) const {
	node *n;
	n = this->head;
	while (n!= nullptr)
    {
	    if(n->data == elem)
	        return true;
	    n = n->next;
    }

	return false;
}
// Best case: Theta(1): When the element we are looking for is at the first position
// Worst case: Theta(n): When the element we are looking for is on the last position or it doesn't exist
// => Total complexity: O(n)

int Set::size() const {
	return this->length;
}
//Theta(1)

bool Set::isEmpty() const {
	if(this->head == nullptr)
	    return true;
	return false;
}
//Theta(1)

void Set::Union(const Set& s)
{
    node *n;
    n = s.head;
    while(n!= nullptr)
    {
        this->add(n->data);
        n = n->next;
    }
}
//Best case: Theta(n * n) if the sets have the same elements
//Worst case: Theta(m* n(m^2)) if the numbers from the second set are different from the first


Set::~Set() {
	node* currentNode = this->head;
	node* nextNode = nullptr;
	while(currentNode!= nullptr)
    {
	    nextNode = currentNode->next;
	    free(currentNode);
	    currentNode = nextNode;

    }
	this->head = nullptr;
}
//Theta(n)

SetIterator Set::iterator() {
	return SetIterator(*this);
}
//Theta(1)

