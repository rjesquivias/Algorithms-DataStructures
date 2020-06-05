#pragma once
#include "../Vector/Vector.h"

/* 
   A bag is a collection where removing items is not supported—its purpose is 
   to provide clients with the ability to collect items and then to iterate 
   through the collected items (the client can also test if a bag is empty and 
   find its number of items). The order of iteration is unspecified and should 
   be immaterial to the client.
*/

namespace Algos
{

template <typename E>
class Bag
{
public:

    Bag()
    {
        this->_size = 0;
    }

    Bag(const Bag<E>& other)
    {
        this->_size = other._size;
        this->_data = other._data;
    }

    virtual ~Bag()
    {
        this->_data.clear();
    }

    void operator=(const Bag<E>& other)
    {
        this->_size = other._size;
        this->_data = other._data;
    }

    void add(E item)
    {
        _size++;
        _data.push_back(item);
    }

    bool isEmpty()
    {
        return size() == 0;
    }

    int size()
    {
        return _size;
    }

private:

    int _size;
    Vector<E> _data;

public:
    
    typename Vector<E>::iterator begin()
    {
        return _data.begin();
    }

    typename Vector<E>::iterator end()
    {
        return _data.end();
    }

};

}