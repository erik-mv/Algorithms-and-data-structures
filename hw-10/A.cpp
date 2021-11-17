#include <iostream>
#include <set>

using namespace std;

void dfs(set<int>* graph, int v, int* color, int indexColor) {
    color[v] = indexColor;

    for (int i : graph[v])
        if (!color[i]) { dfs(graph, i, color, indexColor); }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    set<int>* graph = new set<int>[n];

    for (size_t i = 0; i < m; ++i) {
        int left;
        int right;
        cin >> left >> right;
        --left;
        --right;

        graph[left].emplace(right);
        graph[right].emplace(left);
    }

    int* color = new int[n];
    for (size_t i = 0; i < n; ++i)
        color[i] = 0;

    int indexColor = 0;
    for (size_t i = 0; i < n; ++i)
        if (!color[i]) {
            ++indexColor;
            dfs(graph, i, color, indexColor);
        }

    cout << indexColor << "\n";
    for (size_t i = 0; i < n; ++i)
        cout << color[i] << " ";

    delete[] color;
    for (size_t i = 0; i < n; ++i)
        graph[i].clear();
    delete[] graph;

    return 0;
}