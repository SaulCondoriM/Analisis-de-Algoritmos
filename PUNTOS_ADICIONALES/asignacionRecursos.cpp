#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Nodo {

    int nivel;
    int beneficio;
    int recursosRestantes;
};

int main() {
    int n = 5; 
    int r = 3; 
    vector<vector<int>> N = {
        {0, 5, 9, 12, 14, 15},
        {0, 8, 12, 16, 18, 19},
        {0, 4, 7, 11, 12, 14},
    };

    queue<Nodo> cola;
    Nodo nodoRaiz;

    nodoRaiz.nivel = -1;
    nodoRaiz.beneficio = 0;

    nodoRaiz.recursosRestantes = n;
    cola.push(nodoRaiz);

    int mejorBeneficio = 0;

    while (!cola.empty()) {
        Nodo nodoActual = cola.front();
        cola.pop();

        if (nodoActual.nivel == r - 1) {
            if (nodoActual.beneficio > mejorBeneficio) {

                mejorBeneficio = nodoActual.beneficio;
            }
        } else {
            

            for (int j = 0; j <= nodoActual.recursosRestantes; j++) {
                
                Nodo hijo = nodoActual;

                hijo.nivel++;
                hijo.beneficio += N[hijo.nivel][j];
                hijo.recursosRestantes -= j;

                
                if (hijo.beneficio + (r - 1 - hijo.nivel) * hijo.recursosRestantes * N[hijo.nivel][n / r] >= mejorBeneficio) {
                    cola.push(hijo);
                }
            }
        }
    }

    cout << "El beneficio máximo es: " << mejorBeneficio << endl;

    return 0;
}
