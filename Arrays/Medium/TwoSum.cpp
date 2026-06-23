// Two Sum : Check if a pair with given sum exists in Array

// Problem Statement: Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum 
// is equal to the target. Otherwise, return NO.

// 2nd variant: Return indices of the two numbers such that their 
// sum is equal to the target. Otherwise, we will return {-1, -1}

// Example
// Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
// Output : YES
// Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first 
// variant for second variant output will be : [1,3].

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution{
public:
    // Variant-1
    string TwoSum(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        int sum=0;
        sort(nums.begin(),nums.end());
        while(left<right){
            sum=nums[left]+nums[right];
            if(sum>target){
                right--;
            }
            else if(sum<target)left++;
            else
            return "YES";
        }
        return "NO";
    }
    // Variant-2
    vector<int> twoSum(vector<int>& nums,int target){
        int n=nums.size();
        map<int,int> mpp ;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int more=target-num;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[num]=i;
        }
        return {-1,-1};
    }
};
int main(){
    vector<int> v= {2,6,5,8,11};
    Solution Sol;
    string ans= Sol.TwoSum(v,14);
    cout<<ans<<endl;
}

// Time Complexity:  Variant-1: O(nlog(n)) Variant-2: O(n)
// Space Complexity (Auxiliary): O(1)