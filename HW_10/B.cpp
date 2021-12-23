#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

void dfs(set<int>* graph, int v, int* depth, int indexDepth) {
    depth[v] = indexDepth;

    for (int i : graph[v])
        dfs(graph, i, depth, indexDepth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ++n;

    map <string, int> mp;
    mp["polycarp"] = 0;

    set<int>* graph = new set<int>[n];

    for (size_t i = 1; i < n; ++i) {
        string left;
        string right;
        cin >> left >> right >> right;

        transform(left.begin(), left.end(), left.begin(), ::tolower);
        transform(right.begin(), right.end(), right.begin(), ::tolower);

        mp[left] = i;
        graph[mp[right]].emplace(i);
    }

    int* depth = new int[n];
    int indexDepth = 1;

    dfs(graph, 0, depth, indexDepth);

    int maxDepth = 1;
    for (size_t i = 1; i < n; ++i)
        maxDepth = max(maxDepth, depth[i]);

    cout << maxDepth;

    delete[] depth;
    for (size_t i = 0; i < n; ++i)
        graph[i].clear();
    delete[] graph;
    mp.clear();

    return 0;
}