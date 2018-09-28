/*
* This is a Leetcode question! --> Best Time to Buy and Sell Stock III, only 2 transactions permitted
* DP implementation: using locally optimal choice to construct globally optimal choice
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<int> prices = {7, 1, 5, 3, 6, 4};
int total = 6;

int solve(){
    if(prices.empty()){
        return 0;
    }
    int len = prices.size();
    int global[6][3] = {0};
    int local[6][3] = {0};
    for(int i = 1; i < len; i ++){
        int diff = prices[i] - prices[i - 1];
        for(int j = 1; j <=2; j ++){
            local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
            global[i][j] = max(local[i][j], global[i - 1][j]);
        }
    }
    return global[len - 1][2];  //at most 2 transactions are allowed
}

int main(){
    solve();
}