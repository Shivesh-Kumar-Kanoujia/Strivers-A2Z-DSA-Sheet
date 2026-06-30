// Spiral Traversal of Matrix

// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Example

// Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// ------------------------------------ Code (Optimal Approach) ------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> Spiral(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    vector<int> result = sol.Spiral(matrix);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity (Auxiliary): O(1)
