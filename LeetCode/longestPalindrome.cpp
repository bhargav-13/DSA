// Given a string s, return the longest palindromicsubstringin s.


#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){

    int n = s.size();

    if(n == 0)
        return "";
    
    if(n == 1)
        return s;

    int minStart = 0, maxLen = 0;
    
       

}


int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}
