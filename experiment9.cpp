/*
A program to accept N numbers in an array, and then sort the array using Quick Sort.
*/
#include<iostream>
using namespace std;
void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = Partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        cout<<arr[i]<<endl;
    cout<<endl;
}
int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
    cout<<"Sorted array: "<<endl;
    printArray(arr, n);
    return 0;
}
