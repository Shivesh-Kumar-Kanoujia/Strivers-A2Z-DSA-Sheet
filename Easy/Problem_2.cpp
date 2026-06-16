//  Second Largest Element
//  Problem Statement: Given an array of integers nums, return the second-
// largest element in the array. If the second-largest element does not exist,
//  return -1.

// Example 1:

// Input:
//  arr[] = {2, 5, 1, 3, 0}  

// Output:
//  3

// Explanation:
// 5 is the largest element in the array.

// ----------------------------- Code (Optimal Approach) -----------------------------
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public: 
    int SecondLargestElement(vector<int> nums){
        if(nums.size()<2){
            return -1; // No Maximum Element as Array is Empty.
        }
        int maxi = INT_MIN;
        int maxi2= INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi2 = maxi;
                maxi = nums[i];
            }
            else if(nums[i]>maxi2 && nums[i]!= maxi){
                maxi2=nums[i];
            }
        }
        return maxi2;      // Returning Maximum Element
    }
};
int main(){
    vector<int> v={10,20,50,30,40};
    Solution sol;
    int Max = sol.SecondLargestElement(v);
    cout<<Max<<endl;
}

