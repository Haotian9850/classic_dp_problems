/*
* DP implementation of finding a particular number in large Fibonacci sequence
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, int> dpTable = {{0, 0}}, {1, 1}};    //first & second base case

int solve(int n){
    if(dpTable.count(n) == 1){
        
    }

}

