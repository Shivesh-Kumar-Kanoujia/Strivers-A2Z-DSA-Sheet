// Rotate Image by 90 degree

// Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees
// clockwise. The rotation must be done in place, meaning the input 2D matrix must be modified
// directly.

// Examples
// Input :
// matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output :
// matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void RotateClockwise(vector<vector<int>> &nums)
    {
        int n = nums.size();
        // Transposing Matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(nums[i][j], nums[j][i]);
            }
        }
        // reversing each row
        for (int i = 0; i < n; i++)
        {
            reverse(nums[i].begin(), nums[i].end());
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution sol;
    sol.RotateClockwise(matrix);
    for (auto row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n*n)
// Space Compleixty: O(1)