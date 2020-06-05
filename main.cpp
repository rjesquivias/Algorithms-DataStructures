#include <iostream>
#include <cassert>
#include "Vector/Vector.h"
using namespace std;

void testVector();

int main()
{
    testVector();
    return 0;
}

void testVector()
{
    Algos::Vector<int> myVec;
    assert(myVec.capacity() == 10);
    assert(myVec.size() == 0);
    
    for(int i = 0; i < 11; i++)
    {
        myVec.push_back(i);
        assert(myVec.size() == i + 1);
        assert(myVec[i] == i);
    }
    assert(myVec.size() == 11);
    assert(myVec.capacity() == 20);

    int i = 0;
    for(int x : myVec)
    {
        assert(myVec[i++] == x);
    }

    for(int i = 0; i < 7; i++)
    {
        myVec.pop_back();
    }

    assert(myVec.size() == 4);
    assert(myVec.capacity() == 10);

    myVec.clear();
    assert(myVec.size() == 0);
    assert(myVec.capacity() > 1);

    Algos::Vector<int> secondVec;
    for(int i = 0; i < 81; i++)
    {
        secondVec.push_back(i * 2 + 1);
    }
    assert(secondVec.size() == 81);
    assert(secondVec.capacity() == 160);

    myVec = secondVec;
    for(int i = 0; i < secondVec.size(); i++)
    {
        assert(myVec[i] == secondVec[i]);
    }
    assert(myVec.size() == 81);
    assert(myVec.capacity() == 160);

    Algos::Vector<int> thirdVec;
    for(int i = 0; i < 161; i++)
    {
        thirdVec.push_back(i * 3 + 4);
    }
    assert(thirdVec.size() == 161);
    assert(thirdVec.capacity() == 320);

    Algos::Vector<int> mySecondVec(thirdVec);
    for(int i = 0; i < thirdVec.size(); i++)
    {
        assert(mySecondVec[i] == thirdVec[i]);
    }
    assert(mySecondVec.size() == 161);
    assert(mySecondVec.capacity() == 320);
}