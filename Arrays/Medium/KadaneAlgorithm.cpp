// Kadane's Algorithm : Maximum Subarray Sum in an Array

// Problem Statement: Given an integer array nums, find the subarray with the largest sum and 
// return the sum of the elements present in that subarray.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input:
//  nums = [2, 3, 5, -2, 7, -4]  
// Output:
//  15  

// ------------------------------------ Code (Optimal Approach) ------------------------------------------
// Kadane's Algorithm

#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
public:
    long long MaxSubArray(const vector<int>& nums){
        if(nums.empty()) return 0;
        long long maxi=LLONG_MIN;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            // Updating maxi if current sum is greater
            if(sum>maxi){
                maxi = max(maxi,sum);
            }
            // resetting sum to zero when it becomes negative
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;   // return maximum sum 
    }
};

int main(){
    vector<int> v={2, 3, 5, -2, 7, -4};
    Solution Sol; 
    int k= Sol.MaxSubArray(v);
    cout<<k<<endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

