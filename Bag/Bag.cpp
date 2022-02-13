#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->m = 13;
	this->T = new Node*[m-1];
	for(int i=0;i<m;i++)
	    this->T[i] = nullptr;
	this->amount = 0;
}
//Best case = Worst case: Theta(m)

void Bag::resize()
{
    this->m *=2;
    Node** new_T = new Node*[m-1];
    for(int i=0;i<m;i++)
        new_T[i] = nullptr;
    for(int i = 0;i<this->m/2;i++)
    {
        Node *currentNode = this->T[i];
        while(currentNode!= nullptr)
        {
            Node* new_node = new Node;
            int position = this->h(currentNode->key.first);
            new_node->key = currentNode->key;
            new_node->next = new_T[position];
            new_T[position] = new_node;
            currentNode = currentNode->next;
        }
    }
    for(int i =0;i<m/2;i++)
    {
        Node *currentNode , *next_node;
        currentNode = this->T[i];
        while(currentNode!= nullptr)
        {
            next_node = currentNode->next;
            delete currentNode;
            currentNode = next_node;

        }
    }
    this->T = new_T;



}
//Best case = Worst case: Theta(m+nr) (nr representing the total number of elements in the table)
//Total complexity: O(m+nr)

void Bag::add(TElem elem) {
    int position = this->h(elem);
    Node* currentNode = this->T[position];
    Node* previousNode = nullptr;
    while(currentNode!= nullptr && currentNode->key.first!=elem) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == nullptr && previousNode == nullptr)
    {   Node *new_node = new Node;
        new_node->key.first=elem;
        new_node->key.second=1;
        new_node->next = nullptr;
        this->T[position] = new_node;

    }
    else if(currentNode == nullptr) {
        Node *new_node = new Node;
        new_node->key.first=elem;
        new_node->key.second=1;
        new_node->next = nullptr;
        previousNode->next = new_node;
    }
    else
    {
        currentNode->key.second++;
    }
    this->amount++;
    if(this->amount>= 0.7*this->m)
        this->resize();

}
//Best case: Theta(1) when the element already exists in the table and it's on the first position in the slot
//Worst case: Theta(m+nr) when the element that we are adding doesn't exist and we have to add it but also to resize the table
//Total complexity: O(m+nr)


bool Bag::remove(TElem elem) {
    int position = this->h(elem);
    Node *currentNode = this->T[position];
    Node *previousNode = nullptr;
    while (currentNode != nullptr && currentNode->key.first != elem) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
        return false;
    else if (currentNode->key.second > 1) {
        currentNode->key.second--;
    } else if (previousNode == nullptr) {
        this->T[position] = this->T[position]->next;
    } else {
        previousNode->next = currentNode->next;
        currentNode->next = nullptr;
    }
    this->amount--;
    return true;
}
//Best case: Theta(1) when the element we are looking to remove is on the first position in the slot
//Worst case: Theta(a) (a representing the number of elements in that list)
// when the element we are looking to remove is on the last position of the list
//Total complexity: O(a)


bool Bag::search(TElem elem) const {
	int position = this->h(elem);
	Node* currentNode = this->T[position];
	while(currentNode != nullptr && currentNode->key.first != elem)
	    currentNode = currentNode->next;
	if(currentNode!= nullptr)
	    return true;
	return false; 
}
//Best case: Theta(1) when the element we are looking for is on the first position of the list in the respective slot
//Worst case: Theta(a) (a representing the number of elements in the list of the respective slot)
            //When the element we are looking for is on the last position of the respective list
//Total complexity: O(a)


int Bag::nrOccurrences(TElem elem) const {
    int position = this->h(elem);
    Node* currentNode = this->T[position];
    while(currentNode != nullptr && currentNode->key.first != elem)
        currentNode = currentNode->next;
    if(currentNode == nullptr)
        return 0;
    else
        return currentNode->key.second;

}
//Best case: Theta(1) when the element we are looking for is on the first position of the respective slot
//Worst case: Theta(a) (a representing the number of elements in the list of the respective slot)
//When the element we are looking for is on the last position of the respective list
//Total complexity: O(a)


int Bag::size() const {
    return this->amount;
}
//Theta(1)


bool Bag::isEmpty() const {
	if(this->amount==0)
	    return true;
	return false;
}
//Theta(1)

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
//Theta(1)


Bag::~Bag() {
    for(int i =0;i<m;i++)
    {
        Node *currentNode , *next_node;
        currentNode = this->T[i];
        while(currentNode!= nullptr)
        {
            next_node = currentNode->next;
            delete currentNode;
            currentNode = next_node;

        }
    }
}
//Best case = Worst case : Theta(m+nr) (nr representing the number of all the pairs in the hash table
//Total complexity: O(m+nr)


int Bag::minFrequency() const {
    if(this->amount == 0)
        return 0;
    int mini = 10000000,count = 0;
    for(int i = 0;i<this->m;i++)
    {
        Node *currentNode = this->T[i];
        while(currentNode!= nullptr)
        {
            if(currentNode->key.second < mini) {
                count=1;
                mini = currentNode->key.second;
            }
            else if(currentNode->key.second == mini)
            {
                count++;
            }
            currentNode = currentNode->next;
        }
    }
    return count;
}
//Theta(m+nr) since we iterate through all the slots and every element in the slot
//Total complexity: O(m+nr)