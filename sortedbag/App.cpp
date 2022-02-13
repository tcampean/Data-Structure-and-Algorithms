#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <assert.h>

using namespace std;

bool test_relation(TComp r1, TComp r2) {
    return r1 <= r2;
}

void test_addOccurrences()
{
    cout<<"Testing addOccurrences"<<endl;
    SortedBag sb(test_relation);
    assert(sb.isEmpty() == true);
    assert(sb.size() == 0);
    sb.add(5);
    assert(sb.size()==1);
    assert(sb.nrOccurrences(5)==1);
    sb.addOccurrences(3,5);
    assert(sb.nrOccurrences(5)==4);
    assert(sb.search(6)== false);
    sb.addOccurrences(3,6);
    assert(sb.search(6)==true);
    assert(sb.nrOccurrences(6)==3);

}


int main() {
	testAll();
	testAllExtended();
	test_addOccurrences();
	
	cout << "Test over" << endl;
	system("pause");
}
