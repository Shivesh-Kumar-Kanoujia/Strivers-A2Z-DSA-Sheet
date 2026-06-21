// Remove Duplicates in-place from Sorted Array

// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place 
// such that each unique element appears only once. The relative order of the elements should be kept the same.

// If there are k elements after removing the duplicates, then the first k elements of the array should hold the 
// final result. It does not matter what you leave beyond the first k elements.

// Input: arr[]=[1,1,2,2,2,3,3]
// Output: [1,2,3,_,_,_,_]
// Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3]
// in the beginning of the array.


// ----------------------------- Code (Optimal Approach) -----------------------------
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public: 
    int removeDuplicate(vector<int>& nums){
        int i=0;
        int n=nums.size();
        if(nums.empty()){
            return 0;        // Array is Empty
        }
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;        // index of last unique element
    }
};
int main(){
    vector<int> v={1,1,2,2,2,3,3};
    Solution sol;
    int k = sol.removeDuplicate(v);   // Storing index upto Unique elements
    for(int i=0;i<k;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

