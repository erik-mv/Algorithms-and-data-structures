#include <iostream>
using namespace std;

const int TWO30 = 1073741824;

uint32_t newB(uint32_t z, int32_t t, uint32_t b) {
    b = (z * b + t) % TWO30;
    return b < 0 ? b + TWO30 : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    uint16_t x;
    uint16_t y;
    uint16_t a;
    cin >> x >> y >> a;

    uint64_t* sum = new uint64_t[n];
    sum[0] = a;

    for (int i = 1; i < n; ++i) {
        a = x * a + y;
        sum[i] = sum[i - 1] + a;
    }

    int m;
    cin >> m;

    uint32_t z;
    int32_t t;
    uint32_t b;
    cin >> z >> t >> b;

    uint64_t solv = 0;
    for (int i = 0; i < m; ++i) {
        size_t l = b % n;
        b = newB(z, t, b);

        size_t r = b % n;
        b = newB(z, t, b);

        if (l > r) {
            swap(l, r);
        }

        if (l == 0) {
            solv += sum[r];
        }
        else {
            solv += sum[r] - sum[l - 1];
        }
    }

    cout << solv;

    delete[] sum;
    
    return 0;
}