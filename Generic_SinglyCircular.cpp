//generic singly circular LinkedList

#include <iostream>
using namespace std;

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

int main() 
{
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
    return 0;
}
