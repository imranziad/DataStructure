#include <iostream>
using namespace std;

const int Size = 100;

int Data[Size], List[Size];
int Start = -1;

void init()
{
    for(int i = 0; i < Size; i++)
        List[i] = -2;
}

void print()
{
    cout << "Current array: ";

    for(int i = Start; i != -1; i = List[i])
        cout << Data[i] << " ";

    cout << endl;
}

int find_empty()
{
    for(int i = 0; i < Size; i++)
    {
        if(List[i] == -2)
            return i;
    }

    return -1;
}

void Add(int value)
{
    int idx, i;

    idx = find_empty();

    if(Start == -1)
        Start = idx;

    i = Start;

    while( List[i] >- 1 )
        i = List[i];

    Data[idx] = value;
    List[i] = idx;
    List[idx] = -1;
}

void Insert(int k, int val) // 0 based index
{
    int idx, temp, cnt = 1;

    temp = find_empty();

    if(k==0)
    {
        Data[temp] = val;
        List[temp] = List[Start];
        Start = temp;
    }
    else
    {
        idx = Start;

        while(cnt < k)
        {
            idx = List[idx];
            cnt++;
        }

        Data[temp] = val;
        List[temp] = List[idx];
        List[idx] = temp;
    }
}

int main()
{
    init();             // Initializing the list with -2

    Add(5);
    print();
    Add(7);
    print();
    Add(4);
    print();
    Add(3);
    print();
    Add(9);
    print();
    Insert(2,1);
    print();
    Add(4);
    print();
    Add(3);
    print();
    Add(9);
    print();
    Insert(3,10);
    print();
    Add(4);
    print();
    Add(3);
    print();
    Add(9);
    print();
    Insert(13,12);
    print();

    return 0;
}
