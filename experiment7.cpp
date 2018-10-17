/*
Menu driven Program to demonstrate the implementation of various operations on a Circular queue
 (using a linear array and  a linked list)
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* link;
};

struct Queue_linked
{
    struct Node *Front, *rear;

};
class Queue
{
    int rear, f;
    int Size;
    int arr[100];
    public:
    Queue()
    {
       f = rear = -1;
       Size = 5;
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};
void Queue::enQueue(int value)
{
    if ((f == 0 && rear == Size-1) ||
            (rear == (f-1)%(Size-1)))
    {
        cout<<"\nQueue is Full";
        return;
    }

    else if (f == -1)
    {
        f = rear = 0;
        arr[rear] = value;
    }

    else if (rear == Size-1 && f != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}
int Queue::deQueue()
{
    if (f == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[f];
    arr[f] = -1;
    if (f == rear)
    {
        f = -1;
        rear = -1;
    }
    else if (f == Size-1)
        f = 0;
    else
        f++;

    return data;
}
void Queue::displayQueue()
{
    if (f == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
   cout<<"\nElements in Circular Queue are: ";
    if (rear >= f)
    {
        for (int i = f; i <= rear; i++)
            cout<<arr[i];
    }
    else
    {
        for (int i = f; i < Size; i++)
            cout<< arr[i];

        for (int i = 0; i <= rear; i++)
            cout<< arr[i];
    }
}

void enqueue(Queue_linked *q, int value)
{
    struct Node *temp = new Node;
    temp->data = value;
    if (q->Front == NULL)
        q->Front = temp;
    else
        q->rear->link = temp;

    q->rear = temp;
    q->rear->link = q->Front;
}

int dequeue(Queue_linked *q)
{
    if (q->Front == NULL)
    {
        cout<<"Queue is empty";
        return INT_MIN;
    }


    int value;
    if (q->Front == q->rear)
    {
        value = q->Front->data;

        q->Front = NULL;
        q->rear = NULL;
    }
    else
    {
        struct Node *temp = q->Front;
        value = temp->data;
        q->Front = q->Front->link;
        q->rear->link= q->Front;

    }

    return value ;
}

void displayqueue(struct Queue_linked *q)
{
    struct Node *temp = q->Front;
    cout<<"\nElements in Circular Queue are: ";
    while (temp->link != q->Front)
    {
        cout<< temp->data;
        temp = temp->link;
    }
    cout<< temp->data;
}
int main()
{
    int ch=1;int num;
    Queue qu;
    Queue_linked *q = new Queue_linked;
    q->Front = q->rear = NULL;
    cout<<"1.enqueue using array"<<endl<<"2.dequeue using array"<<endl<<"3.display using array"<<endl<<"4.enqueue using linked list"<<endl<<"5.dequeue using linked list"<<endl<<"6.display using linked list"<<endl;
    while(ch!=7)
    {
        cin>>ch;
        switch(ch)
        {
           case 1:cin>>num;
               qu.enQueue(num);break;
               case 2:qu.deQueue();
               break;
               case 3:qu.displayQueue();
               break;
               case 4:cin>>num;
               enqueue(q,num);
               break;
               case 5:dequeue(q);
               break;
               case 6:displayqueue(q);break;
        }
    }
    return 0;
}
