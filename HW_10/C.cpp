#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>* graph, int v, vector<int>& ans, int* used, bool& flag) {
    used[v] = 1;

    for (int i : graph[v])
        if (used[i] == 0) { dfs(graph, i, ans, used, flag); }
        else if (used[i] == 1) { flag = true; }

    used[v] = 2;

    ans.push_back(v + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    vector<int>* graph = new vector<int>[n];

    for (size_t i = 0; i < m; ++i) {
        int left;
        int right;
        cin >> left >> right;
        --left;
        --right;

        graph[left].push_back(right);
    }

    vector<int> ans;
    int* used = new int[n];
    for (size_t i = 0; i < n; ++i)
        used[i] = 0;

    bool flag = false;
    for (size_t i = 0; i < n; ++i)
        if (used[i] == 0) { dfs(graph, i, ans, used, flag); }

    if (flag) { cout << -1; }
    else {
        for (size_t i = 0; i < n; ++i)
            cout << ans[n - 1 - i] << " ";
    }

    ans.clear();
    delete[] used;
    for (size_t i = 0; i < n; ++i)
        graph[i].clear();
    delete[] graph;

    return 0;
}