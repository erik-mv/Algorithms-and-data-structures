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

void dfs2(vector<int>* graph, int v, int* color, int indexColor) {
    color[v] = indexColor;

    for (int i : graph[v])
        if (!color[i]) { dfs2(graph, i, color, indexColor); }
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


    /*for (size_t i = 0; i < n; ++i)
        cout << ans[n - 1 - i] << " ";
    cout<< endl;*/




    int* color = new int[n];
    for (size_t i = 0; i < n; ++i)
        color[i] = 0;

    int indexColor = 0;
    for (size_t i = 0; i < n; ++i) {
        int j = ans[i];
        if (!color[j]) {
            ++indexColor;
            dfs2(graph, j, color, indexColor);
        }
    }

    cout << indexColor << "\n";
    /*for (size_t i = 0; i < n; ++i)
        cout << color[i] << " ";*/




    ans.clear();
    delete[] used;
    delete[] color;
    for (size_t i = 0; i < n; ++i)
        graph[i].clear();
    delete[] graph;

    return 0;
}

/*
4 4
2 1
3 2
2 3
4 3
*/