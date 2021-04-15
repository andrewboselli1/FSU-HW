#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node(T v);
    T getVal();
    void setVal(T v);
    Node<T>* getNext();
    void setNext(Node<T>*);
    
private:
    T val;
    Node<T> *next;
};

template <class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void print();
    bool isEmpty();
    int size();
    void clear();
    void addElement(T value);
    Node<T> popElement();
    bool balanceStack(const T *array,int);
    void addBeginning(T value);
    
private:
    Node<T> *head,*top;
};

template <class T>
Node<T>::Node(T v)
{
    val = v;
    next = NULL;
}
template <class T>
T Node<T>::getVal()
{
    return val;
}
template <class T>
void Node<T>::setNext(Node<T> *node)
{
    next = node;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
Stack<T>::Stack()
{
    head= NULL;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if(head==NULL)
        return true;
    return false;
}

template <class T>
int Stack<T>::size()
{
    int num=0;
    Node<T> *cur = head;
    while(cur!=NULL)
    {
        num++;
        cur=cur->getNext();
    }
    return num;
}

template <class T>
void Stack<T>::addElement( T value)
{
    Node<T> *cur, *incoming;
    incoming = new Node<T>(value);
    
    cur = head;
    if(cur == NULL)
    {
        head=incoming;
        return;
    }
    
    while(cur->getNext() !=NULL)
    {
        cur = cur->getNext();
    }
    
    cur->setNext(incoming);
    top=cur;
}

template <class T>
void Stack<T>::print()
{
    Node<T> *cur = head;
    while(cur!=NULL)
    {
        cout<<cur->getVal()<<"\t";
        cur=cur->getNext();
    }
    cout<<endl;
}

template <class T>
void Stack<T>::clear()
{
    Node<T> *cur,*el;
    cur=head;
    while(cur!=NULL)
    {
        el = cur;
        cur = cur->getNext();
        delete el;
    }
    head= NULL;
}

template <class T>
Stack<T>::~Stack()
{
    if(head != NULL)
        clear();
}
template <class T>
Node<T> Stack<T>::popElement()
{
    Node<T> *cur, *ans;
    cur=head;
    while(cur->getNext()!=NULL)
    {
        cur=cur->getNext();
    }
    ans=nullptr;
    ans->setVal(cur->getVal());
    
    delete cur;
    return ans->getVal();
    
    
}
template <class T>
void Node<T>::setVal(T v)
{
    val=v;
}
template <class T>
bool Stack<T>::balanceStack(const T *array, int size)
{
    T be;
    T an;
    Node<T> *cur;
    cur=head->getNext();
    addElement(array[0]);
    an=array[0];
    for (int i = 1; i <size ; i++)
    {
        addElement(array[i]);
        be=array[i];
        if(an!=be)
        {
            while(cur->getNext()!=NULL)
            {
                cur =  cur->getNext();
            }
            if(cur->getVal()==an) {
                popElement();
            }
            else
                break;
        }
    }
    if(isEmpty())
        return true;
    else
        return false;
}
template <class T>
void Stack<T>::addBeginning(T value)
{
    Node<T> *cur, *incoming,*temp;
    incoming = new Node<T>(value);
    
    cur = head;
    if(cur == NULL)
    {
        head=incoming;
        return;
    }
    head=incoming;
    while(cur->getNext() !=NULL)
    {
        temp=cur;
        cur = cur->getNext();
        temp->setNext(temp);
    }
    delete incoming;
}

