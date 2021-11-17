#include <iostream>
#include <vector>
#include <list>
using namespace std;

const size_t SIZE = 5881;

class HashTable {
    const size_t PARAMETR = 179;

    vector<list<pair<string, string>>> tablePair;
    vector<list<list<pair<string, string>>::iterator>> tableIt;
    size_t size;

    size_t hFun(const string& key) {
        size_t hash = 0;
        size_t a = PARAMETR;

        for (size_t i = 0; i < key.length(); ++i) {
            hash += a * (key[i]);
            a *= PARAMETR;
            a %= size;
        }

        return hash % size;
    }

public:
    HashTable() {
        size = 0;
    }

    HashTable(const int& newSize) {
        size = newSize;
        tablePair.resize(size);
        tableIt.resize(size);
    }

    ~HashTable() {
        for (size_t i = 0; i < size; ++i) {
            tablePair[i].clear();
            tableIt[i].clear();
        }

        tablePair.clear();
        tableIt.clear();
    }

    void put(const string& key, const string& name) {
        size_t index1 = hFun(key);
        size_t index2 = hFun(key + name);
        auto n = tableIt[index2].end();
        bool flag = true;

        for (auto i = tableIt[index2].begin(); i != n; ++i)
            if (key == (*(*i)).first, name == (*(*i)).second) {
                i = n;
                --i;
                flag = false;
            }

        if (flag) {
            tablePair[index1].push_back(make_pair(key, name));
            tableIt[index2].push_back(--tablePair[index1].end());
        }
    }

    void get(const string& key) {
        size_t index1 = hFun(key);
        size_t numGet = 0;
        string strGet = "";
        auto n = tablePair[index1].end();

        for (auto i = tablePair[index1].begin(); i != n; ++i)
            if (key == (*i).first) {
                ++numGet;
                strGet += " " + (*i).second;
            }

        cout << to_string(numGet) + strGet << "\n";
    }

    void deletePair(const string& key, const string& name) {
        size_t index1 = hFun(key);
        size_t index2 = hFun(key + name);
        auto n = tableIt[index2].end();

        for (auto i = tableIt[index2].begin(); i != n; ++i)
            if (key == (*(*i)).first, name == (*(*i)).second) {
                tablePair[index1].erase(*i);
                tableIt[index2].erase(i);

                i = n;
                --i;
            }
    }

    void deleteAll(const string& key) {
        size_t index1 = hFun(key);
        auto i = tablePair[index1].begin();
        auto n = tablePair[index1].end();

        while (i != n) {
            if (key == (*i).first) {
                auto j = i;
                i++;

                string name = (*j).second;
                size_t index2 = hFun(key + name);

                tableIt[index2].remove(j);
                tablePair[index1].erase(j);
            }
            else {
                i++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string key;
    string name;
    HashTable hT(SIZE);

    while (cin >> key) {
        if (key == "put") {
            cin >> key;
            cin >> name;
            hT.put(key, name);
        }
        else if (key == "get") {
            cin >> key;
            hT.get(key);
        }
        else if (key == "delete") {
            cin >> key;
            cin >> name;
            hT.deletePair(key, name);
        }
        else {
            cin >> key;
            hT.deleteAll(key);
        }
    }

    return 0;
}