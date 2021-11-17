#include <iostream>
using namespace std;

int f(int i) {
    return i & (i + 1);
}

int64_t get(int i, int64_t* t) {
    int64_t res = 0;

    while (i >= 0) {
        res += t[i];
        i = f(i) - 1;
    }

    return res;
}

void add(int i, int64_t x, int n, int64_t* t) {
    int j = i;

    while (j < n) {
        t[j] += x;
        j = j | (j + 1);
    }
}

void set(int i, int64_t x, int n, int64_t* t, int64_t* a) {
    add(i, x - a[i], n, t);

    a[i] = x;
}

int64_t rsq(int l, int r, int64_t* t) {
    if (l == 0) {
        return get(r, t);
    }

    return get(r, t) - get(l - 1, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int64_t* a = new int64_t[n];
    int64_t* t = new int64_t[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        t[i] = 0;
        for (int j = f(i); j < i + 1; ++j)
            t[i] += a[j];
    }

    string str;
    int l;
    int r;

    while (cin >> str) {
        if (str == "sum") {
            cin >> l;
            cin >> r;
            cout << rsq(l - 1, r - 1, t) << "\n";
        }
        else {
            cin >> l;
            cin >> r;
            set(l - 1, r, n, t, a);
        }
    }

    delete[] a;
    delete[] t;
    
    return 0;
}