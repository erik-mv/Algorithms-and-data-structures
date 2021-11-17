#include <iostream>
using namespace std;

int  main() {
    std :: ios :: sync_with_stdio(false);
 
    int n, a, b;
    cin >> n;
 
    int sum[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        sum[i] = a + b;
    }

    for (int i = 0; i < n; i++)
        cout << sum[i] << '\n';

    return 0;
}