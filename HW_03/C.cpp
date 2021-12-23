#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

double f(double x, double c) {
    return x * x + sqrt(x) - c;
}

double binSearch(double c, double l, double r) {
    int n = log2((r - l) / EPS);

    for (int i = 0; i < n; i++) {
        double m = (l + r) / 2.;

        if (f(m, c) < 0.)
            l = m;
        else
            r = m;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);

    double c;
    cin >> c;

    cout << fixed << setprecision(6) << binSearch(c, 0., sqrt(c));

    return 0;
}
/*
2.0000000000
1.0

18.0000000000
4.0
*/