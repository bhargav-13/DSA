#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    int countR=0,countD=0,countU=0,countL=0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == 'R'){
            countR += 1;
        }
        else if(s[i] == 'L'){
            countL += 1;
        }
        else if(s[i] == 'U'){
            countU += 1;
        }
        else{
            countD += 1;
        }
    }

    if((countR == countL) && (countU == countD)){
        cout <<  "true";
    }
    else{
        cout << "false";
    }

    return 0;
}
