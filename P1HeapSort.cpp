#include <iostream>
#include<conio.h>

using namespace std;

void heap_sort(int a[], int size);
void heapify(int a[], int size, int i);

int main()
{   int i, a[10], size;

    cout<<"Enter size of array: ";
    cin>>size;

    for(i=0 ; i<size ; i++)
    {	cout<<"Enter A["<<i+1<<"]: ";
        cin>>a[i];
    }

    cout<<endl<<"Before sorting, Array is ";
    for(i=0 ; i<size ; i++)
        cout<<a[i]<<", ";

    heap_sort(a, size);

    cout<<endl<<"After sorting, Array is ";
    for(i=0 ; i<size ; i++)
        cout<<a[i]<<", ";

    return 0;
}

void heap_sort(int a[], int size)
{   int i, temp;
    for(i=size/2-1 ; i>=0 ; i--)
        heapify(a, size, i);
    for(i=size-1 ; i>=0 ; i--)
    {   temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void heapify(int a[], int size, int i)
{   int largest = i, l, r, temp;
    l = i*2 + 1;
    r = i*2 + 2;
    if(l<size && a[l]>a[largest])
        largest = l;
    if(r<size && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {   temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, size, largest);
    }
}