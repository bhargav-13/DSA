#include<bits/stdc++.h>
using namespace std;

void ReverseString(string &name,int i, int j)
{
   
   if(i>j){
    return ;
   }
   swap(name[i],name[j]);
   i++;
   j--;
   return ReverseString(name,i,j);
}

int main(int argc, char const *argv[])
{
    string name = "bhargav";
    
    ReverseString(name, 0 ,name.length()-1);
    cout << name << endl;

    return 0;
}
