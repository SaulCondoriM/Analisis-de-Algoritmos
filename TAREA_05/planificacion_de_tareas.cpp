#include <bits/stdc++.h>
using namespace std;

struct Job {
    int plazo, beneficio;
};

bool comparacion(Job a, Job b) {
    return (a.beneficio > b.beneficio);
}

int planificacionTareas(Job A[], int n) {

    sort(A, A + n, comparacion);

    int resultado[n];
    bool campo[n];

    for (int i=0; i<n; i++)
        campo[i] = false;

    for (int i=0; i<n; i++) {
        for (int j=min(n, A[i].plazo)-1; j>=0; j--) {
            if (campo[j]==false) {
                resultado[j] = i;
                campo[j] = true;
                break;
            }
        }
    }

    int total = 0;
    for (int i=0; i<n; i++)
        if (campo[i])
            total += A[resultado[i]].beneficio;
    return total;
}

int main() {

    Job A[] = { {2, 100}, {1, 10}, {2, 15}, {1, 27} };

    int n = sizeof(A)/sizeof(A[0]);

    cout << "El beneficio maximo obtenido es: " << planificacionTareas(A, n);

    return 0;
}
