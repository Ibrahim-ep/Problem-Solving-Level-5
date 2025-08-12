#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> 
class clsMyQueue
{
protected:

    clsDblLinkedList <T> _MyList;

public:

    void push(T Value)
    {
       _MyList.InsertAtEnd(Value);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    void print()
    {
        _MyList.PrintList();
    }

    short size()
    {
        return _MyList.Size();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(size() - 1);
    }

    T GetItem(T Index)
    {
        return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void UpdateItem(T Index, T Value)
    {
        _MyList.UpdateItem(Index,Value);
    }

    void InsertAfter(T Index,T Value)
    {
        _MyList.InsertAfter(Index,Value);
    }

    void InsertAtFront(T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyList.Clear();
    }
};