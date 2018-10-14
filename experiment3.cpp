#include<iostream>
using namespace std;
int search_binary(int a[], int l, int r, int x)
{
    int m=0;
     if (r >= l)
   {
        int mid = l + (r - l)/2;


        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return search_binary(a, l, mid-1, x);
        return search_binary(a, mid+1, r, x);
   }
 return -1;
}
int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	cout<<"The array after sorting is"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int num;
	cout<<"Enter the number you want to search using binary search"<<endl;
	cin>>num;
	int result;
	result=search_binary(a,0,n-1,num);
    if(result==-1)
      cout<<"Number not found"<<endl;
    else
    cout<<"Number found at index "<<result<<endl;
	return 0;
}
