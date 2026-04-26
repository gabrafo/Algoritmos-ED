#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int b;
    if (!(cin >> b)) return; // Lê a quantidade de viagens

    for (int r = 1; r <= b; ++r) {
        int s;
        cin >> s; // Lê a quantidade de paradas

        // Variáveis para guardar a MELHOR rota encontrada até agora
        int soma_maxima = 0;
        int melhor_inicio = -1;
        int melhor_fim = -1;

        // Variáveis para a rota que estamos testando AGORA
        int soma_atual = 0;
        int inicio_atual = 1;

        for (int i = 1; i < s; ++i) {
            int niceness;
            cin >> niceness;

            soma_atual += niceness;

            // CASO 1: Encontramos uma soma maior que a máxima, então atualizamos a melhor rota
            if (soma_atual > soma_maxima) {
                soma_maxima = soma_atual;
                melhor_inicio = inicio_atual;
                melhor_fim = i + 1; // i + 1 porque o trecho i vai até a parada i + 1
            } 
            // CASO 2: Empate de soma! A regra diz para escolher o caminho mais longo
            else if (soma_atual == soma_maxima && soma_maxima > 0) {
                int tamanho_atual = (i + 1) - inicio_atual;
                int melhor_tamanho = melhor_fim - melhor_inicio;
                
                if (tamanho_atual > melhor_tamanho) {
                    melhor_inicio = inicio_atual;
                    melhor_fim = i + 1;
                }
            }

            // CASO 3: A soma ficou negativa.
            // Se um caminho acumulou mais coisas ruins do que boas, ele só vai piorar o futuro.
            // Então, "jogamos fora" esse trecho e começamos a contar de novo na próxima parada.
            if (soma_atual < 0) {
                soma_atual = 0;
                inicio_atual = i + 1;
            }
        }

        // Se a soma_maxima for maior que zero, achamos um caminho legal
        if (soma_maxima > 0) {
            cout << "The nicest part of route " << r << " is between stops " << melhor_inicio << " and " << melhor_fim << "\n";
        } else {
            // Se não, nenhum caminho valeu a pena
            cout << "Route " << r << " has no nice parts\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
