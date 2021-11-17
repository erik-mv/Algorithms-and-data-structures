#include <iostream>
#include <queue>

using namespace std;

void bfs(pair<int, int>** ancestor, bool** used, pair<int, int > begin, int n) {
    used[begin.first][begin.second] = true;
    ancestor[begin.first][begin.second] = begin;

    queue<pair<int, int>> q;

    q.push(begin);
    int a[8][2] = { {-1, 2}, {1, 2}, {2, 1}, {2 ,-1},
                    {1 ,-2}, {-1 ,-2}, {-2 ,-1}, {-2 ,1} };

    while (q.size()) {
        auto  v = q.front();
        q.pop();
        for (size_t i = 0; i < 8; ++i) {
            int x = v.first + a[i][0];
            int y = v.second + a[i][1];

            if (x >= 0 && x < n && y >= 0 && y < n) {
                auto u = make_pair(x, y);

                if (!used[u.first][u.second]) {
                    used[u.first][u.second] = true;
                    q.push(u);

                    ancestor[u.first][u.second] = v;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    pair<int, int > begin;
    cin >> begin.first >> begin.second;
    --begin.first;
    --begin.second;

    int x;
    int y;
    cin >> x >> y;
    --x;
    --y;

    pair<int, int>** ancestor = new pair<int, int>*[n];
    for (size_t i = 0; i < n; ++i)
        ancestor[i] = new pair<int, int>[n];

    bool** used = new bool* [n];
    for (size_t i = 0; i < n; ++i) {
        used[i] = new bool[n];

        for (size_t j = 0; j < n; j++)
            used[i][j] = false;
    }

    bfs(ancestor, used, begin, n);

    int numberStep = 1;
    string result = to_string(x + 1) + " " + to_string(y + 1);
    while (begin != make_pair(x, y)) {
        ++numberStep;

        int temp = x;
        x = ancestor[x][y].first;
        y = ancestor[temp][y].second;
        result = to_string(x + 1) + " " + to_string(y + 1) + "\n" + result;
    }

    cout << numberStep << "\n";
    cout << result;

    for (size_t i = 0; i < n; ++i) {
        delete[] ancestor[i];
        delete[] used[i];
    }
    delete[] ancestor;
    delete[] used;

    return 0;
}