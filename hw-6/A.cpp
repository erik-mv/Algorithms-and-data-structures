#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n;
    size_t k;
    cin >> n >> k;

    int* coins = new int[n];
    size_t* parent = new size_t[n - 1];

    coins[0] = 0;
    for (size_t i = 1; i < n - 1; ++i)
        cin >> coins[i];
    coins[n - 1] = 0;

    for (size_t i = 1; i < n; ++i) {
        int l = i - k;
        if (l < 0) {
            l = 0;
        }

        int tempCoins = coins[l];
        size_t tempParent = l;
        ++l;

        for (; l < i; ++l)
            if (tempCoins < coins[l]) {
                tempCoins = coins[l];
                tempParent = l;
            }
        coins[i] += tempCoins;
        parent[i - 1] = tempParent;
    }

    size_t i = n - 2;
    size_t step = 1;
    string solv = " " + to_string(n);

    while (parent[i]) {
        i = parent[i] - 1;
        solv = " " + to_string(i + 2) + solv;
        ++step;
    }
    cout << coins[n - 1] << "\n";
    cout << step << "\n";
    cout << "1" << solv << "\n";

    delete[] coins;
    delete[] parent;

    return 0;
}