#include <iostream>
using namespace std;

long long f(int a[], int n, int m) {
    long long flag = 0;

    for (int i = 0; i < n; i++)
        flag += a[i] / m;

    return flag;
}

long long binSearch(int a[], int n, int k, int l, int r) {
    while (l < r - 1) {
        int m = (l + r) / 2;

        if (f(a, n, m) >= k)
            l = m;
        else
            r = m;
    }
    return l;
}

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

int main() {
    ios::sync_with_stdio(false);

    int n;
    int k;
    cin >> n >> k;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sortQuick(a, n - 1);

    cout << binSearch(a, n, k, 0, a[n - 1] + 1) << "\n";

    delete[] a;

    return 0;
}
/*
4 11
802
743
457
539

3 100
46
23
10

4 4
10
10
10
10

1 2
1

2 10
5
5
*/