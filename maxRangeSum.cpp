/*
* Maximum range sum problem: Given an integer array, determine the maximum range sum of A
* DP / greedy implementation
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int n = 9;
int a[] = {4, -5, 4, -3, 4, 4, -4, 4, -5};

int solve(){
    int result = 0;
    int temp = 0;
    for(int i = 0; i < n; i ++){
        temp += a[i];
        result = max(result, temp);
        if(temp < 0){
            temp = 0;    //reset
        }
    }
    return result;
}

int main(){
    cout << solve() << endl;
}