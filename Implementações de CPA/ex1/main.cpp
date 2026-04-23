#include <iostream>
#include <vector>

using namespace std;

// Retorna o índice da faixa de premiação para uma dada pontuação.
// É uma busca binária.
int findPrizeIndex(const vector<long long>& G1, long long score, int left, int right) {
    if (left >= right) {
        return left;
    }

    int mid = left + (right - left) / 2;
    if (score < G1[mid]) {
        return findPrizeIndex(G1, score, left, mid);
    }
    return findPrizeIndex(G1, score, mid + 1, right);
}

int main() {
    int N; // Número de faixas de premiação.
    int M; // Número de alunos competidores.

    cin >> N >> M;

    vector<long long> G1(N - 1); // Faixas de pontuação. Se for [100, 200, 300], teremos 4 faixas: <100, >=100 <200, >=200 <300, >=300.
    for (int i = 0; i < N - 1; i++) {
        cin >> G1[i];
    }

    vector<long long> F(N); // Valores dos prêmios, 1 p/ cada faixa.
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    vector<long long> G2(M); // Pontuação dos alunos.
    for (int i = 0; i < M; i++) {
        cin >> G2[i];
    }

    // Divisão e conquista
    for (int i = 0; i < M; i++) {
        int prizeIndex = findPrizeIndex(G1, G2[i], 0, N - 1);

        if (i > 0) {
            cout << ' ';
        }
        cout << F[prizeIndex];
    }
    cout << '\n';

    return 0;
}
