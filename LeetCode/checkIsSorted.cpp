#include <bits/stdc++.h>
using namespace std;



bool check(vector<int>& nums) {
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            cnt++;
        }
    }
    if(nums[n-1]>nums[0]){
        cnt++;
    }
    return cnt<=1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,4,5,1,2};

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ", ";
    }

    cout << endl;
    

     cout << check(nums) << endl;


    return 0;
}
