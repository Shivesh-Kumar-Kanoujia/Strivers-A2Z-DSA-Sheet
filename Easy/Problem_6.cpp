// Left Rotate the Array by K Places

// Problem Statement: Given an integer array nums, rotate the array to the left by K places.

// Example:
// Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
// Output : [6, 7, 1, 2, 3, 4, 5]
// Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
// rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 


// ----------------------------- Code (Optimal Approach) -----------------------------
#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

class Solution{
public: 
    void RotateLeft(vector<int>& nums, int k){
        int n=nums.size();
        reverse(nums.begin(),nums.begin()+k);    // reverse first k elements
        reverse(nums.begin()+k,nums.end());      // reverse remaining n-k elements
        reverse(nums.begin(),nums.end());        // reverse the whole array
    }
};
int main(){
    vector<int> v={1, 2, 3, 4, 5};
    Solution sol;
    sol.RotateLeft(v,3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

