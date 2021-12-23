#include <iostream>
using namespace std;
long long inv = 0;

void sortMerge(int a[], int n) {
    if (n == 1) 
        return;

    int m = n / 2;
    sortMerge(a, m);
    sortMerge(a + m, n - m);

    int *temp = new int[n + 1];
    int l = 0, r = m, i = 0;
    while (n > i) {
        if (l >= m || r < n && a[r] < a[l]) {
            inv += r - i;  
            temp[i++] = a[r++];
        }
        else
            temp[i++] = a[l++];
    }

    copy(temp, temp + i, a);
    delete[] temp;
}

int main() {
    std :: ios :: sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    sortMerge(a, n);
 
    cout << inv;

    return 0;
}

/*
10
1 8 2 1 4 7 3 2 3 6
*/




