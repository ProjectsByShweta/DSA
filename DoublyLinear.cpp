//Doubly linear using c++

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);        
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyLL::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
    PNODE temp = First;

    cout<<"\nNULL <=> ";
    while(temp != NULL)
    {
        cout<<" | " <<temp->data <<" | <=> ";
       
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn =  NULL;

    newn = new NODE;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev =NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First ->prev = newn;
        First = newn;
    }
    iCount++;
}

void DoublyLL::InsertLast(int No)
{
    PNODE newn = NULL;
    PNODE temp = First;

    newn = new NODE;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

void DoublyLL::InsertAtPos(int No, int iPos)
{
    PNODE newn = new NODE;
    int i = 0;
    PNODE temp = First;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp =  First;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp ->next;
        temp -> next ->prev = newn;
        temp ->next = newn;
        newn -> prev =temp;
        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(First == NULL)  
    {
        cout<<"Unable to delete the node as LL is empty"<<endl;
        return;
    }
    else if(First->next == NULL) 
    {
        delete First;
        First = NULL;
    }
    else    
    {
        PNODE temp = First;
       First = First ->next;
       First -> prev = NULL;
       delete temp;      
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)  
    {
        cout<<"Unable to delte the node as LL is empty\n";
        return;
    }
    else if((First)->next == NULL) 
    {
        delete(First);
        First = NULL;
    }
    else    
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount)) 
    {
        cout << "Invalid Position\n";
        return;
    }

    if (iPos == 1) 
    {
        DeleteFirst();
    } 
    else if (iPos == iCount)
    {
        DeleteLast();
    } 
    else 
    {
        PNODE temp = First;

        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        PNODE temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL) {
            temp2->next->prev = temp;
        }
        delete temp2;

        iCount--;
    }
}

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.InsertAtPos(105,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    return 0;
}