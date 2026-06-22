// Longest Subarray with given Sum K(Positives)

// Problem Statement: Given an array nums of size n and an integer k,
// find the length of the longest sub-array that sums to k. If no such sub-array
// exists, return 0.

// Example 1:
// Input:
//  nums = [10, 5, 2, 7, 1, 9], k = 15  
// Output:
//  4  

// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(const vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0) return 0;

        int left=0, right=0;
        long long sum = nums[0];
        int maxLen = 0;

        while (right < n) {

            while (sum > k && left <= right) {
                sum -= nums[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;

            if (right < n) {
                sum += nums[right];
            }
        }

        return maxLen;
    }
};

int main() {
    vector<int> v = {10, 5, 2, 7, 1, 9};

    Solution sol;
    cout << sol.longestSubarray(v, 15) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity (Auxiliary): O(1)