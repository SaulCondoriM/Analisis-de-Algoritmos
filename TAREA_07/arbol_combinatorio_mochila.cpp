#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

void mochilaBacktracking(int pesoMaximo, int pesos[], int valores[], int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(pesoMaximo + 1));

    // Construye la tabla K[][] de abajo hacia arriba
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= pesoMaximo; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (pesos[i - 1] <= w)
                K[i][w] = max(valores[i - 1] + K[i - 1][w - pesos[i - 1]],  K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Almacena el resultado 
    int res = K[n][pesoMaximo];
    printf("%d\n", res);

    w = pesoMaximo;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            printf("%d ", pesos[i - 1]);

            // Como este peso está incluido, se resta su valor
            res = res - valores[i - 1];
            w = w - pesos[i - 1];
        }
    }
}

int main() {
    int b[] = {2, 3, 4, 5};
    int p[] = {1, 2, 3, 4};
    int M = 7;
    int n = sizeof(b) / sizeof(b[0]);

    printf("Los items seleccionados son:\n");
    mochilaBacktracking(M, p, b, n);

    return 0;
}
