#include <iostream>
#include <cstdlib>

struct Vector {
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
};

void Resize(Vector *pThis) {
    // Aseguramos que el vector aumente en tamaño
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    // La cantidad máxima tiene que aumentar por m_nDelta
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem) {
    // Verificamos si hay suficiente espacio en el vector
    if(pThis->m_nCount == pThis->m_nMax)
        Resize(pThis); // Redimensionamos el vector antes de insertar elem
    // Insertamos el elemento al final de la secuencia
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
    // Creamos un vector e inicializamos sus valores
    Vector *vec = new Vector;
    vec->m_pVect = (int*)malloc(sizeof(int) * 10);
    vec->m_nCount = 0;
    vec->m_nMax = 10;
    vec->m_nDelta = 10;

    // Insertamos algunos elementos en el vector
    for(int i = 0; i < 20; i++)
        Insert(vec, i);

    // Mostramos los elementos del vector
    for(int i = 0; i < vec->m_nCount; i++)
        std::cout << vec->m_pVect[i] << " ";

    // Liberamos la memoria
    free(vec->m_pVect);
    delete vec;

    return 0;
}
