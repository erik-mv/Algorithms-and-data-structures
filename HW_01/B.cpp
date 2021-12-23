/*
10
1 8 2 1 4 7 3 2 3 6
*/
#include <iostream>
using namespace std;

int main() {
    std :: ios :: sync_with_stdio(false);
    
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                flag++;
                swap(a[i], a[i + 1]);
            }
        }
    }

    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];

    return 0;
}