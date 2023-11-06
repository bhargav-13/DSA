#include <bits/stdc++.h>
using namespace std;

pair<long int, long int> findDev(long int n){
    int min_el = n-1;
     
    pair<long int, long int> p;
    p.first = 1;
    p.second = n;

    long int i=1;
    long int j=n;
    long int k = 2;

    while(i < j ){

        if(j%k == 0){
            
            j = j/k;
            i = i*k;
            
            cout << "if:" << i <<" " << j << endl;
            if(abs(j-i) < min_el){
                p.first = i;
                p.second = j;
                cout << p.first << " " << p.second << endl;

                min_el =j-i;
            }

            cout << "Min:" << min_el << endl;
        }

        else{
            k++;
        }
    }

    cout << p.first << " " << p.second << endl;

    return p;
}

vector<long int> closestDevisior(long int n){
    vector<long int> ans;

    long int min_ans1 = INT_MIN;
    long int min_ans2 = INT_MIN;

    pair<long int, long int> p1 = findDev(n+1);
    min_ans1 = p1.first - p1.second;


    pair<long int, long int> p2 = findDev(n+2);
    min_ans2 = p2.first - p2.second;


    if(abs(min_ans1) < abs(min_ans2)){
        ans.push_back(p1.first);
        ans.push_back(p1.second);
    }
    else{
        ans.push_back(p2.first);
        ans.push_back(p2.second);
    }

    return ans;

} 

int main(int argc, char const *argv[])
{
    int n;
    cout << endl <<  "enter Num: ";
    cin >> n;

        vector<long int> v;
        v = closestDevisior(n); 
        for (auto elem : v) {
            cout << elem << " ";
    }
    

    return 0;
}
