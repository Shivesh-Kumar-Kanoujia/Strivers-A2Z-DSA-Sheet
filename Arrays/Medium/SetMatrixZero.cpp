// Set Matrix Zero

// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to
// set its entire column and row to 0 and then return the matrix..

// Examples
// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool zeroinFirstCol = false;
        for (int row = 0; row < matrix.size(); row++)
        {
            if (matrix[row][0] == 0)
                zeroinFirstCol = true;
            for (int col = 1; col < matrix[0].size(); col++)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for (int row = matrix.size() - 1; row >= 0; row--)
        {
            for (int col = matrix[0].size() - 1; col >= 1; col--)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
            if (zeroinFirstCol)
            {
                matrix[row][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    sol.setZeroes(v);
    for (auto row : v)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(m * n)
// Space Complexity: O(1)