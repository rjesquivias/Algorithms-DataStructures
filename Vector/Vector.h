#pragma once
#include <iostream>

namespace Algos
{

// Template's should be implemented in header
template <typename E>
class Vector
{
    public:

        // Default CTOR
        Vector()
        {
            this->_capacity = 10;
            this->_size = 0;
            this->_data = new E[this->_capacity];

            for(int i = 0; i < this->_capacity; i++) 
                this->_data[i] = 0;
        }                          

        /*****************/
        /*** Rule of 3 ***/
        /*****************/

        // Copy Constructor
        Vector(const Vector<E>& other)
        {
            this->_capacity = other._capacity;
            this->_size = other._size;

            this->_data = new E[this->_capacity];
            for(int i = 0; i < this->_size; i++)
            {
                this->_data[i] = other._data[i];
            }
        }

        // Virtual Destructor      
        virtual ~Vector()
        {
            this->clear();
        }

        // Overloaded assignment operator       
        void operator=(const Vector<E>& other)
        {
            if(this->_data)
                delete [] this->_data;

            this->_capacity = other._capacity;
            this->_size = other._size;

            this->_data = new E[this->_capacity];
            for(int i = 0; i < this->_size; i++)
            {
                this->_data[i] = other._data[i];
            }
        }

        /****************/
        /*** Methods ***/
        /***************/

        // Return size
        int size()
        {
            return this->_size;
        }

        // Return capacity
        int capacity()
        {
            return this->_capacity;
        }

        // Test whether vector is empty
        bool empty()
        {
            return this->size() == 0;
        }

        // Change size
        void resize(int n)
        {
            E* temp = new E[n];

            for(int i = 0; i < n; i++)
            {
                if(i >= this->_capacity)
                    temp[i] = 0;
                else
                    temp[i] = this->_data[i];
            }
            
            this->_capacity = n;

            delete[] this->_data;
            this->_data = temp;
        }

        // Add element at the end
        void push_back(E element)
        {
            if(this->_size >= this->_capacity)
            {
                this->resize(this->_capacity * 2);
            }
            this->_data[this->_size++] = element;
        }

        // Delete last element
        void pop_back()
        {
            if(this->_size > 0)
            {
                this->_size--;
                if(this->_size < this->_capacity / 4)
                {
                    this->resize(this->_capacity / 2);
                }
            }
        }

        // Clear content 
        void clear()
        {
            while(!this->empty())
                this->pop_back();
        }

        // Access element
        E& operator[](int index)
        {
            return (index < this->_size && index >= 0) ? this->_data[index] : this->_data[0];
        }

    private:

        E* _data;
        int _size;
        int _capacity;

    public:

        class iterator 
        {
        public:
            iterator(E* ptr): ptr(ptr){}
            iterator operator++() { ++ptr; return *this; }
            bool operator!=(const iterator & other) const { return ptr != other.ptr; }
            const E& operator*() const { return *ptr; }
        private:
            E* ptr;
        };

        iterator begin() const
        {
            return iterator(_data);
        }

        iterator end() const
        {
            return iterator(_data + _size);
        }
};

}