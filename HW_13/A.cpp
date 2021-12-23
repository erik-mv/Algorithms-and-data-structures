#include <iostream>
 
using namespace std;
 
const int INF = (int)1e9;
 
 
int pushFlow(int v, int t, int curFlow, pair<int, int>** graph, bool* used) {
    if (v == t) { return curFlow; }
 
    for (size_t u = 0; u < t + 1; ++u) {
        int f = graph[v][u].second;
        int c = graph[v][u].first;
 
        if (used[u] && f < c) {
            int nextFlow = min(curFlow, c - f);
            used[u] = false;
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
 
    bool* used = new bool [n];

 
    int ans = 0;
    while (true) {
            for (size_t i = 1; i < n; ++i)
                used[i] = true;

 
        int delta = pushFlow(0, n - 1, INF, graph, used);
        if (delta > 0) { ans += delta; }
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