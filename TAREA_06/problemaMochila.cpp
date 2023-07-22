#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { 

    return (a > b) ? a : b; 
}

vector<int> Mochila(int M, vector<int>& p, vector<int>& b, int n) {

    int i, w;


    vector<vector<int>> V(n + 1 , vector<int> (M + 1, 0));

    for (i = 0; i <= n; i++) {

        for (w = 0; w <= M; w++) {

            if (i==0 || w==0)
                V[i][w] = 0;
            else if (p[i - 1] <= w)
                V[i][w] = max(b[i - 1] + V[i - 1][w - p[i - 1]], V[i - 1][w]);
            else
                V[i][w] = V[i - 1][w];
        }
    }
    

    int res = V[n][M];
    w = M;
    vector<int> solution(n, 0);

    for (i = n; i > 0 && res > 0; i--) {
        if (res == V[i - 1][w])
            continue;
        else {
            solution[i - 1] = 1;
            res = res - b[i - 1];
            w = w - p[i - 1];
        }
    }

    return solution;
}

int main() {

    int n = 3;
    int M = 6;

    vector<int> p = {2, 3, 4};
    vector<int> b = {1, 2, 5};

    vector<int> solution = Mochila(M, p, b, n);

    cout << "Los objetos escogidos son: ";
    for (int i = 0; i < n; i++) {
        if (solution[i] == 1) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
