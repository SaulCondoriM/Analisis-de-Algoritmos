#include <iostream>
#include <cstdlib>

class CVector {
    
private:
    int *m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Resize() {
        m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        m_pVect = (int*)malloc(sizeof(int) * delta);
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
    }

    void Insert(int elem) {
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
    
    CVector vec(10);

   
    for(int i = 0; i < 20; i++)
        vec.Insert(i);

    vec.print();

    return 0;
}
