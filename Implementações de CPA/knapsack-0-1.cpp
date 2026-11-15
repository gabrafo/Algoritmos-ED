#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if(a>=b) {
        return a;
    }
    return b;
}

int knapsack_0_1(int n, int W, vector<int> v, vector<int> w) {
    int cost[n+1][W+1];

    // casos base
    for(int i = 0; i<n+1; i++){ // i => n
        cost[i][0] = 0; // qualquer linha da primeira coluna vai ter valor zero
    }

    for(int j = 0; j<W+1; j++){ // j => W
        cost[0][j] = 0; // qualquer coluna da primeira linha vai ter valor zero
    }

    for(int i = 1; i<n+1; i++){
        for (int j = 1; j<W+1; j++){
            if (w[i-1] > j) { // n podemos pegar o item
                cost[i][j] = cost[i-1][j]; // melhor solução desconsiderando o item
            } else { // podemos pegar o item
                cost[i][j] = max(cost[i-1][j-w[i-1]] + v[i-1], cost[i-1][j]); // máximo retorno entre considerar ou n o item
            }
        }
    }

    return cost[n][W];
}

int main() {
    int n = 4;
    int W = 6; 
    vector<int> v = {3, 5, 5, 4}; 
    vector<int> w = {3, 4, 2, 3}; 

    int maxValue = knapsack_0_1(n, W, v, w);
    cout << "maxValue: " << maxValue << endl;

    return 0;
}