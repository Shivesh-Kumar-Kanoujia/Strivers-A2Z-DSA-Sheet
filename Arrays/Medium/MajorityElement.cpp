// Find the Majority Element that occurs more than N/2 times


// Problem Statement: Given an integer array nums of size n, return the majority element 
// of the array.

// The majority element of an array is an element that appears more than n/2 times 
// in the array. The array is guaranteed to have a majority element.

// Examples
// Input:
//  nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
// Output:
//  7  

// ----------------------------- Code (Optimal Approach) -----------------------------
//Moore Voting Algorithm

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution{
public:
    int majorityElement(const vector<int>& nums){
        int n=nums.size();
        int cnt=0,ele;   // Count and Element
        for(int i=0;i<n;i++){
            if(cnt==0 ){           
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else cnt--;
        }
        // Verifying whether the stored element is the majority element
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele)count++;
        }
        if(count>(n/2)){
            return ele;
        }
        return -1;
    }
};

int main(){
    vector<int> v={7, 0, 0, 1, 7, 7, 2, 7, 7};
    Solution Sol;
    int maj = Sol.majorityElement(v);
    cout<<"Majority Element: "<<maj<<endl;
    return 0;
}

// Time Complexity: O(2n)
// Space Complexity: O(1)