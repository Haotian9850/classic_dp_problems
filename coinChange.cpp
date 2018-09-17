/*
* Coin change problem: given a set of coins each with a different value and a total
* amount M, how many ways the coins can be combined in order to get the total M (coins 
* can be reused & order does not matter)?
*DP implementation
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int dpTable[9][41];
int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int M = 40;

void solve(){
    for(int i = 0; i < sizeof(values)/sizeof(values[0]); i ++){
        dpTable[i][0] = 1;
    }
    for(int i = 1; i < M; i ++){
        dpTable[0][i] = 1;
    }
    for(int i = 1; i <= sizeof(values)/sizeof(values[0]); i ++){
        for(int j = 1; j <= M; j ++){
            if(values[i - 1] <= j){
                dpTable[i][j] = dpTable[i - 1][j] + dpTable[i][j - values[i - 1]];  //takind the coin
            }else{
                dpTable[i][j] = dpTable[i - 1][j];  //not taking the coin
            }
        }
    }
    cout << "Solution: " << dpTable[sizeof(values)/sizeof(values[0])][M] << endl; 
}

int main(){
    solve();
}
