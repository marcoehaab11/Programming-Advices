#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


template <class T>
class clsMyQueue
{
    protected:
  
    clsDynamicArray<T> _MYDynamicArr;
    
    public:
   
   void push(T value)
    {
        _MYDynamicArr.InsertAtEnd(value);
    }
    
    void pop ()
    {
        _MYDynamicArr.DeleteFirstIteam();
    }
    short size()
    {
        return _MYDynamicArr.Size();
    }
    void print()
    {
        _MYDynamicArr.PrintIteam();
    }
    T front()
    {
        _MYDynamicArr.GetIteam(0);
    }
    T back()
    {
        _MYDynamicArr.GetIteam(size()-1);
    }
    T GetIteam(short value)
    {
        _MYDynamicArr.GetIteam(value);
    }
    void Reverse()
    {
        _MYDynamicArr.Revesre();
    }
    
    bool UpdateIteam(short Index,T value)
    {
         return _MYDynamicArr.Update(Index , value);
    }
 
    void InsertAtFront(T value)
    {
        _MYDynamicArr.InsertAtBegin(value);
    }
    void InsertAtBack(T value)
    {
        InsertAtEnd(value);
    }
    void Clear()
    {
        _MYDynamicArr.Clear();
    }
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};