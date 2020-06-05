#pragma once
#include "../Vector/Vector.h"

namespace Algos
{

template <typename E>
class VectorStack
{
public:

    VectorStack() 
    {
        this->_size = 0;
    }

    VectorStack(const VectorStack& other)
    {
        this->_size = other._size;
        this->_data = other._data;
    }

    virtual ~VectorStack() 
    {
        this->_data.clear();
    }

    void operator=(const VectorStack& other)
    {
        this->_size = other._size;
        this->_data = other._data;
    }

    void push(E item)
    {
        this->_data.push_back(item);
        this->_size++;
    }

    E pop()
    {
        E item = this->_data[--(this->_size)];
        this->_data.pop_back();
        return item;
    }

    bool isEmpty()
    {
        return this->size() == 0;
    }

    int size()
    {
        return this->_size;
    }

    typename Vector<E>::reverseIterator begin()
    {
        return this->_data.rbegin();
    }

    typename Vector<E>::reverseIterator end()
    {
        return this->_data.rend();
    }

private:
    int _size;
    Vector<E> _data;
};

}