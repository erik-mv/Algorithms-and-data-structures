#include <iostream>
using namespace std;

void sortQuick(int a[], int r) {
    if (r < 1)
        return;

    int x = a[rand() % (r + 1)];
    int mL = 0, mR = r;
    for (int i = 0; i <= mR; i++)
        if (a[i] < x)
            swap(a[i], a[mL++]);
        else if (a[i] > x)
            swap(a[i--], a[mR--]);

    sortQuick(a, mL - 1);
    sortQuick(a + mR + 1, r - mR - 1);
}

int lowerBound(int a[], int n, int x) {
    int l = -1;
    int r = n;

    while (l < r - 1) {
        int m = (l + r) / 2;

        if (x <= a[m])
            r = m;
        else
            l = m;
    }

    return r;
}

int upperBound(int a[], int n, int x) {
    int l = -1;
    int r = n;

    while (l < r - 1) {
        int m = (l + r) / 2;

        if (x < a[m])
            r = m;
        else
            l = m;
    }

    return l;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sortQuick(a, n - 1);

    int k;
    cin >> k;

    int* solv = new int[k];

    for (int i = 0; i < k; i++) {
        int l;
        int r;
        cin >> l >> r;

        solv[i] = upperBound(a, n, r) + 1;
        solv[i] -= lowerBound(a, solv[i], l);
    }

    delete[] a;

    cout << solv[0];
    for (int i = 1; i < k; i++)
        cout << " " << solv[i];

    delete[] solv;

    return 0;
}
/*
5
10 1 10 3 4
4
1 10
2 9
3 4
2 2

5 2 2 0
*/