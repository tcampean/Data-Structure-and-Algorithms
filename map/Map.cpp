#include "Map.h"
#include "MapIterator.h"
#include <iostream>

Map::Map() {
	this->cap = 1;
	this->elems = new TElem[this->cap];
	this->next = new int[this->cap];
	this->head = -1;
	for(int i =0;i<this->cap-1;i++)
	    this->next[i] = i+1;
	this->next[this->cap-1] = -1;
	this->firstEmpty = 0;
	this->length=0;

}
//Theta(cap)

Map::~Map() {
    delete[] this->elems;
    delete[] this->next;
}
//Theta(1)

TValue Map::add(TKey c, TValue v){
    if(search(c)!=NULL_TVALUE) {
        int current = this->head;
        while (this->elems[current].first != c)
            current = this->next[current];
        TValue value =this->elems[current].second;
        this->elems[current].second = v;
        return value;
    }
    else
    {
        if(this->firstEmpty==-1){
            TElem *newElems = new TElem [2*this->cap];
            int *newNext = new int[2*this->cap];
            for(int i =0 ;i<this->cap;i++)
            {
                newElems[i] = this->elems[i];
                newNext[i] = this->next[i];
            }
            for(int i = this->cap;i<this->cap*2-1;i++)
                newNext[i] = i+1;
            newNext[this->cap*2-1] = -1;
            delete[] this->elems;
            this->elems = newElems;
            delete[] this->next;
            this->next = newNext;
            this->firstEmpty = this->cap;
            this->cap *=2;
        }
        int position = this->firstEmpty;
        TElem e(c,v);
        this->elems[position] = e;
        this->firstEmpty = this->next[firstEmpty];
        this->next[position] = this->head;
        this->head = position;
        this->length++;
        return NULL_TVALUE;

    }
}
//Best case: Theta(1) if the list has only one element and we are trying to add a new pair with the same key with the existing element
//Worst case: Theta(n) when we are trying to add a pair with the same key with the element from the last position
//Total complexity: O(n)

TValue Map::search(TKey c) const{
	int current = this->head;
	while(current != -1 && this->elems[current].first != c)
	    current = this->next[current];
	if (current != -1)
	    return this->elems[current].second;
	else
	    return NULL_TVALUE;
}
//Best case: Theta(1) when the key we are looking for is on the first position
//Worst case: Theta(n) when they key we are looking for is on the last position
//Total complexity: O(n)


TValue Map::remove(TKey c){
	int node = this->head;
	int prevNode=-1;
	while(node !=-1 && this->elems[node].first != c)
    {
	    prevNode = node;
	    node = this->next[node];
    }
	if(node!=-1) {
	    TKey value;
        if (node == this->head) {
            value = this->elems[node].second;
            this->head = this->next[this->head];
        } else{
            value = this->elems[node].second;
            this->next[prevNode] = this->next[node];
            }
        this->next[node] = this->firstEmpty;
        this->firstEmpty = node;
        this->length--;
        return value;
    }
	else
	    return NULL_TVALUE;
}
//Best case: Theta(1) when the element we are looking for is on the first position
//Worst case: Theta(n) when the element we are looking for is on the last position
//Total complexity: O(n)


int Map::size() const {
	return this->length;
}
//Theta(1)

bool Map::isEmpty() const{
	if(this->length==0)
	    return true;
	return false;
}
//Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
//Theta(1)

std::vector<TValue> Map::valueBag() const
{
    std::vector<TValue> values;
    int current = this->head;
    while(current != -1) {
        values.push_back(this->elems[current].second);
        current = this->next[current];
    }
    return values;

}
// Best case = Worst case = Theta(n)



