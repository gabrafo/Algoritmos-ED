#include <iostream>
#include <vector>

using namespace std;

// Função para intercalar dois sub-vetores e contar as inversões
long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Índice inicial para o sub-vetor da esquerda
    int j = mid + 1; // Índice inicial para o sub-vetor da direita
    int k = left;    // Índice inicial para o vetor temporário
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Se arr[i] > arr[j], então há inversões.
            // Todos os elementos restantes na metade esquerda (de i até mid)
            // são maiores que arr[j].
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    // Copia os elementos restantes da esquerda, se houver
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copia os elementos restantes da direita, se houver
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copia o vetor temporário de volta para o original
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

// Função recursiva do Merge Sort
long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }
    return count;
}

int main() {
    int n;

    // Leitura e Merge Sort (0 é o fim do programa)
    while (cin >> n && n != 0) {
        vector<int> a(n);
        vector<int> temp(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long result = mergeSort(a, temp, 0, n - 1);
        
        cout << "Minimum exchange operations : " << result << endl;
    }

    return 0;
}
