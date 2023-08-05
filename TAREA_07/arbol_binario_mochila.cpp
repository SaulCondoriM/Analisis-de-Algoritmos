#include <bits/stdc++.h>
using namespace std;

struct Item {
    int beneficio;
    int peso;
};

int pesoMaximo;

bool comp(Item a, Item b) {
    double r1 = (double)a.beneficio / a.peso;
    double r2 = (double)b.beneficio / b.peso;
    return r1 > r2;
}

int bound(Item arr[], int n, int nivel, int pesoActual, int beneficioActual) {
    if (pesoActual >= pesoMaximo) return 0;

    int maxBeneficio = beneficioActual;
    int totPeso = pesoActual;

    for (int i = nivel; i < n; i++) {
        totPeso += arr[i].peso;
        if (totPeso <= pesoMaximo) {
            maxBeneficio += arr[i].beneficio;
        } else {
            return beneficioActual + (1 - (double)(totPeso - pesoMaximo) / arr[i].peso) * arr[i].beneficio;
        }
    }
    return maxBeneficio;
}

int mochilaBacktracking(Item arr[], int n, int nivel, int pesoActual, int beneficioActual, int maxBeneficio) {
    if (nivel == n) return maxBeneficio;

    int incluido = 0;
    if (pesoActual + arr[nivel].peso <= pesoMaximo) {
        incluido = mochilaBacktracking(arr, n, nivel + 1, pesoActual + arr[nivel].peso, beneficioActual + arr[nivel].beneficio, max(maxBeneficio, beneficioActual + arr[nivel].beneficio));
    }

    int noIncluido = mochilaBacktracking(arr, n, nivel + 1, pesoActual, beneficioActual, maxBeneficio);
    return max(incluido, noIncluido);
}

int main() {
    Item arr[] = { {2, 1}, {3, 2}, {4, 3}, {5, 4} };
    int n = 4;
    pesoMaximo = 7;

    sort(arr, arr + n, comp);

    cout << "El beneficio maximo es " << mochilaBacktracking(arr, n, 0, 0, 0, 0) << endl;

    return 0;
}
