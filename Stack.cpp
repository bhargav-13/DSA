#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int elm){
        if(top < size-1){
        top++;
        arr[top] = elm;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    void print(){
        while(top != -1){
            cout << arr[top] << " "<< flush;
            top--;
        }
    }


};

int main(int argc, char const *argv[])
{
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.push(3);

    st.print();    
    return 0;
}
