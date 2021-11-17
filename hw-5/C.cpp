#include <iostream>
#include <vector>
#include <list>
using namespace std;

const size_t SIZE = 5881;

class HashTable {
    const size_t PARAMETR = 179;

    vector<list<pair<string, list<string>::iterator>>> table;
    list<string> nameKey;
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
        table.resize(size);
    }

    ~HashTable() {
        for (size_t i = 0; i < size; ++i)
            table[i].clear();

        table.clear();

        nameKey.clear();
    }


    void put(const string& key, const string& name) {
        size_t index = hFun(key);
        auto n = table[index].end();
        bool flag = true;

        for (auto i = table[index].begin(); i != n; ++i)
            if (key == (*i).first) {
                *(*i).second = name;

                i = n;
                --i;
                flag = false;
            }

        if (flag) {
            nameKey.push_back(name);
            table[index].push_back(make_pair(key, --nameKey.end()));
        }
    }

    void get(const string& key) {
        size_t index = hFun(key);
        auto n = table[index].end();
        bool flag = true;

        for (auto i = table[index].begin(); i != n; ++i)
            if (key == (*i).first) {
                cout << *(*i).second << "\n";

                i = n;
                --i;
                flag = false;
            }

        if (flag) {
            cout << "none\n";
        }
    }

    void deleteKey(const string& key) {
        size_t index = hFun(key);
        auto n = table[index].end();

        for (auto i = table[index].begin(); i != n; ++i)
            if (key == (*i).first) {
                nameKey.erase((*i).second);
                table[index].erase(i);

                i = n;
                --i;
            }
    }

    void prev(const string& key) {
        size_t index = hFun(key);
        auto n = table[index].end();
        bool flag = true;

        for (auto i = table[index].begin(); i != n; ++i)
            if (key == (*i).first) {
                auto j = (*i).second;

                if (j != nameKey.begin()) {
                    cout << *(--j) << "\n";
                }
                else {
                    cout << "none\n";
                }

                i = n;
                --i;
                flag = false;
            }

        if (flag) {
            cout << "none\n";
        }
    }

    void next(const string& key) {
        size_t index = hFun(key);
        auto n = table[index].end();
        bool flag = true;

        for (auto i = table[index].begin(); i != n; ++i)
            if (key == (*i).first) {
                auto j = (*i).second;

                if (++j != nameKey.end()) {
                    cout << *j << "\n";
                }
                else {
                    cout << "none\n";
                }

                i = n;
                --i;
                flag = false;
            }

        if (flag) {
            cout << "none\n";
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
            hT.deleteKey(key);
        }
        else if (key == "prev") {
            cin >> key;
            hT.prev(key);
        }
        else {
            cin >> key;
            hT.next(key);
        }
    }

    return 0;
}