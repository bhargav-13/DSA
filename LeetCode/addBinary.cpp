#include <bits/stdc++.h>
using namespace std;

void checklength(string &a, string &b ){
    while(a.length() > b.length()){
        b.insert(0, "0");
    }
    while(a.length() < b.length()){
        a.insert(0, "0");
    }

}

string addBinary(string a, string b){

    string ans;

        if(a.length() == 0){
            return b;
        }
        if(b.length() == 0){
            return a;
        }

        checklength(a, b);
        int len = a.length();
        
        int v = 0;
        for(int i=len-1; i>=0; i--){
            int n = (a[i]-'0')+(b[i]-'0')+v;
            if(n == 2){
                ans.append("0");
                v = 1;
            }
            else if(n == 0){
                ans.append("0");
                v=0;
            }
            else if(n == 3){
                ans.append("1");
                v = 1;
            }
            else{
                ans.append("1");
                v=0;
            }
        }

        if(v != 0){
            ans.append(to_string(v));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a;
    cin >> b;

    cout << addBinary(a, b);

    return 0;
}


// Input: a = "11", b = "1"
// Output: "100"

// Input: a = "1010", b = "1011"
// Output: "10101"