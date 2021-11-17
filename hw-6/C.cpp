#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int* seq = new int[n];
    int* dp = new int[n];
    int* parent = new int[n - 1];

    dp[0] = 1;
    cin >> seq[0];
    int flag = 0;

    for (int i = 1; i < n; ++i) {
        cin >> seq[i];

        dp[i] = 0;
        parent[i - 1] = -1;
        for (int j = i - 1; j >= 0; j--)
            if (seq[i] > seq[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j];
                parent[i - 1] = j;
            }
        ++dp[i];

        if (dp[flag] < dp[i]) {
            flag = i;
        }
    }

    int i = flag - 1;
    string str = " " + to_string(seq[flag]);

    while (i >= 0 && parent[i] >= 0) {
        i = parent[i];
        str = " " + to_string(seq[i]) + str;
        i--;
    }

    cout << dp[flag] << " \n";

    if (dp[flag] != 1)
        cout << str << "\n";
    else
        cout << to_string(seq[0]);

    delete[] seq;
    delete[] dp;
    delete[] parent;

    return 0;
}