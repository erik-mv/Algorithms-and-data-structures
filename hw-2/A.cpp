#include <iostream>
#include <ctime>
using namespace std;

int findQuick(int a[], int r, int k) {
    if (r < 1)
        return a[k];

    int x = a[rand() % (r + 1)];
    int mL = 0, mR = r;
    for (int i = 0; i <= mR; i++)
        if (a[i] < x)
            swap(a[i], a[mL++]);
        else if (a[i] > x)
            swap(a[i--], a[mR--]);

    if (mL > k)
        return findQuick(a, mL - 1, k);
    else if (mR < k)
        return findQuick(a + mR + 1, r - mR - 1, k - mR - 1);
    else
        return a[k];
}

int main() {
    ios ::sync_with_stdio(false);
    srand(time(0));

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    int solv[m];
    int l, r, k;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        r -= l - 1;
        
        int *temp = new int[r];
        for (int j = 0; j < r; j++)
            temp[j] = a[j + l - 1];

        solv[i] = findQuick(temp, r - 1, k - 1);
        delete[] temp;
    }

    for (int i = 0; i < m; i++)
        cout << solv[i] << '\n';

    return 0;
}
/*
10
1 8 2 1 4 7 3 2 3 6
8
1 3 2
1 5 1
1 5 2
1 10 5
1 10 2
4 10 2
3 10 1
3 10 2

10
1 8 2 1 4 7 3 2 3 6
1
4 10 2
*/