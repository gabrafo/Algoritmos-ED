#include <iostream>

using namespace std;

// Vídeo sobre Counting Sort e Radix Sort: https://www.youtube.com/watch?v=Nz1KZXbghj8

// Padrão: "30 10103538 2222 1233 6160 0142"
// Contabilizei os espaços no LENGTH
const int LENGTH = 31; 

// Como estamos trabalhando com strings...
int getIndex(char ch) {
    if (ch == ' ') return 0;
    return (ch - '0') + 1;
}

// Radix Sort sempre demanda um algoritmo aliado de ordenação, no nosso caso o Counting Sort
// Será um Radix Sort LSD
void countingSort(string arr[], int n, int place){
    string output[n];
    int count[11] = {0};

    // Contagem
    for(int i = 0; i < n; i++){
        int idx = getIndex(arr[i][place]);
        count[idx]++;
    }

    // Acumulado
    for(int i = 1; i < 11; i++){
        count[i] += count[i - 1];
    }

    // Construção do output (de trás pra frente = estável)
    for(int i = n - 1; i >= 0; i--){
        int idx = getIndex(arr[i][place]);
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    // Copiar de volta
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

// Função principal
 void radixSort(string arr[], int n){
    for(int place = LENGTH - 1; place >= 0; place--){
        countingSort(arr, n, place);
    }
}   

int main() {
    int t; // Número de casos de teste
    long n; // Número de contas bancárias do caso de teste a seguir

    cin >> t;
    string resultados[5]; // t ≤ 5

    for(int i = 0; i < t; i++){
        cin >> n;
        cin.ignore();

        string* arr = new string[n];
        for(int j = 0; j < n; j++) {
            getline(cin, arr[j]);
        }

        // Lendo linha vazia
        string lixo;
        getline(cin, lixo);

        radixSort(arr, n);

        string saida = ""; // String de output
        int count = 1; // Contador
        
        // Contagem de repetições + append pra string de output
        for(int z = 1; z < n; z++) {
            if(arr[z] == arr[z - 1]) {
                count++;
            } else {
                saida += arr[z - 1] + to_string(count) + "\n";
                count = 1;
            }
        }

        saida += arr[n - 1] + to_string(count) + "\n";

        resultados[i] = saida;

        delete[] arr;
    }

    for(int i = 0; i < t; i++){
        cout << resultados[i];
        if(i < t - 1) cout << endl;
    }      
    cout << endl;

    return 0;
}
