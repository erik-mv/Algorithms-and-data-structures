#include <iostream>
#include <string>
using namespace std;

int main() {
    ios ::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int sCnt[26], tCnt[26];
    for (int i = 0; i < 26; i++) {
        sCnt[i] = 0;
        tCnt[i] = 0;
    }

    for (int i = 0; i < m; i++)
        tCnt[(int)t[i] - 97]++;

    int temp = (int)s[0] - 97;
    sCnt[temp]++;

    int l = 0, r = 0;
    long long flag = 0;
    while (l < n) {
        if (sCnt[temp] <= tCnt[temp]) {
            flag += r - l + 1;

            if (r < n - 1) {
                temp = (int)s[++r] - 97;
                sCnt[temp]++;
            }
            else
                l = n;
        }
        else if (l >= r) {
                sCnt[(int)s[l++] - 97]--;
                temp = (int)s[++r] - 97;
                sCnt[temp]++;
            }
            else
                sCnt[(int)s[l++] - 97]--;
    }

    cout << flag;

    return 0;
}
/*
4 3
aaab
aba

7 3
abacaba
abc
*/