#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;


template <class T>
class clsMyQueue
{
    protected:
    clsDblLinkedList<T> _Mylinkedlist;
    
    public:
    
   void push(T value)
    {
        _Mylinkedlist.InsertAtEnd(value);
    }
    
    void pop ()
    {
        _Mylinkedlist.DeleteFirstNode();
    }
    short size()
    {
        return _Mylinkedlist.Size();
    }
    void print()
    {
        _Mylinkedlist.PrintList();
    }
    T front()
    {
        _Mylinkedlist.GetIteam(0);
    }
    T back()
    {
        _Mylinkedlist.GetIteam(size()-1);
    }
    T GetIteam(short value)
    {
        _Mylinkedlist.GetIteam(value);
    }
    void Reverse()
    {
        _Mylinkedlist.Reverse();
    }
    
    bool UpdateIteam(short Index,T value)
    {
         return _Mylinkedlist.Update(Index , value);
    }
    void InsertAfter(T valueAfter,T value)
    {
        clsDblLinkedList<int>::Node *N=_Mylinkedlist.Find(valueAfter);
        _Mylinkedlist.InsertAfter(N,value);
    }
    void InsertAtFront(T value)
    {
        _Mylinkedlist.InsertAtBeginning(value);
    }
    void InsertAtBack(T value)
    {
        push(value);
    }
    void Clear()
    {
        _Mylinkedlist.Clear();
    }
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};