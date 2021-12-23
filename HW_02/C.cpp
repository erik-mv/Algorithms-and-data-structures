#include <iostream>
#include <string>
using namespace std;

int main() {
    ios ::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    string str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];

    int cnt[27], p[27];
    for (int i = m - 1; i >= m - k; i--) {
        for (int j = 0; j < 27; j++)
            cnt[j] = 0;

        for (int j = 0; j < n; j++)
            cnt[(int)str[j][i] - 96]++;

        p[0] = 0;
        for (int j = 1; j < 27; j++)
            p[j] = p[j - 1] + cnt[j - 1];

        string *temp = new string[n];
        for (int j = 0; j < n; j++)
            temp[p[(int)str[j][i] - 96]++] = str[j];

        copy(temp, temp + n, str);
        delete[] temp;
    }

    for (int j = 0; j < n; j++)
        cout << str[j] << '\n';

    return 0;
}

/*
3 3 3
bbb
aba
baa
*/
/*
5 7 2
bbbhzab
zcabaab
baabdab
baabdab
zcabaab
*/