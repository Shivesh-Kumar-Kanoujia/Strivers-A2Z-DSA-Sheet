// Union of Two Sorted Arrays

// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

// The union of two arrays can be defined as the common and distinct elements in the two arrays.

// NOTE: Elements in the union should be in ascending order.

// Examples
// Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
// Output: {1,2,3,4,5}
// Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5}

// ----------------------------- Code (Optimal Approach) -----------------------------

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> Union;

        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                if (Union.empty() || Union.back() != nums1[i])
                    Union.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                if (Union.empty() || Union.back() != nums2[j])
                    Union.push_back(nums2[j]);
                j++;
            }
            else
            {
                if (Union.empty() || Union.back() != nums1[i])
                    Union.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        while (i < n)
        {
            if (Union.empty() || Union.back() != nums1[i])
                Union.push_back(nums1[i]);
            i++;
        }

        while (j < m)
        {
            if (Union.empty() || Union.back() != nums2[j])
                Union.push_back(nums2[j]);
            j++;
        }

        return Union;
    }
};

int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr2 = {2,3,4,4,5,11,12};

    Solution obj;
    vector<int> result = obj.findUnion(arr1, arr2);

    cout << "Union of arr1 and arr2 is: ";

    for (int val : result)
        cout << val << " ";

    return 0;
}

// Time Complexity: O(n+m)
// Auxiliary Space Complexity: O(1)