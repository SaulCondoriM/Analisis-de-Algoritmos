#include <iostream>

using namespace std;


unsigned long fiboRecursive(unsigned n){

    if (n < 2)
        return 1;
    return fiboRecursive(n - 1) + fiboRecursive(n - 2);

}


unsigned long fiboIterative(unsigned n) {

    if (n < 2)
        return 1;
    unsigned long f1 = 0, f2 = 1;
    unsigned long output;
    
    
    do {
        output = f1 + f2;
        f1 = f2;
        f2 = output;
    } while (--n >= 2);
    return output;
}

int main() {
    
    unsigned num = 10; 

    cout << "Fibonacci Recursivo " << num << ": " << fiboRecursive(num) << endl;
    cout << "Fibonacci iterativo " << num << ": " << fiboIterative(num) << endl;

    return 0;
}
