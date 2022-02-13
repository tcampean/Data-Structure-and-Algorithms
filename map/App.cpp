#include "ExtendedTest.h"
#include "ShortTest.h"

#include "Map.h"
#include <assert.h>


#include <iostream>
using namespace std;

void test_valueBag()
{
    cout<<"Testing valueBag"<<endl;
    Map m;
    assert(m.add(5,5)==NULL_TVALUE);
    assert(m.add(1,111)==NULL_TVALUE);
    assert(m.add(10,110)==NULL_TVALUE);
    assert(m.add(7,7)==NULL_TVALUE);
    vector<TValue> values = m.valueBag();
    assert(values[0] == 7);
    assert(values[1] == 110);
    assert(values[2]==111);
    assert(values[3] == 5);
    assert(values.size()==4);
    assert(m.add(-3,-3)==NULL_TVALUE);
    values = m.valueBag();
    assert(values[0] == -3);
    assert(values.size()==5);

}


int main() {
    test_valueBag();
	testAll();
	testAllExtended();

	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


