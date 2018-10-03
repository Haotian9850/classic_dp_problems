#include <iostream>
#include <cstdlib>
using namespace std;

/*Asumming 1 or 2 stairs each time*/

int numStairs(int n){
    int dp[n + 2];
    //base cases
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i ++){
        //state transition
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n + 1];   //last index: result
}

int main(){
    cout << numStairs(29) << endl;
}