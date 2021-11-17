#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string strN;
    string strM;

    cin >> strN >> strM;

    size_t n = strN.size() + 1;
    size_t m = strM.size() + 1;

    int** dp = new int* [n];
    for (size_t i = 0; i < n; ++i)
        dp[i] = new int[m];

    dp[0][0] = 0;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j) {
            if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j - 1] + 1;
            }
            else if (i > 0 && j == 0) {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else if (i > 0 && j > 0) {
                int m = 1;
                if (strN[i - 1] == strM[j - 1])
                    m = 0;

                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + m);
            }
        }

    cout << dp[n - 1][m - 1] << "\n";

    for (size_t i = 0; i < n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}