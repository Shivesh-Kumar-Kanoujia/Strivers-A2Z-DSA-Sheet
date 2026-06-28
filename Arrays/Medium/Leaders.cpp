// Leaders in an Array

// Problem Statement: Given an array of positive integers arr[] of size N, find all the 
// leaders in the array.

// An element is called a leader if it is greater than or equal to all the elements to its 
// right side. The rightmost element is always a leader, since there are no elements to its right.

// Return the leaders in the same order in which they appear in the array.

// Example:

// Input:
//  arr = [4, 7, 1, 0]  
// Output:
//  7 1 0  
// Explanation:
//  The rightmost element (0) is always a leader.  
// 7 and 1 are greater than the elements to their right, making them leaders as well.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> Leaders(vector<int> nums){
        vector<int> ans;
        int n=nums.size();
        if(nums.empty()){
            return ans;
        }
        int maxi=nums[n-1];
        ans.push_back(maxi);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=maxi){
                ans.push_back(nums[i]);
                maxi=nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    vector<int> v = {4, 7, 1, 0};
    Solution sol;
    vector<int> v1 = sol.Leaders(v);
    for(int num:v1){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

// Time Complexity : O(n)
// Space Complexity (Auxiliary) : O(n);

