#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter size of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int num;
	cout<<"Enter the number you want to search in the array"<<endl;
	cin>>num;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		if(num==a[i])
		{
			cout<<"Number found at "<<i<<"th index"<<endl;
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"Number not found"<<endl;
	}
	return 0;
}
