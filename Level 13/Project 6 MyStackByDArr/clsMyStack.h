#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;

template <class T>
class clsMyStack:public clsMyQueue<T>
{
    public:
   
    void push(T value)
    {
        clsMyQueue<T>::_MYDynamicArr.InsertAtBeginning(value);
    }
    
    T Top()
    {
        return clsMyQueue<T>::front();
    }
    
    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};