#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const size_t SIZE = 1000003;

class HashTable {
    const int INT_FIRST_15_BIT = 32767;
    const int INT_SECOND_16_BIT = 2147450880;
    const int EMPT = INT_MAX;
    const int RIP = INT_MIN;

    vector<int> table;
    size_t size;

    size_t hFun(const int& key) {
        return (2 * (key & INT_SECOND_16_BIT) + 4 * (key & INT_FIRST_15_BIT)) % size;
    }

public:
    HashTable() {
        size = 0;
    }

    HashTable(const int& newSize) {
        size = newSize;
        table.resize(size);

        for (size_t i = 0; i < size; i++) {
            table[i] = EMPT;
        }
    }

    ~HashTable() {
        table.clear();
    }

    void insert(const int& key) {
        size_t index = hFun(key);
        size_t indexRip = -1;
        bool flag = true;

        for (size_t i = 0; i < size; ++i) {
            size_t j = (index + i) % size;

            if (flag && table[j] == RIP) {
                indexRip = j;
                flag = false;
            }

            if (table[j] == EMPT || table[j] == RIP && i + 1 == size) {
                if (flag) {
                    table[j] = key;
                }
                else {
                    table[indexRip] = key;
                }
                i = size;
            }
            if (table[j] == key) {
                i = size;
            }
        }
    }

    void exists(const int& key) {
        size_t index = hFun(key);

        for (size_t i = 0; i < size; ++i) {
            size_t j = (index + i) % size;

            if (table[j] == EMPT) {
                cout << "false\n";
                i = size;
            }

            if (table[j] == key) {
                cout << "true\n";
                i = size;
            }
        }

        if (size == 0) {
            cout << "false\n";
        }
    }

    void deleteKey(const int& key) {
        size_t index = hFun(key);

        for (size_t i = 0; i < size; ++i) {
            size_t j = (index + i) % size;

            if (table[j] == EMPT) {
                i = size;
            }
            if (table[j] == key) {
                table[j] = RIP;
                i = size;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    HashTable hT(SIZE);

    string func;
    int key;

    while (cin >> func) {
        if (func == "insert") {
            cin >> key;
            hT.insert(key);
        }
        else if (func == "exists") {
            cin >> key;
            hT.exists(key);
        }
        else {
            cin >> key;
            hT.deleteKey(key);
        }
    }

    return 0;
}