// Count Maximum Consecutive One's in the array

// Problem Statement: Given an array that contains only 1 and 0 return the 
// count of maximum consecutive ones in the array.

// Example 1:
// Input: prices = {1, 1, 0, 1, 1, 1}
// Output: 3
// Explanation: There are two consecutive 1’s and three consecutive 1’s in the
//  array out of which maximum is 3.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int countOnes(vector<int>& nums){
        int cnt=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;       // Increasing count if one is found
            }
            else if(nums[i]==0){
                cnt=0;       // resetting count as streak is ended and starting again from 0
            }
            maxi=max(maxi,cnt);    // Comparing and Choosing Maximum value of count
        }
        return maxi;        // returning Maximum Count of Consecutives 1's
    }
};

int main(){
    vector<int> v={1, 1, 0, 1, 1, 1};
    Solution Sol;
    int k = Sol.countOnes(v);
    cout<<k<<" ";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity (Auxiliary): O(1)