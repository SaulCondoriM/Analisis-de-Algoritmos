#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochilaPoda(int M, const vector<int>& W, const vector<int>& B, int n) {
    vector<vector<int>> K(n + 1, vector<int>(M + 1));


    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (W[i - 1] <= w)
                K[i][w] = max(B[i - 1] + K[i - 1][w - W[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][M];
}

int main() {

    int M = 61;
    int n = 5;

    vector<int> W = {1, 11, 21, 23, 33};
    vector<int> B = {11, 21, 31, 33, 43};


    cout << "El valor maximo que se puede obtener es " << mochilaPoda(M, W, B, n) << endl;
    return 0;
}
