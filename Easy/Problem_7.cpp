// Move all Zeros to the end of the array

// Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the 
// end of the array and move non-negative integers to the front by maintaining their order.

// Examples
// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order


// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

class Solution{
public: 
    void moveZeros(vector<int>& nums){
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                j=i;       // placing j at first zero
                break;
            }
        }
        if(j==-1)return;            // No zeros found
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);    // Swapping zero and non-zero element
                j++;                      // Moving j to next zero
            }
        }      
    }
};
int main(){
    vector<int> v={1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    Solution sol;
    sol.moveZeros(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}