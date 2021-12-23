#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-4;

double f(double vP, double vF, double a, double x) {
    return sqrt(x * x + (a - 1.) * (a - 1.)) / vP + sqrt((x - 1.) * (x - 1.) + a * a) / vF;
}

double ternarySearch(double vP, double vF, double a) {
    double l = 0.;
    double r = 1.;

    int n = -2 * log2(EPS) / log2(1.5);

    for (int i = 0; i < n; i++) {
        double mL = (2. * l + r) / 3.;
        double mR = (l + 2. * r) / 3.;

        if (f(vP, vF, a, mL) < f(vP, vF, a, mR))
            r = mR;
        else
            l = mL;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);

    double vP;
    double vF;
    double a;
    cin >> vP >> vF >> a;

    cout << fixed << setprecision(4) << ternarySearch(vP, vF, a);

    return 0;
}
/*
5 3
0.4

*/