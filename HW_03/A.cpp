#include <iostream>
using namespace std;

int nearlyLowerBound(int a[], int n, int x) {
    int l = -1;
    int r = n;

    while (l < r - 2) {
        int m = (l + r) / 2;

        if (x - a[m] <= a[m + 1] - x)
            r = m + 1;
        else
            l = m;
    }

    return a[r - 1];
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    int k;
    cin >> n >> k;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int* solv = new int[k];

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        solv[i] = nearlyLowerBound(a, n, x);
    }
    
    delete[] a;

    for (int i = 0; i < k; i++)
        cout << solv[i] << "\n";

    delete[] solv;

    return 0;
}
/*
5 5
1 3 5 7 9
2 4 8 1 6

10 13
4 4 6 10 15 15 16 17 18 90
1 3 4 5 6 7 18 19 54 55 90 91 105
10 7
4 4 6 10 15 15 16 17 18 90
18 19 54 55 90 91 105

4
4
4
4
6
6
18
18
18
90
90
90
90
*/