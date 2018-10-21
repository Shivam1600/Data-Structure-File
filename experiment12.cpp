#include<iostream>
using namespace std;
int n=4;
void heapify(int arr[],int i,int n)
{
	int l=(2*i)+1;
	int r=(2*i)+2;
	int large;
	if(l<n && arr[l]>arr[i])
		large=l;
	else
	large=i;
	if(r<n && arr[r]>arr[large])
	large=r;
	if(large!=i)
	{
		swap(arr[i],arr[large]);
		heapify(arr,large,n);
	}
}
void build_heap(int arr[])
{
	for(int i=(n-1)/2;i>=0;i--)
	{
		heapify(arr,i,n);
	}
}
void heapsort(int arr[])
{
	int heapsize=n;
	build_heap(arr);
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapsize=heapsize-1;
		heapify(arr,0,heapsize);
	}
}
void swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
