#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> sum(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

vector<vector<int>> subtract(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}

vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    if (n == 1) {
        return {{a[0][0] * b[0][0]}};
    }
    int k = n / 2;
    vector<vector<int>> a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    vector<vector<int>> b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }
    auto s1 = subtract(b12, b22);
    auto p1 = strassen(a11, s1);
    auto s2 = sum(a11, a12);
    auto p2 = strassen(s2, b22);
    auto s3 = sum(a21, a22);
    auto p3 = strassen(s3, b11);
    auto s4 = subtract(b21, b11);
    auto p4 = strassen(a22, s4);
    auto s5 = sum(a11, a22);
    auto s6 = sum(b11, b22);
    auto p5 = strassen(s5, s6);
    auto s7 = subtract(a12, a22);
    auto s8 = sum(b21, b22);
    auto p6 = strassen(s7, s8);
    auto s9 = subtract(a11, a21);
    auto s10 = sum(b11, b12);
    auto p7 = strassen(s9, s10);
    auto c12 = sum(p1, p2);
    auto c21 = sum(p3, p4);
    auto s11 = sum(p5, p4);
    auto s12 = subtract(s11, p2);
    auto c11 = sum(s12, p6);
    auto s13 = sum(p5, p1);
    auto s14 = subtract(s13, p3);
    auto c22 = subtract(s14, p7);
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = c11[i][j];
            res[i][j + k] = c12[i][j];
            res[i + k][j] = c21[i][j];
            res[i + k][j + k] = c22[i][j];
        }
    }
    return res;
}

int main() {
    vector<vector<int>> a = {{1, 2}, {3, 4}};
    vector<vector<int>> b = {{5, 6}, {7, 8}};
    auto c = strassen(a, b);
    for (auto &row : c) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
