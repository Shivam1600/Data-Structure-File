#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int a[100];
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int choice,flag=1;
	cout<<"Press 1 to insert an element at a specified position"<<endl<<"Press 2 to delete an element whose position is given"<<endl<<"Press 3 to find the location of an element"<<endl<<"Press 4 to display the elements of the linear array"<<endl<<"Press 5 to exit the menu"<<endl;
	cin>>choice;
	while(choice!=5)
	{
		switch(choice)
		{
			case 1:
				cout<<"Enter the element you want to enter"<<endl;
				int b;
				cin>>b;
				cout<<"Enter the location at which you want to insert the element"<<endl;
				int pos;
				cin>>pos;
				for(int i=n;i>=pos-1;i--)
				{
					a[i]=a[i-1];
				}
				a[pos-1]=b;
				n++;
				break;
			case 2:
				cout<<"Enter the position from which you want to delete the element"<<endl;
				int p;
				cin>>p;
				for(int i=p-1;i<n;i++)
				{
					a[i]=a[i+1];
				}
				n--;
			break;
			case 3:
				cout<<"Enter the element whose location you want to find in the linear array"<<endl;
				int c;
				cin>>c;
				for(int i=0;i<n;i++)
				{
					if(c==a[i])
					{
						cout<<"The element is present in "<<i+1<<" position"<<endl;
			            flag=0;
					}
				}
				if(flag==1)
				cout<<"Element is not present in the array"<<endl;
				break;
			case 4:
				for(int i=0;i<n;i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<endl;
			break;
		}
		cout<<"Press 1 to insert an element at a specified position"<<endl<<"Press 2 to delete an element whose position is given"<<endl<<"Press 3 to find the location of an element"<<endl<<"Press 4 to display the elements of the linear array"<<endl;
		cin>>choice;
	}
	return 0;
}
