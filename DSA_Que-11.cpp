#include<iostream>
#include<stack>
using namespace std;

bool BalancedBracket(string s){
    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(ch);
        }

        else
        {
        
            if(!st.empty()){
                char top = st.top();
                if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      st.pop();
                }
                else
                 {
                     return false;
                 }   
            }
            else{
                return false;
            }
        }
    }
    
    if(st.empty()){

        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter Brackets :" ;
    cin >> s;
    
    if(BalancedBracket(s)){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not Balanced" << endl;
    }
        
    
    return 0;
}
