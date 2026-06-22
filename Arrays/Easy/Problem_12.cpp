// Find the number that appears once, and the other numbers twice

// Problem Statement: Given a non-empty array of integers arr, every element 
// appears twice except for one. Find that single one.

// Example 1:
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and 
// so it is the answer.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int getsingleElement(const vector<int>& nums){
        int xorr = 0;       // Initializing xorr
        for(int i=0;i<nums.size();i++){
            xorr = xorr ^ nums[i];       // Apllying XOR
        }
        return xorr;                 // returning the XOR of all elements
    }
};

int main(){
    vector<int> v={4, 1, 2, 1, 2};
    Solution Sol;
    int k = Sol.getsingleElement(v);
    cout<<k<<endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity (Auxiliary): O(1)