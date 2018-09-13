/*
* Top-down DP solution of the wedding shopping problem. Assume given money < 200, number of different garment < 20 and number of options for each garment < 20
*/
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int M;
int C;
int price[25][25];
int dpMatrix[210][25];

int shop(int money, int g){
    if(money < 0){
        return -1;
    }
    if(g == C){
        return M - money;
    }
    if(dpMatrix[money][g] != -1){
        return dpMatrix[money][g];
    }
    int result = -1;
    for(int model = 1; model <= price[g][0]; model ++){
        result = max(result, shop(money - price[g][model], g + 1));
    }
    return dpMatrix[money][g] = result;
}

int main(){
    int i;
    int j;
    int TC;
    int score;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &price[i][0]);
        for(j = 1; j <= price[i][0]; j ++){
            scanf("%d", &price[i][j]);
        }
        memset(dpMatrix, -1, sizeof dpMatrix);
        score = shop(M, 0);
        if(score < 0){
            cout << "No feasible solution" << endl;
        }else{
            cout << score << endl;
        }
    }
}