#include<iostream>
using namespace std;

class Queue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            this-> size = size;
            arr = new int[size];
            front = -1; 
            rear = -1;
        }

        void insert(int data){
            if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = data;
            }
            else if(rear >= 0 && rear < size){
                rear++;
                arr[rear] = data;
            }
            else{
                cout << "Queue Overflow" << endl;
            }
        }

        void Delete(){
            if(front == -1){
                cout << "Queue Underflow" << endl;
            }
            else if(front == rear ){
                front=-1;
                rear=-1;
                cout << arr[front+1] << " element deleted" << endl;
            }
            else{
                front++;
                cout << arr[front-1] << " element deleted" << endl;
            }
        }

        void Display(){
            int i;
            if(front == -1){
                cout << "Queue is empty" << endl;
            }
            else{
            for(i=front; i<=rear; i++){
                cout << arr[i] << " ";
            }
            }
            cout << endl;
        }
};


int main(int argc, char const *argv[])
{
    Queue q(5);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);

    q.Display();

    q.Delete();

    q.Display();
    return 0;
}
