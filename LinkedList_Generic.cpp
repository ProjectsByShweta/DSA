
/*
    1-> Singly linear Linked List
    2-> Singly circular Linked List
    3-> Doubly linear Linked List
    4-> Doubly circular Linked List
    5-> Stack
    6-> Queue
*/

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
//              Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

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
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n\n";
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
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n\n";
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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}


////////////////////////////////////////////////////////////
//
//               Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSC 
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL 
{
    private:
        struct nodeSC<T> *First;
        struct nodeSC<T> *Last;
        int iCount;

    public:
        SinglyCL();
        
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);

        void DeleteFirst();
        void DeleteLast();

        void InsertAtPos(T No, int iPos);
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL() 
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display() 
{
    if ((First == NULL) && (Last == NULL)) 
    {
        cout << "LinkedList is empty\n";
        return;
    }

    struct nodeSC<T> *temp = First;
    do {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    } while (temp != Last->next);

    cout << "\n";
}

template <class T>
int SinglyCL<T>::Count() 
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No) 
{
    struct nodeSC<T> * newn = new nodeSC<T>;

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
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No) 
{
    struct nodeSC<T> * newn = new nodeSC<T>;

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
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst() {
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
        struct nodeSC<T> *temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast() {
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
        struct nodeSC<T> *temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
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
        struct nodeSC<T> *newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        struct nodeSC<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++) 
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos) 
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
        struct nodeSC<T> *temp1 = First;
        for (int i = 1; i < iPos - 1; i++) 
        {
            temp1 = temp1->next;
        }
        struct nodeSC<T> *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
//              Code of Doubly Linear
//
/////////////////////////////////////////////////////////////


template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

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
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T>* temp = First;

    cout<<"\nNULL <=> ";
    while(temp != NULL)
    {
         cout<<" | " <<temp->data <<" | <=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T>* newn =  NULL;

    newn = new nodeDL<T>;

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

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T>* newn = NULL;
   struct nodeDL<T>* temp = First;

    newn = new nodeDL<T>;

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

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T>* newn = new nodeDL<T>;
    int i = 0;
    struct nodeDL<T>* temp = First;

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

template <class T>
void DoublyLL<T>::DeleteFirst()
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
       struct nodeDL<T>* temp = First;
       First = First ->next;
       First -> prev = NULL;
       delete temp;      
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
   struct nodeDL<T>* temp = First;

    if(First == NULL)  
    {
        cout<<"Unable to delte the node as LL is empty\n";
        return;
    }
    else if(First->next == NULL) 
    {
        delete First;
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

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
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
       struct nodeDL<T>* temp = First;

        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        struct nodeDL<T>* temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL) {
            temp2->next->prev = temp;
        }
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
//              Code of Doubly Circular
//
/////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////
//
//                    Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);        // InsertFirst()
        int pop();              // DeleteFirst()
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void Stack <T>:: Display()
{
    cout<<"Elements of stack are: \n";
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Stack <T>:: Count()
{
    return iCount;
}

template <class T>
void Stack <T>:: Push(T No)
{
    struct nodeS<T> * newn = NULL;
    newn = new nodeS<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack <T>:: pop()
{
    int iValue = 0;
    struct nodeS<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}

/////////////////////////////////////////////////////////////
//
//                   Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        T iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);        // InsertLast()
        T DeQueue();              // DeleteFirst()
};
template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void Queue<T> :: Display()
{
    cout<<"Elements of Queue are: \n";
    struct nodeQ<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

template <class T>
void Queue<T> :: EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new nodeQ<T>;
    
    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }   
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> :: DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as Queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}

int main()
{

/////////////////////////////////////////////////////////////
//
//                 Singly Linear LL
//
/////////////////////////////////////////////////////////////

cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n-------------------- Singly Linear Linkd List ----------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";

 cout<<"\n\n-------------- Singly Linear LinkdList of Integers --------------\n\n";

    SinglyLL<int> *iobj = new SinglyLL<int>();
    int SLRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    SLRet = iobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    SLRet = iobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    SLRet = iobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    SLRet = iobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    // LL of character
    cout<<"\n\n-------------- Singly Linear LinkdList of Chracters --------------\n\n";

    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    SLRet = cobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    SLRet = cobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    cobj->InsertAtPos('W',5);

    cobj->Display();
    SLRet = cobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    SLRet = cobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    // LL of float
    cout<<"\n\n-------------- Singly Linear LinkdList of Floats --------------\n\n";

    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(90.58f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    SLRet = fobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    SLRet = fobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    fobj->InsertAtPos(88.56,5);

    fobj->Display();
    SLRet = fobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    SLRet = fobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    // LL of double

    cout<<"\n\n-------------- Singly Linear LinkdList of Doubles --------------\n\n";

    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    SLRet = dobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    SLRet = dobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    dobj->InsertAtPos(88.56987,5);

    dobj->Display();
    SLRet = dobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    SLRet = dobj->Count();
    cout<<"Number of elemensts are : "<<SLRet<<endl;


////////////////////////////////////////////////////////////
//
//               Singly Circular
//
/////////////////////////////////////////////////////////////


cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n-------------------- Singly Circular Linkd List ----------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";

 // LL of integer
    cout<<"\n\n-------------- LinkdList of Integers --------------\n\n";

    SinglyCL<int> *SCiobj = new SinglyCL<int>();
    int SCiRet = 0;

    SCiobj->InsertFirst(51);
    SCiobj->InsertFirst(21);
    SCiobj->InsertFirst(11);

    SCiobj->Display();
    SCiRet = SCiobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCiobj->InsertLast(101);
    SCiobj->InsertLast(111);
    SCiobj->InsertLast(121);
    
    SCiobj->Display();
    SCiRet = SCiobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCiobj->InsertAtPos(105,5);

    SCiobj->Display();
    SCiRet = SCiobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCiobj->DeleteAtPos(5);
    SCiobj->Display();
    SCiRet = SCiobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    // LL of character
    cout<<"\n\n-------------- LinkdList of Chracters --------------\n\n";

    SinglyCL<char> *SCcobj = new SinglyCL<char>();

    SCcobj->InsertFirst('D');
    SCcobj->InsertFirst('F');
    SCcobj->InsertFirst('R');

    SCcobj->Display();
    SCiRet = SCcobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCcobj->InsertLast('E');
    SCcobj->InsertLast('Y');
    SCcobj->InsertLast('U');
    
    SCcobj->Display();
    SCiRet = SCcobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCcobj->InsertAtPos('W',5);

    SCcobj->Display();
    SCiRet = SCcobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCcobj->DeleteAtPos(5);
    SCcobj->Display();
    SCiRet = SCcobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    // LL of float
    cout<<"\n\n-------------- LinkdList of Floats --------------\n\n";

    SinglyCL<float> *SCfobj = new SinglyCL<float>();

    SCfobj->InsertFirst(90.78f);
    SCfobj->InsertFirst(78.99f);
    SCfobj->InsertFirst(67.99f);

    SCfobj->Display();
    SCiRet = SCfobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCfobj->InsertLast(45.67f);
    SCfobj->InsertLast(54.78f);
    SCfobj->InsertLast(77.89f);
    
    SCfobj->Display();
    SCiRet = SCfobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCfobj->InsertAtPos(88.56,5);

    SCfobj->Display();
    SCiRet = SCfobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCfobj->DeleteAtPos(5);
    SCfobj->Display();
    SCiRet = SCfobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    // LL of double

    cout<<"\n\n-------------- LinkdList of Doubles --------------\n\n";

    SinglyCL<double> *SCdobj = new SinglyCL<double>();

    SCdobj->InsertFirst(90.78978);
    SCdobj->InsertFirst(78.99645);
    SCdobj->InsertFirst(67.9934);

    SCdobj->Display();
    SCiRet = SCdobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCdobj->InsertLast(45.67867);
    SCdobj->InsertLast(54.78534);
    SCdobj->InsertLast(77.89324);
    
    SCdobj->Display();
    SCiRet = SCdobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCdobj->InsertAtPos(88.56987,5);

    SCdobj->Display();
    SCiRet = SCdobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

    SCdobj->DeleteAtPos(5);
    SCdobj->Display();
    SCiRet = SCdobj->Count();
    cout<<"Number of elemensts are : "<<SCiRet<<endl;

/////////////////////////////////////////////////////////////
//
//                       Doubly Linear
//
/////////////////////////////////////////////////////////////



cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n-------------------- Doubly Linear Linkd List ----------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";

// LL of integer
    cout<<"\n\n-------------- LinkedList of Integers --------------\n\n";

    DoublyLL <int> *DLiobj = new DoublyLL<int>();
    int DLiRet = 0;

    DLiobj->InsertFirst(51);
    DLiobj->InsertFirst(21);
    DLiobj->InsertFirst(11);

    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLiobj->InsertLast(101);
    DLiobj->InsertLast(111);
    DLiobj->InsertLast(121);
    
    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLiobj->InsertAtPos(105,4);
    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLiobj->DeleteFirst();
    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLiobj->DeleteLast();
    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout << "Number of elements are : " << DLiRet << endl;

    DLiobj->DeleteAtPos(3);
    DLiobj->Display();
    DLiRet = DLiobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    // LL of character
    cout<<"\n\n-------------- LinkedList of Chracters --------------\n\n";

    DoublyLL<char> *DLcobj = new DoublyLL<char>();

    DLcobj->InsertFirst('D');
    DLcobj->InsertFirst('F');
    DLcobj->InsertFirst('R');

    DLcobj->Display();
    DLiRet = DLcobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLcobj->InsertLast('E');
    DLcobj->InsertLast('Y');
    DLcobj->InsertLast('U');
    
    DLcobj->Display();
    DLiRet = DLcobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLcobj->InsertAtPos('W',5);

    DLcobj->Display();
    DLiRet = DLcobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLcobj->DeleteAtPos(5);
    DLcobj->Display();
    DLiRet = DLcobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    // LL of float
    cout<<"\n\n-------------- LinkedList of Floats --------------\n\n";

    DoublyLL<float> *DLfobj = new DoublyLL<float>();

    DLfobj->InsertFirst(90.78f);
    DLfobj->InsertFirst(78.99f);
    DLfobj->InsertFirst(67.99f);

    DLfobj->Display();
    DLiRet = DLfobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLfobj->InsertLast(45.67f);
    DLfobj->InsertLast(54.78f);
    DLfobj->InsertLast(77.89f);
    
    DLfobj->Display();
    DLiRet = DLfobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLfobj->InsertAtPos(88.56,5);

    DLfobj->Display();
    DLiRet = DLfobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLfobj->DeleteAtPos(5);
    DLfobj->Display();
    DLiRet = DLfobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    // LL of double

    cout<<"\n\n-------------- LinkedList of Doubles --------------\n\n";

    DoublyLL<double> *DLdobj = new DoublyLL<double>();

    DLdobj->InsertFirst(90.78978);
    DLdobj->InsertFirst(78.99645);
    DLdobj->InsertFirst(67.9934);

    DLdobj->Display();
    DLiRet = DLdobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLdobj->InsertLast(45.67867);
    DLdobj->InsertLast(54.78534);
    DLdobj->InsertLast(77.89324);
    
    DLdobj->Display();
    DLiRet = DLdobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLdobj->InsertAtPos(88.56987,5);

    DLdobj->Display();
    DLiRet = DLdobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

    DLdobj->DeleteAtPos(5);
    DLdobj->Display();
    DLiRet = DLdobj->Count();
    cout<<"Number of elements are : "<<DLiRet<<endl;

/////////////////////////////////////////////////////////////
//
//                          Doubly Circular
//
/////////////////////////////////////////////////////////////



cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n-------------------- Doubly Circular Linkd List ----------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";
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

/////////////////////////////////////////////////////////////
//
//                      Stack
//
/////////////////////////////////////////////////////////////



cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n----------------------------- Stack ------------------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n\n-------------- Stack --------------\n\n";
    Stack <int> *Sobj = new Stack<int>();
    int iRet = 0;

    Sobj->Push(10);
    Sobj->Push(20);
    Sobj->Push(30);
    Sobj->Push(40);

    Sobj->Display();
    iRet = Sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iRet = Sobj->pop();
    cout<<"Poped element is : "<<iRet<<"\n";
    iRet = Sobj->pop();
    cout<<"Poped element is : "<<iRet<<"\n";

    Sobj->Display();
    iRet = Sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

     Sobj->Push(50);
     Sobj->Display();
    iRet = Sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

/////////////////////////////////////////////////////////////
//
//                      Queue
//
/////////////////////////////////////////////////////////////


cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n----------------------------- Queue ------------------------------\n";
 
cout<<"\n-------------------------------------------------------------------\n";

cout<<"\n\n-------------- Queue --------------\n\n";
    Queue <int> *Qobj = new Queue<int>();
    int QRet = 0;

    Qobj->EnQueue(10);
    Qobj->EnQueue(20);
    Qobj->EnQueue(30);
    Qobj->EnQueue(40);

    Qobj->Display();
    QRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n\n";

    QRet = Qobj->DeQueue();
    cout<<"Removed element is : "<<iRet<<"\n";
    QRet = Qobj->DeQueue();
    cout<<"Removeed element is : "<<iRet<<"\n";

    Qobj->Display();
    QRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n\n";

    Qobj->EnQueue(50);
    Qobj->Display();
    QRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";

    return 0;
}