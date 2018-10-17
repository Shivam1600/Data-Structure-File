#include <iostream>
using namespace std;
#define Size 10
class stack1
{
    int arr[Size];
    int top;
public:
    stack1()
    {

        top=-1;
    }
    void push(int);
    void pop();
    void display();
};
void stack1::display()
{

 cout<<top;
}
void stack1::push(int x)
{
top++;
    if(top==Size)
    {
        cout<<"Stack Overflow";

    }
    arr[top]=x;
}
void stack1::pop()
{

    if(top==-1)
    {

        cout<<"stack underflow";

    }
    top--;
}
int main()
{
    stack1 s;
    int n,i;int num;
    int ch;
     cout<<"1.Push"<<endl<<"2.pop"<<endl<<"3.display top"<<endl;
     cin>>ch;
    while(ch!=4)
    {
    switch(ch)
    {
    case 1:
        cin>>num;
        s.push(num);
        cout<<endl;
    break;
    case 2:
    s.pop();
    break;
    case 3:s.display();
    break;
    default:ch=4;
    }
    cin>>ch;
    }
    return 0;
}
