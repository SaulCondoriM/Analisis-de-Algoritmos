#include <iostream>
#include <cstdlib>

template <typename Type>
class CVector {
private:
    Type *m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Resize() {
        m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta));
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        m_pVect = (Type*)malloc(sizeof(Type) * delta);
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
    }

    void Insert(Type elem) {
        if(m_nCount == m_nMax)
            Resize();
        m_pVect[m_nCount++] = elem;
    }

    void print() {
        for(int i = 0; i < m_nCount; i++)
            std::cout << m_pVect[i] << " ";
        std::cout << "\n";
    }

    ~CVector() {
        free(m_pVect);
    }
};

int main() {
    // Creamos un vector para int
    CVector<int> vecInt(10);
    for(int i = 0; i < 20; i++)
        vecInt.Insert(i);
    vecInt.print();

    // Creamos un vector para char
    CVector<char> vecChar(10);
    for(int i = 0; i < 10; i++)
        vecChar.Insert('a' + i);
    vecChar.print();

    // Creamos un vector para float
    CVector<float> vecFloat(10);
    for(int i = 0; i < 10; i++)
        vecFloat.Insert((float)i / 3);
    vecFloat.print();

    return 0;
}
