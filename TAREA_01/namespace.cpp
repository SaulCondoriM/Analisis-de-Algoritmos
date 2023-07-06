#include <iostream>


using namespace std;

namespace MyNS {
    int gnCount = 0; 

    double Addition(double a, double b) { return a+b; } 

    long factorial(int n) { 
        long result = 1;
        for(int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }

    class CTest {
    public:
        CTest() {}

        void Method1() {
            cout << "Testeo del metodo 1" << endl;
        }
    };
    
}

int main() {
    // Creando una instancia de la clase CTest en el espacio de nombres MyNS
    MyNS::CTest myTest;
    
    // Llamando a un método en la clase CTest
    myTest.Method1();

    // Usando una función global en el espacio de nombres MyNS
    double result = MyNS::Addition(5.5, 3.3);
    cout << "Resultado de la suma: " << result << endl;

    // Usando otra función global en el espacio de nombres MyNS para calcular un factorial
    long factorialResult = MyNS::factorial(5);
    cout << "Resultado del factorial: " << factorialResult << endl;

    return 0;
}
