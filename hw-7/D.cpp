#include <iostream>
#include <climits>

using namespace std;

void buildTree(long long* a, long long* tree, int n, int x) {
    for (int i = 0; i < n; ++i)
        tree[i + x - 1] = a[i];

    for (int i = n; i < x; ++i)
        tree[i + x - 1] = INT64_MAX;

    for (int j = x - 2; j >= 0; --j)
        tree[j] = min(tree[2 * j + 1], tree[2 * j + 2]);
}

void setAdd(int l, int r, long long k, long long b, long long* tree) {
    for (int i = l; i <= r; ++i)
        tree[i] = tree[i] * k + b;

    while (l) {
        l = (l - 1) / 2;
        r = (r - 1) / 2;

        for (int i = l; i <= r; ++i)
            tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

long long rmq(int v, int l, int r, int a, int b, long long* tree) {
    if (l > b || r < a) {
        return INT64_MAX;
    }

    if (l >= a && r <= b) {
        return tree[v];
    }
    int m = (l + r) / 2;

    return min(rmq(2 * v + 1, l, m, a, b, tree), rmq(2 * v + 2, m + 1, r, a, b, tree));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long* a = new long long[n];

    int x = 1;
    while (x < n) {
        x *= 2;
    }

    long long* tree = new long long[2 * x - 1];


    for (int i = 0; i < n; ++i)
        cin >> a[i];

    buildTree(a, tree, n, x);

    /*for (int i = 0; i < 2 * x - 1; ++i)
        cout << tree[i] << " ";
    cout << "\n";*/

    string str;
    int l;
    int r;
    long long k;

    while (cin >> str) {
        if (str == "re") {
            return 0;
        }
        if (str == "set") {
            cin >> l;
            cin >> r;
            cin >> k;
            setAdd(l + x - 2, r + x - 2, k, 0, tree);
        }
        else if (str == "add") {
            cin >> l;
            cin >> r;
            cin >> k;
            setAdd(l + x - 2, r + x - 2, 1, k, tree);
        }
        else {
            cin >> l;
            cin >> r;
            cout << rmq(0, x - 1, 2 * x - 2, l + x - 2, r + x - 2, tree) << "\n";
        }
    }

    delete[] a;
    delete[] tree;

    return 0;
}
/*
5
1 2 3 4 5
min 2 5
min 1 5
min 1 4
min 2 4
set 1 3 10
add 2 4 4
min 2 5
min 1 5
min 1 4
min 2 4
*/