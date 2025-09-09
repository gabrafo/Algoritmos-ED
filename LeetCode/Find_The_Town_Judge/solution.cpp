#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> score(n+1, 0);
            for (auto vertex : trust) {
                int a = vertex[0]; // primeiro número do par (quem confia)
                int b = vertex[1]; // segundo número do par (em quem confia)
                score[a]--;   // a perde ponto (tem aresta de saída)
                score[b]++;   // b ganha ponto (tem aresta de entrada)
            }      
            
            for (int i = 1; i <= n; i++) {
                if (score[i] == n-1) {
                    return i; // achou o juiz
                }
            }

            return -1;
    };
};