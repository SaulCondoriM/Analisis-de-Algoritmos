#include<bits/stdc++.h>
using namespace std;

int obtenerCambio(int c[], int n, int P){

    int tabla[P+1];

    tabla[0] = 0;

    for (int i=1; i<=P; i++)
        tabla[i] = INT_MAX;
 
    for (int i=1; i<=P; i++){

        for (int j=0; j<n; j++)

          if (c[j] <= i){

              int sub_res = tabla[i-c[j]];
              if (sub_res != INT_MAX && sub_res + 1 < tabla[i])
                  tabla[i] = sub_res + 1;
          }
    }
    
    return tabla[P];
}

int main(){


    int c[] = {1, 4, 6};

    int P = 8;

    int n = sizeof(c)/sizeof(c[0]);

    cout << "Minimas monedas necesarias para dar cambio: " 
         << obtenerCambio(c, n, P) << endl;
    return 0;
}
