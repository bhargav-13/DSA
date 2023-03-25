#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    cout << "[ ";
    do{
        cout << s.top() << " " << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
        s.pop();
    }while(!s.empty());
    cout << "]";
    cout << endl;
}

void insertatbottom(stack<int> &s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int elm = s.top();
    s.pop();

    insertatbottom(s, num);

    s.push(elm);
}

void reverseStack(stack<int> &stack){
    if(stack.empty()){
        return ;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertatbottom(stack, num);    
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(7);
    s.push(14);
    s.push(21);
    s.push(28);
    print(s);
    reverseStack(s);
    print(s);
    
    return 0;
}
