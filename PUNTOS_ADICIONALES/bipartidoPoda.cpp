#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Nodo {
    vector<int> conjuntoX;
    vector<int> conjuntoY;
    int nivel;
};

bool esBipartito(const vector<vector<int>>& grafo) {

    int n = grafo.size();
    queue<Nodo> cola;
    Nodo nodoRaiz;

    nodoRaiz.nivel = 0;
    
    cola.push(nodoRaiz);

    while (!cola.empty()) {
        Nodo nodoActual = cola.front();
        cola.pop();

        if (nodoActual.nivel == n) {
            
            for (int x : nodoActual.conjuntoX) {
                for (int y : nodoActual.conjuntoY) {
                    if (grafo[x][y] && grafo[y][x]) {
                        return false;
                    }
                }
            }
            return true;
        }

        
        Nodo hijoX = nodoActual;
        hijoX.conjuntoX.push_back(nodoActual.nivel);
        hijoX.nivel++;
        cola.push(hijoX);

       
        Nodo hijoY = nodoActual;
        hijoY.conjuntoY.push_back(nodoActual.nivel);
        hijoY.nivel++;
        cola.push(hijoY);
    }

    return false;
}

int main() {

    vector<vector<int>> grafo = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (esBipartito(grafo)) {
        cout << "El grafo es bipartito." << endl;
    } else {
        cout << "El grafo no es bipartito." << endl;
    }

    return 0;
}
