#include <iostream>
using namespace std;
int Max = INT32_MIN, Min = INT32_MAX;
int a[] = {1000, 11, 4450, 1, 330, 3000};
void max_min(int i, int j);
int main()
{   int n = sizeof(a)/sizeof(a[0]);
    max_min(0, n - 1);
    cout<<"Min = "<<Min<<endl;
    cout<<"Max = "<<Max<<endl;
    return 0;
}

void max_min(int i, int j)
{   if(i==j){
        Max = Min = a[i];
    } else if(i==j-1){
        if(a[i] < a[j]){
            Max = a[j];
            Min = a[i];
        } else {
            Max = a[i];
            Min = a[j];
        }
    } else {
        int mid = (i+j)/2;
        max_min(i, mid);

        int max1 = Max, min1 = Min;
        max_min(mid+1, j);

        if(Max < max1) Max = max1;
        if(Min > min1) Min = min1;
    }
}