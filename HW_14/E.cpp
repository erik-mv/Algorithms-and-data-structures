#include <iostream>

using namespace std;

const int SIZE = 1000001501;
const int PARAMETR = 179;

int getHash(long long** hash, long long** powp, int left, int rigth, int i) {
    if (left == 0)
        return hash[i][rigth];

    return (hash[i][rigth] - (hash[i][left - 1] * powp[i][rigth - left + 1]) % SIZE + SIZE) % SIZE;
}


double binSearch(double c, double left, double rigth) {
    int n = log2((r - l) / EPS);

    for (int i = 0; i < n; i++) {
        double m = (l + r) / 2.;

        if (f(m, c) < 0.)
            l = m;
        else
            r = m;
    }
    return r;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n;
    cin >> n;

    long long** hash = new long long*[n];
    long long** powp = new long long*[n];

    for (size_t i = 0; i < n; ++i) {
        string str;
        cin >> str;
        size_t k = str.size();

        hash[i] = new long long [k];
        powp[i] = new long long [k];

        hash[i][0] = str[0];
        powp[i][0] = 1;

        for (int j = 1; j < k; ++j) {

        hash[i][j] = (hash[i][j - 1] * PARAMETR + str[i]) % SIZE;
        powp[i][j] = (powp[i][j - 1] * PARAMETR) % SIZE;
    }
        
    }

    /*for (size_t i = 0; i < n; ++i) {
        int left;
        int rigth;
        int check_hash;

        cin >> left >> rigth;
        check_hash = getHash(hash, powp, left - 1, rigth - 1);

        cin >> left >> rigth;
        check_hash -= getHash(hash, powp, left - 1, rigth - 1);

        if (check_hash) { cout << "No\n"; }
        else { cout << "Yes\n"; }
    }*/

    for (size_t i = 0; i < n; ++i) {
        delete[] hash[i];
        delete[] powp[i];
    }
    delete[] hash;
    delete[] powp;

    return 0;
}

/*
3
abacaba
mycabarchive
acabistrue
*/