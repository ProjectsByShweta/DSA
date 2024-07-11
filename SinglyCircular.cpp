//singly circular using c++

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL 
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;

    public:
        SinglyCL();
        
        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);

        void DeleteFirst();
        void DeleteLast();

        void InsertAtPos(int No, int iPos);
        void DeleteAtPos(int iPos);
};

SinglyCL::SinglyCL() 
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCL::Display() 
{
    if ((First == NULL) && (Last == NULL)) 
    {
        cout << "LinkedList is empty\n";
        return;
    }

    PNODE temp = First;
    do {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    } while (temp != Last->next);

    cout << "\n";
}

int SinglyCL::Count() 
{
    return iCount;
}

void SinglyCL::InsertFirst(int No) 
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    } 
    else 
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
}

void SinglyCL::InsertLast(int No) 
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    } 
    else 
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
}

void SinglyCL::DeleteFirst() {
    if ((First == NULL) && (Last == NULL)) 
    {
        return;
    }
     else if (First == Last) 
     {
        delete First;
        First = NULL;
        Last = NULL;
    } 
    else 
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
}

void SinglyCL::DeleteLast() {
    if ((First == NULL) && (Last == NULL)) 
    {
        return;
    } 
    else if (First == Last)
     {
        delete First;
        First = NULL;
        Last = NULL;
    } 
    else
     {
        PNODE temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
}

void SinglyCL::InsertAtPos(int No, int iPos)
 {
    int iLength = Count();

    if ((iPos < 1) || (iPos > iLength + 1)) 
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) 
    {
        InsertFirst(No);
    } 
    else if (iPos == iLength + 1) 
    {
        InsertLast(No);
    } 
    else 
    {
        PNODE newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        PNODE temp = First;
        for (int i = 1; i < iPos - 1; i++) 
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCL::DeleteAtPos(int iPos) 
{
    int iLength = Count();

    if ((iPos < 1) || (iPos > iLength)) 
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) 
    {
        DeleteFirst();
    } 
    else if (iPos == iLength)
    {
        DeleteLast();
    } 
    else 
    {
        PNODE temp1 = First;
        for (int i = 1; i < iPos - 1; i++) 
        {
            temp1 = temp1->next;
        }
        PNODE temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

int main() {
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.DeleteAtPos(3);

    obj.Display();

    iRet = obj.Count();
    cout << "Number of elements are: " << iRet << endl;

    return 0;
}
