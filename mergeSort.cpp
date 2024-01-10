#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high ){

    vector<int> temp;

    int left = low;
    int right = mid+1;

    while( left <= mid && right <= high ){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
            left++;
    }

     while(right <= high){
       temp.push_back(arr[right]);
            right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

}


void mergeSort(vector<int> &arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, mid,  e);

}

int main() {

    vector<int> arr = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}