#include<bits/stdc++.h>
using namespace std;

string isPalindrome(string s){
    bool flag = false;
    int len = s.length();

    if(len == 1){
        return s;
    }

    if(len == 2){
        if(s[0] == s[1]){
            return s;
        }
    }

    int mid = len/2;
    int l = mid-1;
    int r = len%2 == 0 ? mid : mid+1;
    int anslen = 0;
    while(l >= 0){
        if(s[l] == s[r]){
            flag = true;
            anslen = r-l;
        }
        else{
            flag = false;
            break;
        }
        l--;
        r++;
    }

    return s.substr(l, anslen);
}

// string longestPalindrome(string s){
//     int i=0, j=0; 
//     string ans="";

//     while(j <= s.length()){
//         string s1 = s.substr(i, j-i+1);
//         if(isPalindrome(s1)){
//             ans = s1.length() > ans.length() ? s1 : ans;
//         }
//         if(j == s.length()){
//             i++;
//             j = i;
//         }
//         else{
//             j++;
//         }
        
//     }
//     return ans;
// }

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    cout << isPalindrome(s);

    return 0;
}
