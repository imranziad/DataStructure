#include <bits/stdc++.h>
using namespace std;

char *a = new char [1];
int top=-1,size=1;

void resize()
{
    size = size * 2;
    char *b = new char [size];
    for(int i=0; i<=top; i++)
        b[i] = a[i];
    delete []a;
    a = b;
}
void push(char val)
{
    if(top+2>=size)
        resize();
    top++;
    a[top] = val;
}
void pop()
{
    if(top>-1)
        top--;
}

int main()
{
    int i,len;
    char s[1000];
    bool flag=true;

    cin >> s;

    len = strlen(s);

    for(i=0; i<len; i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
           push(s[i]);
        else if(top>-1 && (s[i]==')' || s[i]=='}' || s[i]==']') )
        {
            if(a[top]=='(' && s[i]==')')
                pop();
            else if(a[top]=='{' && s[i]=='}')
                pop();
            else if(a[top]=='[' && s[i]==']')
                pop();
            else
                break;
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            flag = false;
            break;
        }
    }

    if(top>-1 || flag==false)
        cout << "Syntax Error!" << endl;
    else
        cout << "Syntax Correct!" << endl;

    return 0;
}

// ertor
