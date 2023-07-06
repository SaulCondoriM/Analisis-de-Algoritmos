#include <iostream>
#include <cstring>

using namespace std;

int fnIntCompare(void *pVar1, void *pVar2) {
    return *(int *)pVar1 - *(int *)pVar2;
}

class CVector
{
private:
    void **m_pVect; 
    int m_nCount,
    m_nMax,
    m_nDelta,
    m_nElemSize; 
    int (*m_lpfnCompare)(void *, void*);

    void Init(int delta) {
        m_nDelta = delta;
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new void*[m_nMax];
    }

    void Resize() {
        m_nMax += m_nDelta;
        void **newVect = new void*[m_nMax];
        memcpy(newVect, m_pVect, m_nCount * sizeof(void*));
        delete[] m_pVect;
        m_pVect = newVect;
    }

    void* DupBlock(void *pElem) {
        void *p = new char[m_nElemSize];
        return memcpy(p, pElem, m_nElemSize);
    }

public:
    CVector(int (*lpfnCompare)(void *, void*), int nElemSize, int delta = 10) {
        Init(delta);
        m_lpfnCompare = lpfnCompare;
        m_nElemSize = nElemSize;
    }

    ~CVector() {
        for(int i = 0; i < m_nCount; ++i)
            delete[] (char*)m_pVect[i];
        delete[] m_pVect;
    }

    void Insert(void * elem) {
        if(m_nCount == m_nMax)
            Resize(); 
        m_pVect[m_nCount++] = DupBlock(elem); 
    }

   
    void PrintAll() {
        for(int i = 0; i < m_nCount; ++i)
            cout << *(int *)m_pVect[i] << " ";
        cout << "\n";
    }

};

int main() {
    CVector myVector(fnIntCompare, sizeof(int));

    // Insertando elementos
    for(int i = 0; i < 20; ++i)
        myVector.Insert(&i);

    // Imprimiendo
    myVector.PrintAll();

    return 0;
}
