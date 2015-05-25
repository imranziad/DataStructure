#include <bits/stdc++.h>
using namespace std;

int *a = new int [1];
int size=1,f=0,r=0;

void resize()
{
    int i,k;
    int *b = new int [size * 2];

    for(i=0,k=f; k<r; i++,k++)
        b[i] = a[k%size];

    size = size * 2;
    delete []a;
    a = b;
    r = r-f;
    f = 0;
}

void print()
{
    cout << "Current Queue: ";

    for(int i=f; i<r; i++)
        cout << a[i%size] << " ";

    cout << endl;
}

void enqueue(int val)
{
    if(r-f>=size)
        resize();

    a[r%size] = val;
    r++;

    print();
}

void dequeue()
{
    if(f>=r)
        cout << "Can not dequeue. Queue full!" << endl;
    else
        f++;

    if(f>=size)
    {
        f = f % size;
        r = r % size;
    }

    print();
}

int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(4);
    enqueue(6);
    enqueue(9);
    enqueue(1);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(3);
    enqueue(8);
    enqueue(2);
    enqueue(5);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    cout << "Queue Capacity: " << size << endl;

    return 0;
}

