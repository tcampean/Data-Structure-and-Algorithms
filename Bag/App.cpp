#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <assert.h>
using namespace std;

void test_function()
{
    cout<<"Testing Minimum Frequency"<<endl;
    Bag b;
    assert(b.isEmpty() == true);
    assert(b.size() == 0);
    assert(b.minFrequency() == 0);
    b.add(5);
    b.add(1);
    b.add(1);
    b.add(5);
    assert(b.minFrequency() == 2);
    b.add(3);
    assert(b.minFrequency() == 1);
}

int main() {

    test_function();
	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All test over" << endl;










    cout<<"Press any key to continue...";
    char a;
    cin.get(a);
}