// Linear Search in C

// Problem Statement: Given an array, and an element num the task is to find if num is present in the given array 
// or not. If present print the index of the element or print -1.

// Example 1:
// Input:
//  arr[] = 1 2 3 4 5, num = 3  
// Output:
//  2


// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

class Solution{
public: 
    int LinearSearch(vector<int> nums,int x){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                return i;          // returning index of the matched element
            }
        }
        return -1;                 // element not found

    }
};
int main(){
    vector<int> v={10,20,30,40,50};
    Solution sol;
    int k=sol.LinearSearch(v,30);
    cout<<k<<endl;
}


// Time Complexity: O(n)
// Space Complexity: O(1)