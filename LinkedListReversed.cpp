#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Root = NULL;

void AddLast(int value)
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
void AddSorted(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else if(value < Root->data)
	{
		tempnode->next = Root;
		Root = tempnode;
		//AddFirst(value);
	}
	else if(Root->next == NULL)
	{
		Root->next = tempnode;
		//AddLast(value);
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL && t->next->data < value)
		{
			t = t->next;
		}
		if(t->next == NULL)
		{
			t->next = tempnode;
			//AddLast(value);
		}
		else
		{
			tempnode->next = t->next;
			t->next = tempnode;
		}
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

void Reverse()
{
    if(Root == NULL || Root->next == NULL)
        return ;

    Node *t;
    Node *temp;
    Node *v;

	t = Root->next;
	temp = t->next;
	Root->next = NULL;
	t->next = Root;

	while( temp != NULL  )
	{
        v = temp->next;
        temp->next = t;
        t = temp;
        temp = v;
	}

    Root = t;
}

void pp(Node *t)
{
    if(t != NULL)
    {
        cout << t->data << " -> ";
        pp(t->next);
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

int main()
{
	AddSorted(14);
	print();
	AddSorted(19);
	print();
	AddSorted(12);
	print();
	AddSorted(16);
	print();
	AddSorted(17);
	print();
	AddSorted(11);
	print();
	AddSorted(13);
	print();
	AddSorted(15);
	print();
	Reverse();
	print();

	//pp(Root);

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
