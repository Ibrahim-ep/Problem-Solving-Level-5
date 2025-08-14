#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> 
class clsDynamicArray
{
protected:

    int _Size;
    T * _TempArray;

public:

    T * OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        _Size = Size;
        
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete []OriginalArray;
    }

    bool setItem(T Index, T Item)
    {
        if (Index >= _Size || Index < 0)
        {
            return false;
        }

        OriginalArray[Index] = Item;
        return true;
    }
    
    void PrintLis()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << OriginalArray[i] << ' ';
        }
        cout << '\n';
    }

    bool IsEmpty()
    {
        return _Size == 0 ? true : false;
    }

    int Size()
    {
        return _Size;
    }

    void Resize(int Size)
    {
        if (Size < 0)
        {
            Size = 0;
        }

        _TempArray = new T[Size];

        if (Size < _Size)
        {
            _Size = Size;
        }

        for (int i = 0; i < Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = Size;
        
        delete []OriginalArray;
        OriginalArray = _TempArray;
    }

    void Reverse()
    {
        _TempArray = new T[_Size];

       for (int i = 0; i <= _Size -1; i++)
       {
            _TempArray[i] = OriginalArray[_Size - 1 - i];
       }

       delete []OriginalArray;
       OriginalArray = _TempArray;
    }

    T GetItem(T Index)
    {
        return OriginalArray[Index];
    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete []OriginalArray;
        OriginalArray = _TempArray;
    }
    
    bool DeleteItemAt(short Index)
    {
        if (Index >= _Size || Index < 0)
            return false;

        _Size--;
       _TempArray = new T[_Size];

       for (int i = 0; i < Index; i++)
       {
            _TempArray[i] = OriginalArray[i];
       }

       for (int i = Index + 1; i < _Size + 1; i++)
       {
            _TempArray[i - 1] = OriginalArray[i];
       }

       delete []OriginalArray;
       OriginalArray = _TempArray;
       return true;
    }

    void DeleteFirstItme()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }

    short Find(T Value)
    {
        for (short i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;
    }

    bool DeleteByValue(T Value)
    {
        short Index = Find(Value);

        if (Index != -1)
        {
            return DeleteItemAt(Index);
        }
        return false;
    }

    bool InsertAt(short Index, T Value)
    {
        if (Index > _Size || Index < 0)
            return false;

        _Size++;
        _TempArray = new T[_Size];

        for (short i = 0; i < Index + 1; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[Index] = Value;

        for (short i = Index; i < _Size + 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }


        delete []OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }

    bool InsertAtBeginning(T Value)
    {
        return (InsertAt(0,Value));
    }

    bool InsertBefor(short Index, T Value)
    {
        if (Index > _Size)
            return false;

        if (Index < 1)
        {
            return InsertAtBeginning(Value);
        }
        else
        {
            return (InsertAt(Index - 1, Value));
        }       
    }

    bool InsertAfter(short Index, T Value)
    {
        if (Index < 0)
            return false;

        if (Index >= _Size)
        {
            return InsertAfter(_Size - 1, Value);
        }
        else
        {
            return (InsertAt(Index + 1, Value));
        }
    }

    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size,Value);
    }
};