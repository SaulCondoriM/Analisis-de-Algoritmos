#include <iostream>

using namespace std;

double power(double x, int n) {
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if(n < 0)
        return power(1 / x, -n);
    else {
        
        double result = power(x, n / 2);
        if(n % 2 == 0)
            return result * result; 
        else
            return x * result * result; 
    }
}

int main() {
    double x = 2.0;
    int n = 5;
    cout << "El resultado de" << x << " elevado a la potencia de " << n << " es " << power(x, n);
    return 0;
}
