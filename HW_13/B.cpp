#include <iostream>
#include <queue>
using namespace std;

const int INF = (int)1e9;

int pushFlow(int v, int t, int curFlow, pair<int, int>** graph, bool* used, int* ancestor) {

    ancestor[0] = 0;
    queue <int> q;
    q.push(0);
    used[0] = false;

    while (q.size()) {

        for (size_t i = 0; i < t + 1; ++i)
            if (graph[0][i].first) { q.push(i); }

        int u = q.front();
        int f = graph[v][u].second;
        int c = graph[v][u].first;

        q.pop();

        if (used[u] && f < c) {
            curFlow = min(curFlow, c - f);
            used[u] = false;
            q.push(u);
        }
    }
    return curFlow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    pair<int, int>** graph = new pair<int, int>*[n];
    for (size_t i = 0; i < n; ++i) {
        graph[i] = new pair<int, int>[n];
    }

    for (size_t i = 0; i < m; ++i) {
        int left;
        int right;
        cin >> left >> right;
        --left;
        --right;

        int vol;
        cin >> vol;

        graph[left][right].first += vol;
        graph[right][left].first += vol;
    }


    bool* used = new bool[n];

    int* ancestor = new int[n];


    int ans = 0;
    while (true) {
        for (size_t i = 1; i < n; ++i)
            used[i] = true;


        int delta = pushFlow(0, n - 1, INF, graph, used, ancestor);
        if (delta > 0) { ans += delta; break; }
        else { break; }
    }

    cout << ans;

    for (size_t i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] used;
    delete[] graph;

    return 0;
}

/*
2
2
1 2 1
2 1 3
*/

/*
3
5
1 2 1
1 2 1
2 1 5
3 2 2
2 3 2
*/
/*
8
13
1 2 6
1 3 6
3 2 5
2 4 4
2 5 2
3 5 9
5 4 8
4 6 4
4 7 2
5 7 7
7 6 11
6 8 7
7 8 4
*/