#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{   
    protected:
    short _size=0;
    public:
    class Node
    {   
        public:
        T value;
        Node* next;
        Node* prev;
        
    };
    
    Node* head=NULL;
    
    //Insert
    void InsertAtBeginning(T value)
    {
        Node* newNode=new Node();
        newNode->value=value;
        newNode->next=head;
        newNode->prev=NULL;
        
        
        if(head != NULL)
        {
            head->prev=newNode;
        }
        
        head =newNode;
        _size++;
    }
    
    //Print
    void PrintList()
    {
        Node* Current=head;
        
        while(Current!=NULL)
        {
            cout<<Current->value<<" ";
            Current=Current->next;
        }
    cout<<endl;    

    }
    
    //Find
    Node* Find(T value)
    {
        Node* Current=head;
        
        while(Current!=NULL)
        {
            if(Current->value==value)
            {
                return Current;
            }
        Current=Current->next;    
        }
        
        return NULL;
    }
    
    //InsertAfter
    void InsertAfter(Node* current, T value)
    {
        Node* newNode=new Node();
        newNode->value=value;
        newNode->next=current->next;
        newNode->prev=current;
        
        if(current->next!=NULL)
        {
            current->next->prev=newNode;
            
        }
        current->next=newNode;
        _size++;
    }
    
    //InsertAtEnd
    void InsertAtEnd(T value)
    {
        Node* newNode=new Node();
        newNode->value=value;
        newNode->next=NULL;
        
        if(head==NULL)
        {
            newNode->prev=NULL;
            head=newNode;
        }
        else
        {
        Node* current=head;
         while(current->next!=NULL)
         {
             current=current->next;
         } 
         current->next=newNode;
         newNode->prev=current;
        }
         _size++;
    }
    
    //DeleteNode
    void DeleteNode(Node* &NodeToDelete)
    {
        if(head==NULL || NodeToDelete==NULL)
        {
            return;
        }
        if(head==NodeToDelete)
        {
            head=NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
          delete NodeToDelete;
          _size--;
    }

    //DeleteFirstNode
    void DeleteFirstNode()
    {
        if(head==NULL)
        {
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        delete temp;
        _size--;
    }
    
    void DeleteLastNode()
    {
        if(head==NULL)
        {
            return;
            
        }
        
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        
        Node* current=head;
        while(current->next->next !=NULL)
        {
            current=current->next;
        }
        
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _size--;
    }
    //Clear
    
    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }
    //Reverse
    void  Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }
    //GetNode
    Node* GetNode(short Index)
    {
        int counter=0;
        if(Index>_size-1||Index<0)
            return NULL;
        
        Node*current=head;
        
        while(current !=NULL&& (current->next !=NULL) )
        {
            if(counter==Index)
            {
                break;
            }
            current=current->next;
            counter++;
        }
        return current;
    }
    //GetIteam
    T GetIteam(short Index)
    {
        Node *N=GetNode(Index);
        if(N==NULL)
            return NULL;
        else
            return N->value;
            
    }
    //IsEmpty
    bool IsEmpty()
    {
        return (_size==0?1:0);
    }
    //Size
    short Size()
    {
        return _size;
    }
    //Update
    bool Update(short Index,T value)
    {
        Node *N=GetNode(Index);
        if(N!=NULL)
        {
            N->value=value;
            return true;
            
        }
        else
        {
            return false;
        }
    }
    //InsertAfterIndex
    void InsertAfterIndex(short Index ,T value)
    {
        Node* current= GetNode(Index);
        InsertAfter(current,value);
    }
    
};