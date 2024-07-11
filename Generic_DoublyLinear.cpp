//Generic Doubly linear LinkedList

#include<iostream>
using namespace std;

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

int main()
{
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

    delete DLiobj;
    delete DLcobj;
    delete DLfobj;
    delete DLdobj;

    return 0;
}