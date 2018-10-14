#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void insertEnd(struct Node** start, int value)
{

    if (*start == NULL)
    {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    Node *last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;

    new_node->next = *start;


    (*start)->prev = new_node;


    new_node->prev = last;


    last->next = new_node;
}
void insertBegin(struct Node** start, int value)
{

    struct Node *last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
    *start = new_node;
}

void insertAfter(struct Node** start, int value1,int value2)
{
    struct Node* new_node = new Node;
    new_node->data = value1;
    Node *p;
    p=*start;
    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;


    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}


void display(struct Node* start)
{
    struct Node *temp = start;
    while (temp->next != start)
    {
       cout<< temp->data;
        temp = temp->next;
    }
    cout<< temp->data;

}
void deleteNode(struct Node **start, int key)
{

    if (*start == NULL)
        return;

    struct Node *curr = *start, *prev_1 = NULL;
    while (curr -> data != key)
    {
        if (curr->next == *start)
        {
            cout<<"\nList doesn't have node with value"<<key;
            return;
        }

        prev_1 = curr;
        curr = curr -> next;
    }

    if (curr -> next == *start && prev_1 == NULL)
    {
        (*start) = NULL;

        return;
    }

    if (curr == *start)
    {

        prev_1 = (*start) -> prev;


        *start = (*start) -> next;


        prev_1 -> next = *start;
        (*start) -> prev = prev_1;

    }


    else if (curr->next == *start)
    {

        prev_1 -> next = *start;
        (*start) -> prev = prev_1;

    }
    else
    {

        struct Node *temp = curr -> next;


        prev_1 -> next = temp;
        temp -> prev = prev_1;

    }
}
int searchList(struct Node* start, int search)
{

    struct Node *temp = start;

    int count=0,flag=0,value;


    if(temp == NULL)
        return -1;
    else
    {

        while(temp->next != start)
        {

            count++;

            if(temp->data == search)
            {
                flag = 1;
                count--;
                break;
            }

            temp = temp->next;
        }

        if(temp->data == search)
        {
            count++;
            flag = 1;
        }

        if(flag == 1)
            cout<<"\n"<<search <<" found at location "<<
                                            count<<endl;
        else
            cout<<"\n"<<search <<" not found"<<endl;
    }
}

int main()
{

    struct Node* start = NULL;
    int ch=1;

	cout<<"1.Insert a new element at the beginning 2.end 3. in-between the given list"<<endl;
cout<<"4.Delete an existing element"<<endl;
cout<<"5.Search an element"<<endl;
cout<<"6.Display all the elements "<<endl;
int num,rep;
    while(ch!=7)
    {
        cin>>ch;
        switch(ch)
        {
            case 1:cin>>num;
            insertBegin(&start,num);
            break;
            case 2:cin>>num;
            insertEnd(&start,num);break;
            case 3:cin>>num;cin>>rep;
            insertAfter(&start,num,rep);break;
            case 4:cout<<"enter the number to delete";
                cin>>num;
                deleteNode(&start,num);break;
            case 5:cout<<"enter the number to search";
            cin>>num;
                searchList(start,num);break;
            case 6:display(start);
            break;
            default:ch=7;

        }

    }


    return 0;
