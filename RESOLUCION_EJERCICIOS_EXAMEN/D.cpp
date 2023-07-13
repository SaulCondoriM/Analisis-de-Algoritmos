#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Intervalo;

vector<Intervalo> resuelve(int M, vector<Intervalo>& segmentos) {

    sort(segmentos.begin(), segmentos.end());

    vector<Intervalo> res;

    int i = 0, inicio = 0;

    while (inicio < M) {
        int fin = inicio;
        while (i < segmentos.size() && segmentos[i].first <= inicio) {
            fin = max(fin, segmentos[i].second);
            i++;
        }

        if (fin == inicio) return vector<Intervalo>();

        res.push_back({inicio, fin});
        inicio = fin;
    }

    return res;
}

int main() {

    int A;
    cin >> A;

    while (A--) {
        int M;
        cin >> M;

        vector<Intervalo> segmentos;
        while (true) {
            int Li, Ri;
            cin >> Li >> Ri;
            if (Li == 0 && Ri == 0) break;

            segmentos.push_back({Li, Ri});
        }

        vector<Intervalo> solucion = resuelve(M, segmentos);
        if (solucion.empty()) {
            cout << 0 << "\n";
        } else {
            cout << solucion.size() << "\n";
            for (Intervalo& inter : solucion)
                cout << inter.first << " " << inter.second << "\n";
        }

        if (A) cout << "\n";
    }

    return 0;
}
