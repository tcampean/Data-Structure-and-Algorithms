#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
#include <assert.h>
using namespace std;

void test_Union()
{
    cout<<"Union test"<<endl;
    Set s,s1;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5)==true);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    assert(s.add(-3)==true);
    assert(s1.isEmpty() == true);
    assert(s1.size() == 0);
    assert(s1.add(5)==true);
    assert(s1.add(1)==true);
    assert(s1.add(10)==true);
    assert(s1.add(7)==true);
    assert(s1.add(-3)==true);
    assert(s.size() == 5);
    s.Union(s1);
    assert(s.size()==5);
    s1.add(-33);
    assert(s.search(-33)==false);
    assert(s1.search(-33)==true);
    s.Union(s1);
    assert(s.size()==6);
    assert(s.search(-33)==true);

}


int main() {

    test_Union();
	testAll();
	testAllExtended();

	cout << "That's all!" << endl;
	system("pause");

}



