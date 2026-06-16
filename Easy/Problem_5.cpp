// Left Rotate the Array by One

// Problem Statement: Given an integer array nums, rotate the array to the left by one.

// Example 1:
// Input:
//  nums = [1, 2, 3, 4, 5]  
// Output:
//  [2, 3, 4, 5, 1]  
// Explanation:
//  Initially, nums = [1, 2, 3, 4, 5]  
// Rotating once to the left results in nums = [2, 3, 4, 5, 1].


// ----------------------------- Code (Optimal Approach) -----------------------------
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public: 
    void RotateByOne(vector<int>& nums){
        int n=nums.size();
        int k=nums[0];              // Storing first element in temporary variable
        for(int i=1;i<n;i++){
            nums[i-1]=nums[i];      // Shifting element to left by one places
        }
        nums[n-1]=k;                // Putting back first element at last
    }
};
int main(){
    vector<int> v={1, 2, 3, 4, 5};
    Solution sol;
    sol.RotateByOne(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

