// Length of the longest subarray with zero Sum

// Problem Statement: Given an array containing both positive and negative integers,
// we have to find the length of the longest subarray with the sum of all elements 
// equal to zero.

// Example 1:
// Input:
//  N = 6, array[] = {9, -3, 3, -1, 6, -5}  
// Result:
//  5  
// Explanation:
//  The following subarrays sum to zero:
// - {-3, 3}
// - {-1, 6, -5}
// - {-3, 3, -1, 6, -5}
// The length of the longest subarray with sum zero is 5

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    int longestSubarray(const vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> mpp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            // if sum is zero, subarray [0..i] has zero sum
            if(sum==0){
                maxi=i+1;       // update best length
            }
            //checking if this sum has appeared before
            else{
                // when seen, zero-sum segment between previous index + 1 and i
                if(mpp.find(sum)!=mpp.end()){
                    maxi=max(maxi,i-mpp[sum]);
                }
                // first time seeing this sum
                else{
                    // record index
                    mpp[sum]=i;
                }
            }
        }
        return maxi;      // returning maximum length of subarray with sum 0
    }
};

// Time Complexity: O(n)
// Space Complexity (Auxiliary): O(n)