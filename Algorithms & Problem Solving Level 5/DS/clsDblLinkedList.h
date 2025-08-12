#pragma once

#include <iostream>

using namespace std;



template <class T> 
class clsDblLinkedList
{

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
    }

    void InsertAtEnd(T Value)
    {
        Node * newNode = new Node();

        newNode->Value = Value;
        newNode->Next = NULL;

        if (Head == NULL)
        {
            Head->Previous = NULL;
            Head = newNode;
        }
        else
        {
            Node *Current = Head;

            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }
            Current->Next = newNode;
            newNode->Previous = Current;
        }
   
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
    }

    void DeleteFirstNode()
    {
        if (Head == NULL)
        {
            return;
        }

        Node * temp = Head;

        Head = Head->Next;
        if (Head->Previous != NULL)
        {
            Head->Previous = NULL;
        }

        delete temp;
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
};