#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Heap {
public:
    int* pointer;
    int* decKey;
    size_t capacity;
    size_t size;
    size_t keyMin;

    Heap() :
        pointer(new int[1]),
        decKey(new int[1]),
        capacity(1),
        size(0),
        keyMin(0)

    {} // конструктор

    ~Heap() { // деструктор
        delete[] pointer;
        delete[] decKey;
    }

    void expand() { // расширяет массивы
        int* newPointer = new int[2 * capacity];
        int* newDecKey = new int[2 * capacity];

        for (size_t i = 0; i < capacity; ++i) {
            newPointer[i] = pointer[i];
            newDecKey[i] = decKey[i];
        }

        capacity *= 2;

        delete[] pointer;
        pointer = newPointer;

        delete[] decKey;
        decKey = newDecKey;
    }
    void constrict() { // сужает массивы
        capacity /= 2;
        int* newPointer = new int[capacity];
        int* newDecKey = new int[capacity];

        for (size_t i = 0; i < capacity; ++i) {
            newPointer[i] = pointer[i];
            newDecKey[i] = decKey[i];
        }

        delete[] pointer;
        pointer = newPointer;

        delete[] decKey;
        decKey = newDecKey;
    }

    void push(const int& x, const int& key) { // добавляет элемент
        if (capacity - size <= 0)
            expand();

        int i = size++;
        int cur = (i - 1) / 2;
        pointer[i] = x;
        decKey[i] = key;

        while (pointer[i] < pointer[cur]) {
            swap(pointer[i], pointer[cur]);
            swap(decKey[i], decKey[cur]);
            i = cur;
            cur = (i - 1) / 2;
        }
    }

    void decreaseKey(const int& x, const int& key) { // подставляет значение из ключа
        for (size_t i = 0; i < size; ++i) {
            if (key == decKey[i]) {
                pointer[i] = x;

                int j = i;
                int cur = (j - 1) / 2;

                while (pointer[j] < pointer[cur]) {
                    swap(pointer[j], pointer[cur]);
                    swap(decKey[j], decKey[cur]);
                    j = cur;
                    cur = (j - 1) / 2;
                }

                i = size;
            }
        }
    }
    int removeKeyMin() { // возвращает ключ вершины
        return keyMin;
    }


    int removeMin() { // возвращает вершину
        if (size == 0)
            return INT_MAX;

        if (4 * --size == capacity)
            constrict();

        int x = pointer[0];
        keyMin = decKey[0] + 1;

        pointer[0] = pointer[size];

        decKey[0] = decKey[size];
        decKey[size] = -1;

        heapify(0);

        return x;
    }

    void heapify(int i) { // исправляет кучу
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int temp;

        if (l < size && pointer[i] > pointer[l] && (r >= size || pointer[r] > pointer[l])) {
            swap(pointer[i], pointer[l]);
            swap(decKey[i], decKey[l]);
            heapify(l);
        }
        else if (r < size && pointer[i] > pointer[r]) {
            swap(pointer[i], pointer[r]);
            swap(decKey[i], decKey[r]);
            heapify(r);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Heap heap;

    int x;
    int key;
    int i = 0;

    string str;

    while (cin >> str) {
        if (str == "push") {
            cin >> x;
            heap.push(x, i++);
        }
        else if (str == "extract-min") {
            i++;
            x = heap.removeMin();
            key = heap.removeKeyMin();

            if (x == INT_MAX)
                cout << '*' << "\n";
            else
                cout << x << " " << key << "\n";
        }
        else if (str == "decrease-key") {
            i++;
            cin >> key >> x;
            heap.decreaseKey(x, key - 1);
        }
    }

    return 0;
}

/*
push 3
push 4
push 2
extract-min
decrease-key 2 1
extract-min
extract-min
extract-min
decrease-key 2 1
*/