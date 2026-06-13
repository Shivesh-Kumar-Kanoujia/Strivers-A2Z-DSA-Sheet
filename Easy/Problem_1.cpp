//  Find the Largest element in an array
//  Problem Statement: Given an array, we have to find the largest element in the array.

// Example 1:
// Input:
//  arr[] = {2, 5, 1, 3, 0}  
// Output:
//  5  
// Explanation:
  
// 5 is the largest element in the array.

// ----------------------------- Code (Optimal Approach) -----------------------------
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public: 
    int LargestElement(vector<int> nums){
        if(nums.empty()){
            return -1; // No Maximum Element as Array is Empty.
        }
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return maxi;      // Returning Maximum Element
    }
};
int main(){
    vector<int> v={10,20,50,30,40};
    Solution sol;
    int Max = sol.LargestElement(v);
    cout<<Max<<endl;
}

