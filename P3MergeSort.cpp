#include <iostream>
#include<conio.h>

using namespace std;

void merge_sort(int a[], int beg, int end);
void merge(int a[], int beg, int mid, int end);

int main()
{   int i, a[10], size;

    cout<<"Enter the no. of elements in array: ";
    cin>>size;

    for(i = 0; i < size ; i++) {
        cout<<"A["<<i<<"] = ";
        cin>>a[i];
    }

    cout<<endl<<"Before sorting, Array is ";
    for(i=0 ; i<size ; i++)
        cout<<a[i]<<", ";

    merge_sort(a, 0, size-1);

    cout<<endl<<"After sorting, Array is ";
    for(i=0 ; i<size ; i++) {
        cout<<a[i]<<", ";
    }

    return 0;
}

void merge_sort(int a[], int beg, int end)
{   int mid;
    if(beg<end)
    {   mid = (beg+end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

void merge(int a[], int beg, int mid, int end)
{   int i=beg, j=mid+1, index=beg, temp[20];
    while(i<=mid && j<=end)
    {   if(a[i]<a[j])
            temp[index++]=a[i++];
        else
            temp[index++]=a[j++];
    }
    if(i>mid)
        while(j<=end)
            temp[index++]=a[j++];
    else
        while(i<=mid)
            temp[index++]=a[i++];
    for(i=beg ; i<index ; i++)
        a[i]=temp[i];
}