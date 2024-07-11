// Generic Doubly Circular LinkedList

#include<iostream>
using namespace std;

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

int main()
{
    // LL of integer
    cout<<"\n\n-------------- LinkdList of Integers --------------\n\n";

    DoublyCL<int> *DCiobj = new DoublyCL<int>();
    int DCiRet = 0;

    DCiobj->InsertFirst(51);
    DCiobj->InsertFirst(21);
    DCiobj->InsertFirst(11);

    DCiobj->Display();
    DCiRet = DCiobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCiobj->InsertLast(101);
    DCiobj->InsertLast(111);
    DCiobj->InsertLast(121);
    
    DCiobj->Display();
    DCiRet = DCiobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCiobj->InsertAtPos(105,5);

    DCiobj->Display();
    DCiRet = DCiobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCiobj->DeleteAtPos(5);
    DCiobj->Display();
    DCiRet = DCiobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    // LL of character
    cout<<"\n\n-------------- LinkdList of Chracters --------------\n\n";

    DoublyCL<char> *DCcobj = new DoublyCL<char>();

    DCcobj->InsertFirst('D');
    DCcobj->InsertFirst('F');
    DCcobj->InsertFirst('R');

    DCcobj->Display();
    DCiRet = DCcobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCcobj->InsertLast('E');
    DCcobj->InsertLast('Y');
    DCcobj->InsertLast('U');
    
    DCcobj->Display();
    DCiRet = DCcobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCcobj->InsertAtPos('W',5);

    DCcobj->Display();
    DCiRet = DCcobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCcobj->DeleteAtPos(5);
    DCcobj->Display();
    DCiRet = DCcobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    // LL of float
    cout<<"\n\n-------------- LinkdList of Floats --------------\n\n";

    DoublyCL<float> *DCfobj = new DoublyCL<float>();

    DCfobj->InsertFirst(90.78f);
    DCfobj->InsertFirst(78.99f);
    DCfobj->InsertFirst(67.99f);

    DCfobj->Display();
    DCiRet = DCfobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCfobj->InsertLast(45.67f);
    DCfobj->InsertLast(54.78f);
    DCfobj->InsertLast(77.89f);
    
    DCfobj->Display();
    DCiRet = DCfobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCfobj->InsertAtPos(88.56,5);

    DCfobj->Display();
    DCiRet = DCfobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCfobj->DeleteAtPos(5);
    DCfobj->Display();
    DCiRet = DCfobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    // LL of double

    cout<<"\n\n-------------- LinkdList of Doubles --------------\n\n";

    DoublyCL<double> *DCdobj = new DoublyCL<double>();

    DCdobj->InsertFirst(90.78978);
    DCdobj->InsertFirst(78.99645);
    DCdobj->InsertFirst(67.9934);

    DCdobj->Display();
    DCiRet = DCdobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCdobj->InsertLast(45.67867);
    DCdobj->InsertLast(54.78534);
    DCdobj->InsertLast(77.89324);
    
    DCdobj->Display();
    DCiRet = DCdobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCdobj->InsertAtPos(88.56987,5);

    DCdobj->Display();
    DCiRet = DCdobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    DCdobj->DeleteAtPos(5);
    DCdobj->Display();
    DCiRet = DCdobj->Count();
    cout<<"Number of elemensts are : "<<DCiRet<<endl;

    return 0;
}