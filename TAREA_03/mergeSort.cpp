#include <iostream>
#include <vector>

using namespace std;



void merge(vector<int>& v, int inicio, int medio, int fin) {
    int i, j, k;
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = v[medio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {

        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {

        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v, int inicio, int fin) {

    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        mergeSort(v, inicio, medio);
        mergeSort(v, medio + 1, fin);

        merge(v, inicio, medio, fin);
    }
}

int main() {
    vector<int> arr = {45, 38, 27, 43, 3, 9, 82, 10};
    int arr_size = arr.size();

    cout << "Imprimiendo el array\n";
    for (auto i: arr)
        cout << i << " ";

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nEl array una vez ordenado es: \n";
    for (auto i: arr)
        cout << i << " ";

    return 0;
}
