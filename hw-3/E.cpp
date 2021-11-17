#include <iostream>
using namespace std;

long long f(long long firstCopier, long long secondCopier, long long time) {
    return time / firstCopier + (time - firstCopier) / secondCopier;
}

long long upperBound(long long n, long long firstCopier, long long secondCopier, long long time) {
    long long l = 1;
    long long r = time;

    while (l < r - 1) {
        long long m = (l + r) / 2;

        if (n <= f(firstCopier, secondCopier, m))
            r = m;
        else
            l = m;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);

    long long n;
    long long firstCopier;
    long long secondCopier;
    cin >> n >> firstCopier >> secondCopier;

    if (firstCopier > secondCopier)
        swap(firstCopier, secondCopier);

    cout << upperBound(n, firstCopier, secondCopier, n * firstCopier);

    return 0;
}
/*
4 1 1

5 1 2

3 9 10 = 19, 3 3 5 = 8, 1 2 2 = 2
*/