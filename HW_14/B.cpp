#include <iostream>

using namespace std;

void zfunction(string str) {
    int n = str.length();
    int left = 0;
    int right = 0;
    int* z = new int[n];
    z[0] = 0;

    for (int i = 1; i < n; ++i) {

        z[i] = max(0, min(right - i, z[i - left]));

        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }

    for (size_t i = 1; i < n; ++i) {
        cout << z[i] << " ";
    }

    delete[] z;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    zfunction(str);

    return 0;
}