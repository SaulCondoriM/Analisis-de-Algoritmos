#include <iostream>
#include <vector>

using namespace std;

vector<int> algoritmoVoraz(int monto, const vector<int>& monedas) {
    vector<int> resultado(monedas.size(), 0);

    for (int i = 0; i < monedas.size(); i++) {
        while (monto >= monedas[i]) {
            resultado[i]++;
            monto -= monedas[i];
        }
    }

    return resultado;
}

int main() {
    int monto = 180;
    vector<int> monedas = {100, 90, 1};

    vector<int> resultado = algoritmoVoraz(monto, monedas);

    cout << "Cantidad de monedas utilizadas: " << endl;
    for (int i = 0; i < resultado.size(); i++) {
        cout << monedas[i] << " monedas: " << resultado[i] << endl;
    }

    int totalmonedas = 0;
    for (int monedasUsed : resultado) {
        totalmonedas += monedasUsed;
    }

    cout << "Total de monedas utilizadas: " << totalmonedas << endl;

    return 0;
}
