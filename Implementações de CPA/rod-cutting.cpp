#include <limits>
#include <iostream>
using namespace std;

struct result {
    int r;
    int s;
};

int max(int a, int b){
    if(a>=b) {
        return a;
    }
    return b;
}

int rod_cut_dynamic_programming(int n, int p[]){
    int r[n+1];
    r[0] = 0;
    for(int j = 1; j<n+1; j++){
        r[j] = numeric_limits<int>::min(); // representando infinito, menor valor de int possivel
        for (int i = 1; i<=j; i++){
            r[j] = max(r[j], p[i] + r[j-i]);
        }
    }
    return r[n]; // lucro máx
}

void rod_cut_dynamic_programming_path(int n, int p[], result res[]){ // res é param de saida, vai ficar nele os dados
    res[0].r = 0;
    for(int j = 1; j<n+1; j++){
        res[j].r = numeric_limits<int>::min(); // representando infinito, menor valor de int possivel
        for (int i = 1; i<=j; i++){
            res[j].r = max(res[j].r, p[i] + res[j-i].r);
            res[j].s = i;
        }
    }
}

int main(){
    int n;

    while (cin >> n && n != 0) {
        int element[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> element[i];
        }
        // int bestProfit = rod_cut_dynamic_programming(n, element);
        // cout << bestProfit << endl;
        result res[n+1];
        rod_cut_dynamic_programming_path(n, element, res);
        cout << "results" << endl;
        for (int i = 1; i <= n; i++) {
            cout << res[i].r << " ";
        }
        cout << endl;
        cout << "best cut position" << endl;
        for (int i = 1; i <= n; i++) {
            cout << res[i].s << " ";
        }
    }

    return 0;
}