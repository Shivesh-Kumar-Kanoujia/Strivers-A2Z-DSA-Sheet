// Stock Buy And Sell

// Problem Statement: You are given an array of prices where prices[i] is the price of a 
// given stock on an ith day. You want to maximize your profit by choosing a single day 
// to buy one stock and choosing a different day in the future to sell that stock. 
// Return the maximum profit you can achieve from this transaction. If you cannot achieve 
// any profit, return 0.

// Example
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note: That buying on day 2 and selling on day 1 is not allowed because you must buy 
// before you sell.

// ----------------------------- Code (Optimal Approach) -----------------------------

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
public:
    int StockBuySell(const vector<int>& prices){
        int minPrice = INT_MAX;   // Initialize the minimum price to a large number
        int maxProfit = 0;    // Initializing maximum profit to 0
        for(int price : prices){
            // Updating minPrice if the minPrice is greater than current Price
            minPrice=min(minPrice,price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;      // returning the maximum profit
    }
};

int main(){
    vector<int> v = {7,1,5,3,6,4};
    Solution Sol;
    int prof = Sol.StockBuySell(v);
    cout<<prof<<endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)