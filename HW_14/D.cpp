#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int ALFAV = 97;

class Trie {
    int size;
    vector<vector<int>> next;
    vector<bool> isTerminal;

public:
    Trie() {
        size = 1;
        next.resize(size);
        next[0].resize(26, -1);
        isTerminal.resize(size, false);
    }

    ~Trie() {
        for (size_t i = 0; i < size; ++i)
            next[i].clear();

        next.clear();
        isTerminal.clear();
    }


    void insert(string& str) {
        int v = 0;

        for (int i = 0; i < str.length(); ++i) {
            if (next[v][str[i] - ALFAV] == -1) {
                next[v][str[i] - ALFAV] = size;

                size += 1;
                next.resize(size);
                next[size - 1].resize(26, -1);
                isTerminal.resize(size, false);
            }

            v = next[v][str[i] - ALFAV];
        }

        isTerminal[v] = true;
    }

    int contains(string& str, int& left) {
        int rigth = -1;
        int v = 0;

        for (int i = left; i < str.length(); ++i) {
            if (next[v][str[i] - ALFAV] == -1) {
                return -1;
            }

            v = next[v][str[i] - ALFAV];

            if (isTerminal[v]) {
                isTerminal[v] = false;
                return i + 1;
            }

            rigth = i;
        }

        if (isTerminal[v]) {
            return rigth;
        }

        return -1;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string result_str;
    string str;
    cin >> result_str;

    int n;
    cin >> n;

    map <string, bool> mp;
    auto it = mp.begin();

    Trie trie;

    for (size_t i = 0; i < n; ++i) {
        cin >> str;
        mp[str] = false;
        trie.insert(str);
    }

    for (int i = 0; i < result_str.size(); i++) {
        int j = trie.contains(result_str, i);

        while (j != -1) {
            str.assign(result_str, i, j - i);

            it = mp.find(str);
            if (it != mp.end()) {
                mp[it->first] = true;
            }

            j = trie.contains(result_str, i);
        }
    }

    it = mp.begin();
    for (int i = 0; it != mp.end(); it++, i++)
        if (it->second) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }

    return 0;
}