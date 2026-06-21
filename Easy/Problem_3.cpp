// //  Check if an Array is Sorted
// //  Problem Statement: Given an array of size n, write a program to check if the given array is sorted in
//     (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, 
//     Else 
//     return False.

// Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: True.
// Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next
//              values, So the answer is True.


// ----------------------------- Code (Optimal Approach) -----------------------------
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public: 
    bool isSorted(vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    vector<int> v={10,20,30,40,50};
    Solution sol;
    bool sort = sol.isSorted(v);
    cout<<sort<<endl;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

