#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        // Construindo lista de adjacência
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // BFS bidirecional 
        unordered_set<int> sFrontier = {source};
        unordered_set<int> dFrontier = {destination};
        unordered_set<int> visitedS = {source};
        unordered_set<int> visitedD = {destination};

        while (!sFrontier.empty() && !dFrontier.empty()) {
            // Expande sempre o menor frontier para otimização
            if (sFrontier.size() > dFrontier.size()) {
                swap(sFrontier, dFrontier);
                swap(visitedS, visitedD);
            }

            unordered_set<int> nextFrontier;

            for (int node : sFrontier) {
                for (int neigh : graph[node]) {
                    if (visitedS.count(neigh)) continue;       // já visitado deste lado
                    if (visitedD.count(neigh)) return true;    // clusters se encontram

                    visitedS.insert(neigh);
                    nextFrontier.insert(neigh);
                }
            }

            sFrontier = move(nextFrontier);
        }

        return false;
    }
};
