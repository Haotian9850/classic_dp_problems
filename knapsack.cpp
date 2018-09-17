/*
* Knapsack problem: a problem in combinational optimization
* Given a set of items each with a mass w and value v, determine the number of each item to include
* in a collection so that the total weight M is less than or equal to a given limit and total value
* is as large as possible.
* DP implementation:  O(n * W)
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int numOfItems = 3;
int capacityOfKnapSack = 6;
int knapsackTable[4][7];
int totalBenefit;
int weight[] = {1, 2, 3};
int values[] = {60, 100, 120};

void solve(){
    for(int i = 1; i < numOfItems + 1; i ++){
        for(int w = 1; w < capacityOfKnapSack + 1; w ++){
            int notTakingItem = knapsackTable[i - 1][w];
            int takingItem = 0;
            if(weight[i] <= w){
                takingItem = knapsackTable[i - 1][w - weight[i]] + values[i];
            }
            knapsackTable[i][w] = max(notTakingItem, takingItem);
        }
    }
    totalBenefit = knapsackTable[numOfItems][capacityOfKnapSack];
}

void showResult(){
    cout << "Maximum benefit: " << totalBenefit << endl;
    for(int n = numOfItems, w = capacityOfKnapSack; n > 0; n --){
        if(knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n - 1][w]){
            cout << "Take item" << " " << n << endl;
            w -= weight[n];
        }
    }
}

int main(){
    solve();
    showResult();
}