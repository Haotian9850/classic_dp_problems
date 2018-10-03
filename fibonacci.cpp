/*
* DP implementation of finding a particular number in large Fibonacci sequence
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;

int fibonacci(int n){
    int dp[n];
    //base cases
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i ++){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main(){
    cout << fibonacci(29) << endl;
}
