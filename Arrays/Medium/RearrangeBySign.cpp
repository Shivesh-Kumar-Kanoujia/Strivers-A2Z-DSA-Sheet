// Rearrange Array Elements by Sign

/*
Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, you must return an array of alternately 
positive and negative values.
*/ 

// Example 1:
// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output:
// 1 -4 2 -5

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
public:
    // Place positives at even indices and negatives at odd indices.
    vector<int> RearrangeBySign(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n,0);
        int posInd=0,negInd=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negInd]=nums[i];
                negInd+=2;
            }

            else{
                ans[posInd]=nums[i];
                posInd+=2; 
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v = {1,2,-4,-5};
    Solution sol;
    vector<int> v1 = sol.RearrangeBySign(v);
    for(int i: v1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity (Auxiliary): O(n)