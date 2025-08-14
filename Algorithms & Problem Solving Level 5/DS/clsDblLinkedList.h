#pragma once

#include <iostream>

using namespace std;



template <class T> 
class clsDblLinkedList
{
private:

    int _Size = 0;

public:

    class Node
    {    
        public:
        int Value;
        Node * Next;
        Node * Previous;
    };

    Node * Head = NULL;
    
    void InsertAtBeginning(T Value)
    {
        Node * newNode = new Node();

        newNode->Value = Value;
        newNode->Next = Head;
        newNode->Previous = NULL;
       
        if (Head != NULL)
        {
            Head->Previous = newNode;
        }

        
        Head = newNode;
        _Size++;
    }

    void InsertAfter(Node * PrevNode, T Value)
    {
        Node *newNode = new Node();

        newNode->Value = Value;
        newNode->Next = PrevNode->Next;
        newNode->Previous = PrevNode;

        if (PrevNode->Next != NULL)
        {
            PrevNode->Next->Previous = newNode;
        }

        PrevNode->Next = newNode;
        _Size++;
    }

    bool InsertAfter(T Index, T Value)
    {
        Node * ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode,Value);
            return true;
        }
        else
            return false;
    }

    void InsertAtEnd(T Value)
    {
        Node* newNode = new Node();
        newNode->Value = Value;
        newNode->Next = NULL;
        if (Head == NULL) {
            newNode->Previous = NULL;
            Head = newNode;
        }
        else {
            Node* current = Head;
            while (current->Next != NULL) {
                current = current->Next;
            }
            current->Next = newNode;
            newNode->Previous = current;
        }
        _Size++;
    }

    void DeleteNode(Node * &NodeToDelete)
    {
        if (Head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (Head == NodeToDelete)
        {
            Head= NodeToDelete->Next;
        }

        if (NodeToDelete->Next != NULL)
        {
            NodeToDelete->Next->Previous = NodeToDelete->Previous;
        }

        if (NodeToDelete->Previous != NULL)
        {
            NodeToDelete->Previous->Next = NodeToDelete->Next;
        }

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (Head == NULL)
        {
            return;
        }

        Node * temp = Head;

        Head = Head->Next;
        if (Head != NULL)
        {
            Head->Previous = NULL;
        }

        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (Head == NULL)
        {
            return;
        }

        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
            return;
        }

        Node * Current = Head;

        while (Current->Next->Next != NULL)
        {
            Current = Current->Next;
        }

        Node * temp = Current->Next;
        Current->Next = NULL;
        delete temp;
        _Size--;
    }

    Node * Find(T Value)
    {
        Node * Current = Head;
        while (Current != NULL)
        {
            if (Current->Value == Value)
            {
                return Current;
            }
            Current = Current->Next;
        }
        return NULL;
    }

    void PrintList()
    {
        Node * Current = Head;
        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << '\n';
        delete Current;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node * Current = Head;
        Node * temp = nullptr;

        while (Current != nullptr)
        {
            temp = Current->Previous;
            Current->Previous = Current->Next;
            Current->Next = temp;
            Current = Current->Previous;

            if (temp != nullptr)
            {
                Head = temp->Previous;
            }
        }
        
    }

    Node * GetNode(T Index)
    {
        Node * Current = Head;
        short Counter = 0;

        if (Index > _Size -1 || Index < 0)
            return NULL;

        while (Current != NULL && Current->Next != NULL)
        {
            if (Index == Counter)
                break;
            
            Current = Current->Next;
            Counter++;
        } 

        return Current;
    }

    T GetItem(T Index)
    {
        Node * ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return 0;
        else
            return ItemNode->Value;
    }

    bool UpdateItem(T Index, T NewValue)
    {
        Node * ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        else
            return false;
    }

};