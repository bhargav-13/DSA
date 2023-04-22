#include<iostream>
#include<thread>
using namespace std;

class heap{
    public:
        int arr[100];
        int size = 0;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int i = size;
            arr[i] = val;

            while(i > 1){
                int parents = i/2;
                if(arr[i]> arr[parents]){
                    swap(arr[i],arr[parents]);
                    i = parents;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
                this_thread::sleep_for(chrono::milliseconds(300));
            }
            cout << endl;
        }

        void deletefromHeap(){
            if(size == 0){
                cout << "Nothing to Delete" << endl;
                return ;                 
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i<size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex <size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i = leftIndex;
                }
                if(rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] <= arr[rightIndex]){
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else{
                    return ; 
                }
            }
        }
};

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left <= n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;

        while(size > 1){
            swap(arr[size], arr[1]);

            size--;

            heapify(arr, size, 1);
        }
    }


int main(int argc, char const *argv[])
{
    heap h;
    h.insert(50);
    h.insert(5);
    h.insert(53);
    h.insert(54);
    h.insert(60);
    h.insert(55);

    h.deletefromHeap();

    h.print();

    int arr[] = {-1,50,5,53,54,60,55};
    int n = sizeof(arr) / sizeof(arr[0])-1;
    
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    } 
    
    cout << endl;
    cout << "printing array now using heapify:" << endl;
    for(int i=1; i<n+1; i++){
        cout << arr[i] << " ";
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << endl << endl;

    cout << "sorted array using HeapSort:" << endl;;
    heapSort(arr, n);
    for(int i=1; i<n+1; i++){
        cout << arr[i] << " ";
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    // h.print();
    return 0;
}
