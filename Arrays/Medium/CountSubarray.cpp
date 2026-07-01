// Count Subarray sum Equals K

// Problem Statement: Given an array of integers and an integer k, return the total number of 
// subarrays whose sum equals k. A subarray is a contiguous non-empty sequence of elements 
// within an array.

// Examples
// Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
// Output: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

// ------------------------------------ Code (Optimal Approach) ------------------------------------------

#include <iostream>
#include <vector>
#include<unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        // Initialize with prefix sum 0 occurring once
        mpp[0]=1;
        int preSum=0;
        int cnt=0;     // Stores total number of valid subarrays
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            int remove=preSum-k;   // calculating required sum
            cnt+=mpp[remove];      // adding the count if the required sum exists
            mpp[preSum]+=1;        // Store/update the current prefix sum frequency
        }
        return cnt;
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    Solution sol;
    int result = sol.subarraySum(arr, k);
    cout << "The number of subarrays is: " << result << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)