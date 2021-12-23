#include <iostream>
#include <math.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    int twoPow = 1;
    int k = 1;

    while (twoPow < n) {
        twoPow *= 2;
        ++k;
    }


    long long** minA = new long long* [n];
    for (size_t i = 0; i < n; ++i)
        minA[i] = new long long[k];

    cin >> minA[0][0];
    for (int i = 1; i < n; ++i)
        minA[i][0] = (23 * minA[i - 1][0] + 21563) % 16714589;

    twoPow = 1;
    for (int j = 1; j < k; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i + twoPow < n) {
                minA[i][j] = min(minA[i][j - 1], minA[i + twoPow][j - 1]);
            }
            else {
                minA[i][j] = 2000000000;
            }
        }
        twoPow *= 2;
    }


    /*for (size_t i = 0; i < n; ++i) {
        cout << minA[i][0];
        for (size_t j = 1; j < k; ++j)
            cout << " " << minA[i][j];
        cout << "\n";
    } cout << "\n";*/

    int u;
    int v;
    cin >> u >> v;

    long long res;
    for (size_t i = 1; i < m + 1; ++i) {
        if (u == v) {
            res = minA[u - 1][0];
        }
        else {
            int l = min(u, v);
            int r = max(u, v);

            int maxK = 0;//= log2(r - l) + 1;
            int two = 1;

            while (two <= r - l) {
                two *= 2;
                ++maxK;
            }

            two = 1 << (maxK - 1);

            res = min(minA[l - 1][maxK], minA[r - 1 - two][maxK]);
        }
        //cout << u << " " << v << " " << res<< "\n";
        if (i < m) {
            u = (17 * u + 751 + res + 2 * i) % n + 1;
            v = (13 * v + 593 + res + 5 * i) % n + 1;
        }

    }

    cout << u << " " << v << " " << res << "\n";



    for (size_t i = 0; i < n; ++i)
        delete[] minA[i];
    delete[] minA;

    return 0;
}

/*
10 8 12345
3 9
*/
/*
2 8 12345
1 1
*/
/*
10 3 0
2 10
*/

/*
10 8 1
3 9
*/