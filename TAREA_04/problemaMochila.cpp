#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int peso;
    int beneficio;
    double ratio;
    int indice;
};

bool comparar(Objeto a, Objeto b) {
    return a.ratio > b.ratio;
}

vector<Objeto> crearObjetos(vector<int> pesos, vector<int> beneficios, int n) {
    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {
        objetos[i].peso = pesos[i];
        objetos[i].beneficio = beneficios[i];
        objetos[i].ratio = double(beneficios[i]) / pesos[i];
        objetos[i].indice = i;
    }
    return objetos;
}

pair<int, vector<int>> resolverMochila(vector<Objeto> objetos, int M) {
    int beneficio_total = 0;
    vector<int> solucion(objetos.size(), 0);

    for (int i = 0; i < objetos.size() && M > 0; i++) {
        if (objetos[i].peso <= M) {
            M -= objetos[i].peso;
            solucion[objetos[i].indice] = 1;
            beneficio_total += objetos[i].beneficio;
        }
    }

    return make_pair(beneficio_total, solucion);
}

int main() {
    int n = 4;
    int M = 10;
    vector<int> pesos = {10, 3, 3, 4};
    vector<int> beneficios = {10, 9, 9, 9};

    vector<Objeto> objetos = crearObjetos(pesos, beneficios, n);
    sort(objetos.begin(), objetos.end(), comparar);

    pair<int, vector<int>> resultado = resolverMochila(objetos, M);
    int beneficio_total = resultado.first;
    vector<int> solucion = resultado.second;

    cout << "Resultado del algoritmo voraz:\n";
    cout << "Beneficio total: " << beneficio_total << "\n";
    cout << "Solucion: ";
    for (int xi : solucion) {
        cout << xi << " ";
    }
    cout << "\n";

    return 0;
}
