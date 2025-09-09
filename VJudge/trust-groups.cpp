#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* 
The personnel department of Association of Cookie Monsters (ACM) has noticed that the productivity
of various work groups in the company is not as good as it could be. They have interviewed the
employees in the affected groups and they have detected the root of the problem: trust (or, rather, the
lack thereof). Some employees do not trust the rest of the group, and this is decreasing their motivation
and happiness. The personnel department wants to solve this problem, and has decided to reorganize
the groups so that they are stable, i.e., they are formed by people who trust each other. They have
asked the employees, and they know the people each employee trusts directly. Moreover, if employee
A trusts employee B and employee B trusts employee C, then employee A will trust employee C.

And obviously, each employee trusts himself. They want to create as few groups as possible to reduce
administration overhead (they also do not want to work too hard).
With this information they have contacted you, and asked you to write a program that finds the
minimum number of stable groups that can be created.

Input
The input consists of several test cases. Each test case begins with a line containing two positive
integers P and T (1 ≤ P ≤ 1000, 0 ≤ T ≤ 999000) separated by a single space. P lines come next, each
containing the name of one person. The names will have the following format: surname, a comma, a
space and first name (for example McBride, John or Smith, Peter). Both the surname and the first
name will be strings of uppercase or lowercase characters (with no blanks or punctuation marks), with
a maximum length of 10 characters. There will not be repetitions in the complete names of the people.
After the names there will appear T blocks of 2 lines representing the trust relations between people.
Each line of the block will contain the name of a person in the same format as before, and the block
will mean that the person in the first line trusts the person in the second line. All people appearing in
the confidence relations will have appeared in the previous list of P people.
The input will end with the “phantom” test case ‘0 0’, which must not be processed.

Output
For each test case, the output will be a line containing a positive integer representing the minimum
number of stable groups of people that can be formed.

Sample Input
3 2
McBride, John
Smith, Peter
Brown, Anna

Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna

3 2
McBride, John
Smith, Peter
Brown, Anna

Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0

Sample Output
2
3


Resolução utilizando Kosaraju para contagem de CFCs
*/

#include <vector>
#include <stack>
using namespace std;

// DFS do primeiro passo
void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v, adj, visited, st);
    st.push(u); // Depois de explorar todos os vértices a partir da raiz, adiciona na pilha
}

// DFS no grafo transposto
void dfsTransp(int u, const vector<vector<int>> &transpose, vector<bool> &visited) {
    visited[u] = true;
    for (int v : transpose[u])
        if (!visited[v])
            dfsTransp(v, transpose, visited);
}

// Função principal de Kosaraju
int kosaraju(const vector<vector<int>> &adj) {
    int P = adj.size();
    vector<bool> visited(P, false);
    stack<int> st;

    // Passo 1: DFS no grafo original
    for (int i = 0; i < P; i++)
        if (!visited[i])
            dfs(i, adj, visited, st);

    // Passo 2: construir grafo transposto
    vector<vector<int>> transpose(P);
    for (int u = 0; u < P; u++)
        for (int v : adj[u])
            transpose[v].push_back(u);

    // Passo 3: DFS no grafo transposto
    fill(visited.begin(), visited.end(), false);
    int numCFC = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            dfsTransp(u, transpose, visited);
            numCFC++;
        }
    }
    return numCFC;
}


int main() {
    int P, T;
    vector<int> res;

    while (cin >> P >> T, P || T) {
        cin.ignore(); // consumir \n

        vector<vector<int>> listaAdj(P);
        unordered_map<string, int> nomesPos;

        // Ler nomes das pessoas
        for (int i = 0; i < P; i++) {
            string nome;
            getline(cin, nome);
            nomesPos[nome] = i;
        }

        // Ler relações de confiança
        for (int i = 0; i < T; i++) {
            string u, v;
            getline(cin, u);
            getline(cin, v);
            int a = nomesPos[u];
            int b = nomesPos[v];
            listaAdj[a].push_back(b);
        }

        res.push_back(kosaraju(listaAdj));
    }
    
    for (int r : res) {
      cout << r << endl;
    }

    return 0;
}