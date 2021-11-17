#include <iostream>

using namespace std;

const int SIZE = 1000001501;
const int PARAMETR = 179;

int getHash(long long* hash, long long* powp, int left, int rigth) {
    if (left == 0)
        return hash[rigth];

    return (hash[rigth] - (hash[left - 1] * powp[rigth - left + 1]) % SIZE + SIZE) % SIZE;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    size_t k = str.length();

    long long* hash = new long long[k];
    long long* powp = new long long[k];

    hash[0] = str[0];
    powp[0] = 1;
    for (int i = 1; i < k; ++i) {
        hash[i] = (hash[i - 1] * PARAMETR + str[i]) % SIZE;
        powp[i] = (powp[i - 1] * PARAMETR) % SIZE;
    }

    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        int left;
        int rigth;
        int check_hash;

        cin >> left >> rigth;
        check_hash = getHash(hash, powp, left - 1, rigth - 1);

        cin >> left >> rigth;
        check_hash -= getHash(hash, powp, left - 1, rigth - 1);

        if (check_hash) { cout << "No\n"; }
        else { cout << "Yes\n"; }
    }

    delete[] hash;
    delete[] powp;

    return 0;
}