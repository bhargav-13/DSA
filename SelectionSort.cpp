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

void Selsort(int arr[], int n){
    for(int i=0; i<n-1; i++)
    {
        int minindex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minindex]){
                
                minindex = j;
            }
            // cout << arr[j] << endl;
        }
        swap (arr[minindex], arr[i]);
        
    }

    
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,8,15,2,6,89};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "array is: ";
    print(arr,size);
    cout << endl;
    Selsort(arr,size);
    cout << "Soted array is: ";
    print(arr,size);
    return 0;
}
