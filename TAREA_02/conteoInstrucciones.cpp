#include<iostream>
using namespace std;

void Funcion_1(int N) {

    int contador = 0;
    
    for(int i = 0; i <= N; i++) {
        contador++;
        if(i % 2 == 0) {
            contador++;
            cout<<i<<" ";
        }
        contador++;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;
}

void Funcion_2(int N) {
    int contador = 0;

    for(int i = 0; i <= N; i++) {
        contador++;
        for(int j = i; j <= N; j++) {
            contador++;
            cout<<i<<" , "<<j<<endl;
            contador++;
        }
        contador++;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;
}

void Funcion_3(int A[], int lenA, int B[], int lenB) {

    int c = 0;

    for(int i = 0; i < lenA; i++) {
        c++;
        for(int j = 0; j < lenB; j++) {
            c++;
            cout<<A[i]<<" , "<<B[j]<<endl;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;
}

void Funcion_4(int N) {

    int contador = 0;

    for(int i = 0; i <= N; i++) {
        contador++;
        int j = 1;
        contador++;
        while (j < N)
        {
            contador++;
            cout<<j<<" ";
            contador++;
            j *= 2;
            contador++;
        }
        contador++;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;
}

void Funcion_5(int N) {

    int contador = 0;

    for(int i = 0; i <= N; i++) {
        contador++;
        if(i % 2 == 0) {
            contador++;
            cout<<i<<" ";
        }
        contador++;
    }
    contador++;


    for(int i = 0; i <= N; i++) {
        contador++;
        if(i % 2 != 0) {
            contador++;
            cout<<i<<" ";
        }
        contador++;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;
}

void Funcion_6(int N) {
    int contador = 0;

    int i = 1;
    contador++;

    while (i < N)
    {
        contador++;
        cout<<i<<" ";
        contador++;
        i *= 2;
        contador++;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;    
}

void Funcion_7() {
    
    int contador = 0;

    int N = 1000;
    contador++;

    contador++;
    if(N % 2 == 0) {
        contador++;
        cout<<"Par"<<endl;
    }

    else {
        contador++;
        cout<<"Impar"<<endl;
    }
    contador++;

    cout<<endl<<"contador: "<<contador<<endl;    
}

int main() {

    int A[] = {1, 2, 3};
    int B[] = {4, 5};
    int lenA = sizeof(A) / sizeof(A[0]);
    int lenB = sizeof(B) / sizeof(B[0]);


    Funcion_1(10);

    Funcion_2(15);

    Funcion_3(A, lenA, B, lenB);
    
    Funcion_4(18);

    Funcion_5(10);

    Funcion_6(3);

    Funcion_7();

    return 0;
}
