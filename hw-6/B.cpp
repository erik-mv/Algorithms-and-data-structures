#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n;
    size_t m;

    cin >> n >> m;

    int** coins = new int* [n];
    pair<size_t, size_t>** parent = new pair<size_t, size_t>*[n];

    for (size_t i = 0; i < n; ++i) {
        coins[i] = new int[m];
        parent[i] = new pair<size_t, size_t>[m];
    }

    cin >> coins[0][0];

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j) {
            if (i > 0 || j > 0) {
                cin >> coins[i][j];

                if (j == 0 || i > 0 && coins[i - 1][j] > coins[i][j - 1]) {
                    coins[i][j] += coins[i - 1][j];
                    parent[i][j] = make_pair(i - 1, j);
                }
                else {
                    coins[i][j] += coins[i][j - 1];
                    parent[i][j] = make_pair(i, j - 1);
                }
            }
        }

    cout << coins[n - 1][m - 1] << "\n";

    size_t i = n - 1;
    size_t j = m - 1;
    string str = "";
    while (i + j > 0) {
        if (parent[i][j].first == i) {
            j = parent[i][j].second;
            str = "R" + str;
        }
        else {
            i = parent[i][j].first;
            str = "D" + str;
        }
    }

    cout << str << "\n";

    for (size_t i = 0; i < n; ++i) {
        delete[] coins[i];
        delete[] parent[i];
    }
    delete[] coins;
    delete[] parent;

    return 0;
}