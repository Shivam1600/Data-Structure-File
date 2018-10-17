/*
A program to accept N numbers in an array, and then sort the array using Insertion Sort.
 Then accept a number from the user and insert it in the array according to the sequential order
*/
#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       cout<< arr[i]<<"\t";
   cout<<endl;
}

int main()
{
 int n;
 int arr[100];
 cout<<"enter length of array"<<endl;
 cin>>n;
 cout<<"enter the array"<<endl;
 for(int i=0;i<n;i++)
 {
     cin>>arr[i];
 }
 cout<<"sorted array:"<<endl;
    insertionSort(arr, n);
     printArray(arr, n);
    int num;
    cout<<"insert element";
    cin>>num;

   arr[n]=num;
   n=n+1;
   cout<<"After insertion sorted array:"<<endl;
   insertionSort(arr,n);
    printArray(arr, n);

    return 0;
}
