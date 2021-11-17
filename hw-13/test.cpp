#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void bfs(priority_queue <pair<int, int>>* q, bool* used, int* weight) {
    weight[0] = 0;

    priority_queue <pair<int, int>> queueIndex;
    queueIndex.push(make_pair(0, 0));

    while (queueIndex.size()) {
        int i = queueIndex.top().second;
        queueIndex.pop();
        used[i] = true;

        while (q[i].size()) {

            auto v = q[i].top();
            q[i].pop();

            if (weight[i] + v.first > weight[v.second]) {
                weight[v.second] = weight[i] + v.first;

                if (!used[v.second]) { queueIndex.push(make_pair(weight[v.second], v.second)); }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;
    int begin;

    priority_queue <pair<int, int>>* q = new priority_queue <pair<int, int>>[n];
    for (size_t i = 0; i < m; i++) {
        int indexL;
        int indexR;
        int weightRib;

        cin >> indexL >> indexR >> weightRib;

        --indexL;
        --indexR;
        weightRib *= -1;

        q[indexL].push(make_pair(weightRib, indexR));
        q[indexR].push(make_pair(weightRib, indexL));
    }

    int* weight = new int[n];
    for (size_t i = 1; i < n; ++i)
        weight[i] = INT_MIN;

    bool* used = new bool[n];
    for (size_t i = 0; i < n; ++i)
        used[i] = false;

    bfs(q, used, weight);

    for (size_t i = 0; i < n; ++i)
        cout << -weight[i] << " ";

    delete[] q;
    delete[] weight;
    delete[] used;

    return 0;
}