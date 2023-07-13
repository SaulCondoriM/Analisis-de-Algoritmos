#include <bits/stdc++.h>
using namespace std;

const double INF = numeric_limits<double>::infinity();

typedef pair<int, int> Punto;
typedef vector<Punto> VP;


double distancia(Punto p1, Punto p2) {

    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double fuerzaBruta(VP &P, int n) {


    double min_val = INF;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            min_val = min(min_val, distancia(P[i], P[j]));
    return min_val;
}

double stripMasCercano(VP &strip, int size, double d) {

    double min_val = d;
    sort(strip.begin(), strip.end(),
         [](Punto p1, Punto p2) { return p1.second < p2.second; });

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].second - strip[i].second) < min_val; ++j)
            min_val = min(min_val, distancia(strip[i], strip[j]));

    return min_val;
}

double masCercanoUtil(VP &Px, VP &Py, int n) {

    if (n <= 3) return fuerzaBruta(Px, n);

    int mid = n / 2;

    Punto puntoMedio = Px[mid];
    VP pyl, pyr;
    for (int i = 0; i < n; i++) {
        if (Py[i].first <= puntoMedio.first) pyl.push_back(Py[i]);
        else pyr.push_back(Py[i]);
    }

    double dl = masCercanoUtil(Px, pyl, mid);

    VP Px_derecha(Px.begin() + mid, Px.end());
    double dr = masCercanoUtil(Px_derecha, pyr, n - mid);

    double d = min(dl, dr);

    VP strip;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].first - puntoMedio.first) < d) strip.push_back(Py[i]);

    return min(d, stripMasCercano(strip, strip.size(), d));
}

double masCercano(VP &P, int n) {

    VP Px = P, Py = P;
    sort(Px.begin(), Px.end());
    sort(Py.begin(), Py.end(),
         [](Punto p1, Punto p2) { return p1.second < p2.second; });
    return masCercanoUtil(Px, Py, n);
}

int main() {

    int n;
    while (cin >> n, n) {
        VP P(n);
        
        for (int i = 0; i < n; i++) cin >> P[i].first >> P[i].second;

        double resultado = masCercano(P, n);
        cout << fixed << setprecision(4);
        if (resultado < 10000) cout << resultado << "\n";
        else cout << "INFINITY\n";
    }
    return 0;
}
