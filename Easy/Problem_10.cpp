// Find the Missing Number

// Problem Statement: Given an array arr[] of size n-1 with distinct integers in the range of [1, n].
// This array represents a permutation of the integers from 1 to n with one
// element missing. Find the missing element in the array.

// Examples
// Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
// Output: 6
// Explanation: All the numbers from 1 to 8 are present except 6.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& nums){        
        int sum=0,n=nums.size()+1;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];      // Summing elements of array
        }
        long long expSum= (n*1LL*(n+1))/2;  // Expected Sum 
        return expSum-sum;     // returning Missing Number
    }
};
int main(){
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
    Solution Sol;
    cout << Sol.missingNumber(arr);  
    return 0;
}

// Time Complexity: O(n) (Linear)
// Space Complexity (Auxiliary): O(1)