#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack{
    T *a = new T [1];
    int sz,t;           // t = top, sz = size
protected:
    void resize();      // resize stack when needed
public:
    Stack();            // initialize size,top
    void push(T val);   // push value to the stack
    void pop();         // pop from stack
    void print();       // print full stack
    int size();         // get number of elements
    T top();            // get the top element
    bool empty();       // check if the stack is empty
};

template <class T>
Stack<T>::Stack()
{
    sz = 1;
    t = -1;
}

template <class T>
void Stack<T>::resize()
{
    sz *= 2;
    T *b = new T [sz];
    for(int i=0; i<=t; i++)
        b[i] = a[i];
    delete []a;
    a = b;
}

template <class T>
void Stack<T>::push(T val)
{
    if(t+1==sz)
        resize();
    t++;
    a[t] = val;
}

template <class T>
void Stack<T>::pop()
{
    if(t>-1)
        t--;
}

template <class T>
void Stack<T>::print()
{
    cout << "Current stack: ";
    for(int i=0; i<=t; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
int Stack<T>::size()
{
    return t+1;
}

template <class T>
T Stack<T>::top()
{
    return a[t];
}

template <class T>
bool Stack<T>::empty()
{
    if(t<0) return true;
    return false;
}

int main()
{
    Stack <string> s;

    s.push("abc");
    s.print();
    s.push("bcd");
    s.print();
    s.push("efg");
    s.print();
    s.pop();
    s.print();
    s.push("xyz");
    s.print();
    s.push("pqr");
    s.print();

    cout << s.top() << endl;

    return 0;
}
