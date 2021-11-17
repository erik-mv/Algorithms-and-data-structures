#include <iostream>
#include <ctime>
using namespace std;

void sortQuick(int a[], int r) {
    if (r < 1)
        return;

    int x = a[rand() % (r + 1)];
    int mL = 0, mR = r;
    for (int i = 0; i <= mR; i++)
        if (a[i] < x) 
            swap (a[i], a[mL++]);
        else if (a[i] > x)
            swap (a[i--], a[mR--]);

    sortQuick(a, mL - 1);
    sortQuick(a + mR + 1, r - mR - 1);
}

int main() {
    std :: ios :: sync_with_stdio(false);
    srand(time(0));

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sortQuick(a, n - 1);

    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];

    return 0;
}

/*
10
1 8 2 1 4 7 3 2 3 6
*/