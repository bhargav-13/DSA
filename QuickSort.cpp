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

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[s], arr[pivotindex]);

    int i=s, j=e;
    while(i < pivotindex && j > pivotindex){
        while(arr[i] < pivot){
        i++;
        }

        while(arr[j] > pivot){
        j--;
        }

        swap(arr[i], arr[j]);
        i++;
        j--;
        
    }
    return pivotindex; 
}

void Quicksort(int arr[], int s, int e){
       if(s >= e){
        return ;
       }
       int p = partition(arr,s, e);
       Quicksort(arr,s, p-1);
       Quicksort(arr,p+1, e);

}

int main(int argc, char const *argv[])
{
    int arr[] = {5,5,3,10000,8,15,2,6,89};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "array is: ";
    print(arr,size);
    cout << endl;
    Quicksort(arr,0,size-1);
    cout << "Soted array is: ";
    print(arr,size);
    return 0;
}
