#include <iostream>

using namespace std;

const int INF = (int)1e9;


int pushFlow(int v, int t, int curFlow, pair<int, int>** graph, int** used) {

    if (v == t) { return curFlow; }

    for (size_t u = 0; u < t + 1; ++u) {
        int f = graph[v][u].second;
        int c = graph[v][u].first;

        if (used[v][u] == 0 && f < c) {
            int nextFlow = min(curFlow, c - f);
            used[v][u] = 1;
            used[u][v] = 1;
            int delta = pushFlow(u, t, nextFlow, graph, used);
            if (delta > 0) {
                graph[v][u].second += delta;
                graph[u][v].second -= delta;
                return delta;
            }
        }
    }
    return 0;
}

void print_f(int n, pair<int, int>** graph, int** used) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ")";
        }
        cout << "\n";
    }cout << "\n";

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << used[i][j] << " ";
        }
        cout << "\n";
    }cout << "\n";
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

    int** used = new int* [n];
    for (size_t i = 0; i < n; ++i)
        used[i] = new int[n];



    int ans = 0;

    while (true) {
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                used[i][j] = 0;

        for (size_t i = 0; i < n; ++i)
            used[i][0] = 1;

        //print_f(n, graph, used);
        int delta = pushFlow(0, n - 1, INF, graph, used);
        if (delta > 0) { ans += delta; }
        else { break; }
    }


    cout << ans;

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