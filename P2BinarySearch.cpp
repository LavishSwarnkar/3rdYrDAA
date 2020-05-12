#include <iostream>

using namespace std;

void binarySearch(int a[], int BEG, int END, int x);

int main()
{   int a[20], size, x, i;

    cout<<"Enter the no. of elements in array: ";
    cin>>size;

    for(i = 0; i < size ; i++) {
        cout<<"A["<<i<<"] = ";
        cin>>a[i];
    }

    cout<<endl<<"Enter element to be searched: ";
    cin>>x;
    binarySearch(a, 0, size-1, x);
    return 0;
}

void binarySearch(int a[], int BEG, int END, int x){
    int MID;
    if(BEG < END) {
        MID = (BEG + END)/2;
        if(a[MID] == x)
            cout<<endl<<x<<" found at index "<<MID;
        else if(a[MID] > x)
            binarySearch(a, BEG, MID-1, x);
        else
            binarySearch(a, MID+1, END, x);
    }
    else
        cout<<endl<<x<<" not found!";
}