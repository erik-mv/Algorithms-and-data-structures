#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    size_t n;
    cin >> n;

    int* pay = new int[n];
    for (size_t i = 0; i < n; ++i) {
        cin >> pay[i];
    }



    pair<int, int>** dp = new pair<int, int>*[n];
    for (size_t i = 0; i < n; ++i)
        dp[i] = new pair<int, int>[n];

    dp[0][0].first = pay[0];
    if (pay[0] > 100) {
        dp[0][0].second = 1;
    }
    else {
        dp[0][0].second = 0;
    }

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) {
            if (i < j && i + j < n) {
                dp[i][j].first = 2000000;
            }
            else if (j == 0 && i > 0) {
                dp[i][j].first = pay[i];

                if (dp[i][j].first <= 100) {
                    dp[i][j].first += dp[i - 1][j].first;
                    dp[i][j].second = dp[i - 1][j].second +1;
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);

                }
                else {
                    dp[i][j] = dp[i - 1][j + 1];

                    if (dp[i][j].first == 2000000){
                        dp[i][j].second = dp[i - 1][j].second+1;
                        if (dp[i - 1][j].second) {
                            dp[i][j] = dp[i - 1][j];
                        }
                    } 
                }
                --dp[i][j].second;
            }
            else if (i > 0 && j > 0 && i + j < n) {
                dp[i][j].first = pay[i];

                if (dp[i][j].first > 100) {
                    dp[i][j].first += dp[i - 1][j - 1].first;
                    dp[i][j].second = 1 + dp[i - 1][j - 1].second;
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);
                }
                else {
                    dp[i][j].first += dp[i - 1][j].first;
                    dp[i][j].second = dp[i - 1][j].second;
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);
                }
            }
        }

    int payMin = dp[n - 1][0].first;
    int couponMin = dp[n - 1][0].second;
    int indexMin = 0;


    int couponMax = dp[0][n - 1 - indexMin].second;
    string solv = "";

    for (size_t i = 1; i < indexMin + 1; ++i) {
        if (dp[i][n - 1 - indexMin].second < dp[i - 1][n - 1 - indexMin].second) {
            solv += to_string(n - indexMin + i) + "\n";
        }
        if (dp[i][n - 1 - indexMin].second > dp[i - 1][n - 1 - indexMin].second) {
            ++couponMax;
        }
    }

    cout << payMin << "\n";
    cout << couponMin << " " << couponMax - couponMin << "\n";
    cout << solv;


    cout << "\n";
    for (size_t i = 0; i < n; ++i) {
        cout << dp[i][0].first;
        for (size_t j = 1; j < n; ++j)
            cout << " " << dp[i][j].first;
        cout << "\n";
    }cout << "\n";

    cout << "\n";
    for (size_t i = 0; i < n; ++i) {
        cout << dp[i][0].second;
        for (size_t j = 1; j < n; ++j)
            cout << " " << dp[i][j].second;
        cout << "\n";
    }cout << "\n";


    for (size_t i = 0; i < n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] pay;

    return 0;
}
/*
5
110
40
120
110
60

3
110
110
110

7
10
120
10
115
100
10
55

8
10
120
10
115
100
10
55
101


{10, 120, 10, 115, 100, 10, 55};   // 265
{10, 120, 10, 115, 100, 10, 55, 101}; // 320
*/