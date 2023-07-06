#include<iostream>

using namespace std;

template <typename T> 
class CLinkedList {
private: 
    struct NODE {
        T m_data; 
        NODE *m_pNext; 
    };
    NODE* m_pRoot;
public: 
    CLinkedList() : m_pRoot(nullptr) {}

    void Insert(T data) {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = m_pRoot;
        m_pRoot = newNode;
    }

    void Display() {
        NODE* current = m_pRoot;
        while(current != nullptr) {
            cout << current->m_data << " ";
            current = current->m_pNext;
        }
        cout << endl;
    }
};


template <typename T>
class CBinaryTree {
private: 
    struct NODE {
        T m_data;
        NODE *m_pLeft, *m_pRight; 
    };
    NODE* m_pRoot; 

    NODE* findNodeWithoutLeftChild(NODE* node) {
        if (node == nullptr || node->m_pLeft == nullptr) return node;
        else return findNodeWithoutLeftChild(node->m_pLeft);
    }

public: 
    CBinaryTree() : m_pRoot(nullptr) {}

    void Insert(T data) {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pLeft = nullptr;
        newNode->m_pRight = nullptr;
        if(m_pRoot == nullptr) {
            m_pRoot = newNode;
        } else {
            NODE* parentNode = findNodeWithoutLeftChild(m_pRoot);
            parentNode->m_pLeft = newNode;
        }
    }

    void Display(NODE* node) {
        if (node != nullptr) {
            Display(node->m_pLeft);
            cout << node->m_data << " ";
            Display(node->m_pRight);
        }
    }

    NODE* getRoot() {
        return m_pRoot;
    }
};

int main() {
    // Creando instancias de las clases
    CLinkedList<int> myList;
    CBinaryTree<int> myTree;
    
    // Insertar elementos en la lista enlazada
    for (int i = 1; i <= 5; ++i) {
        myList.Insert(i);
    }

    // Insertar elementos en el árbol binario
    for (int i = 1; i <= 5; ++i) {
        myTree.Insert(i);
    }

    // Mostrar elementos
    cout << "Linked List: ";
    myList.Display();
    cout << "Binary Tree: ";
    myTree.Display(myTree.getRoot());
    cout << endl;

    return 0;
}
