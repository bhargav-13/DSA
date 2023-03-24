#include<bits/stdc++.h>
using namespace std;


void print (int arr[], int n)
{
    
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
        if(i<n-1){
            cout << ", ";
        }
    }
    cout << endl;
}

int insertion(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int x = arr[i];
        while(arr[j]>x  &&  j>-1)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 98, 4, 87, 56, 1, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    print(arr,size);

    insertion(arr, size);
    cout << "Sorted:- ";
    print(arr, size);
    return 0;
}
