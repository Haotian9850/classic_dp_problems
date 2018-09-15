/*
* Subset Sum: given a set S of integers, is there a non-empty subset whose sum is a given number?
* This is a NP-complete problem!
* Also a special case of knapsack problem...
* Below is the DP implementation of Subset Sum problem
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> S;
int sum;
bool dpTable[5][9];

void solve(){
    /*initialize DP table*/
    for (int i = 0; i < S.size(); i ++){
        dpTable[i][0] = true;
    }
    for(int rowIndex = 1; rowIndex < S.size() + 1; rowIndex ++){
        for(int columnIndex = 1; columnIndex < sum + 1; columnIndex ++){
            if(columnIndex < S[rowIndex - 1]){
                dpTable[rowIndex][columnIndex] = dpTable[rowIndex - 1][columnIndex];
            }else{
                if(dpTable[rowIndex - 1][columnIndex]){
                    dpTable[rowIndex][columnIndex] = dpTable[rowIndex - 1][columnIndex];    //copy value from cell above
                }else{
                    dpTable[rowIndex][columnIndex] = dpTable[rowIndex - 1][columnIndex - S[rowIndex - 1]];
                }
            }
        }
    }
    cout << "Solution: " << dpTable[S.size()][sum] << endl;
}

int main(){
    S.push_back(5);
    S.push_back(2);
    S.push_back(3);
    S.push_back(1);
    solve();
}