#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>

SortedBag::SortedBag(Relation r) {
    this->objects = new TComp[1];
    this->frequency = new TComp[1];
    this->length = 0;
    this->capacity = 1;
    this->relation = r;
}
//Theta(1)

void SortedBag::resize() {
    TComp *new_objects = new TComp[2 * this->capacity];
    TComp *new_freq = new TComp[2 * this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        new_objects[i] = this->objects[i];
        new_freq[i] = this->frequency[i];
    }
    delete[] this->objects;
    delete[] this->frequency;
    this->objects = new_objects;
    this->frequency = new_freq;
    this->capacity *= 2;
}
//Theta(n)

void SortedBag::sort() {
    int i, j;
    TComp key, freq;
    for (i = 0; i < this->length; i++) {
        key = this->objects[i];
        freq = this->frequency[i];
        j = i - 1;
        while (j >= 0 && !this->relation(this->objects[j], key)) {
            this->objects[j + 1] = this->objects[j];
            this->frequency[j + 1] = this->frequency[j];
            j = j - 1;
        }
        this->objects[j + 1] = key;
        this->frequency[j + 1] = freq;
    }
}
//Best case: Theta(n) Worst case: Theta(n^2) => Total complexity: O(n)  ; n = this->length


void SortedBag::add(TComp e) {
    if (this->length == this->capacity)
        this->resize();
    int ok = 0, index;
    for (int i = 0; i < this->length; i++)
        if (this->objects[i] == e) {
            ok = 1;
            index = i;
            break;
        }
    if (ok == 1)
        this->frequency[index]++;
    else {
        this->objects[length] = e;
        this->frequency[length] = 1;
        this->length++;
        this->sort();
    }
}
//Best case: Theta(1) Worst case: Theta(n^2) => Total complexity: O(n^2)

bool SortedBag::remove(TComp e) {
    if (!this->search(e))
        return false;
    for (int i = 0; i < this->length; i++)
        if (this->objects[i] == e) {
            if (this->frequency[i] == 1) {
                for (int j = i; j < this->length - 1; j++) {
                    this->objects[j] = this->objects[j + 1];
                    this->frequency[j] = this->frequency[j + 1];
                }
                this->length--;
            } else
                this->frequency[i]--;

        }
    return true;
}
//Best case: Theta(1) Worst case: Theta(n^2) => Total complexity: O(n^2)

bool SortedBag::search(TComp elem) const {
    for (int i = 0; i < this->length; i++)
        if (this->objects[i] == elem)
            return true;
    return false;
}
//Best case: Theta(1) Worst case: Theta(n) => Total complexity: O(n)   ; n=this->length

int SortedBag::nrOccurrences(TComp elem) const {
    for (int i = 0; i < this->length; i++)
        if (this->objects[i] == elem)
            return this->frequency[i];

    return 0;
}
//Best case: Theta(1) Worst case: Theta(n) => Total complexity: O(n) ; n=this->length

int SortedBag::size() const {

    int s = 0;
    for (int i = 0; i < this->length; i++)
        s += this->frequency[i];
    return s;
}
//Best case = Worst case: Theta(n) => Total complexity: O(n) ; n=this->length

bool SortedBag::isEmpty() const {
    if (this->length == 0)
        return true;
    return false;
}
//Theta(1)


void SortedBag::addOccurrences(int nr, TComp elem)
{
    if(nr<1)
        throw std::exception();
    if(search(elem)) {
        for (int i = 0; i < this->length; i++)
            if (this->objects[i] == elem)
                this->frequency[i] += nr;
    }
    else{
        if (this->length == this->capacity)
            this->resize();
        this->objects[this->length] = elem;
        this->frequency[this->length] = nr;
        this->length++;
        this->sort();
    }

}
//Best case: Theta(n) Worst case: Theta(n^2) , Total complexity: 0(n^2)

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete[] this->frequency;
    delete[] this->objects;
}
//Theta(1)