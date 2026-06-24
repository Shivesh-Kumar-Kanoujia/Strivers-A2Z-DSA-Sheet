// Sort an array of 0s, 1s and 2s

// Problem Statement: Given an array nums consisting of only 0, 1, or 2. 
// Sort the array in non-decreasing order. The sorting must be done in-place, 
// without making a copy of the original array.

// Examples
// Input: nums = [1, 0, 2, 1, 0]
// Output: [0, 0, 1, 1, 2]
// Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

// ----------------------------- Code (Optimal Approach) -----------------------------
//  Dutch National Flag Algorithm

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution{
public:
    void sortZeroOneTwo(vector<int>& nums){
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
            else if(nums[mid]==1)mid++;
            else{
                swap(nums[mid],nums[mid]);
                high--;
            }
        }
    }
};

int main(){
    vector<int> v= {1, 0, 2, 1, 0};
    Solution Sol;
    Sol.sortZeroOneTwo(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}