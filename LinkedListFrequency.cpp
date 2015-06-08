#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Root = NULL;
int array[100][2];

void AddValue(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = tempnode;
	}
}
void AddFirst(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else
	{
		tempnode->next = Root;
		Root = tempnode;
	}
}
void RemoveFirst()
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else
	{
		Root = Root->next;
	}
}
void RemoveLast()
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else if(Root->next == NULL)
	{
		Root = NULL;
	}
	else
	{
		Node* t = Root;
		while(t->next->next != NULL)
		{
			t = t->next;
		}
		t->next = NULL;
	}
}

void RemoveValue(int value)
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else if(Root->data == value)
	{
		Root = Root->next;
		//RemoveFirst();
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL && t->next->data != value)
		{
			t = t->next;
		}
		if(t->next == NULL)
		{
			cout << "Not found" << endl;
		}
		else
		{
			t->next = t->next->next;
		}
	}
}
void print()
{
	cout << "Current List: ";
	Node* t = Root;
	while(t != NULL)
	{
		cout << t->data << " -> ";
		t = t->next;
	}
	cout << endl;
}

int search(int start, int size, int value)
{
    if(start >= size)
        return -1;
    if(array[start][0] == value)
        return start;

    return search(start + 1, size, value);
}

void printFrequency()
{
	Node* t = Root;
	int x, idx, cnt;

    cnt = 0;

	while(t != NULL)
	{
	    x = t->data;
	    idx = search(0, cnt, x);

		if(idx == -1)
		{
            array[cnt][0] = x;
            array[cnt][1] = 1;
            cnt++;
		}
		else
            array[idx][1]++;

        t = t->next;
	}

	for(int i = 0; i < cnt; i++)
        cout << array[i][0] << " - " << array[i][1] << endl;

	cout << endl;
}

int main()
{
	AddValue(2);
	print();
	AddValue(2);
	print();
	AddValue(7);
	print();
	AddValue(5);
	print();
	AddValue(7);
	print();
	AddValue(2);
	print();
	printFrequency();
/*
	RemoveFirst();
	print();
	RemoveLast();
	print();
	RemoveValue(16);
	print();
	RemoveValue(100);
	print();
*/
	return 0;
}
