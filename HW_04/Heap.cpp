#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Heap {
public:
    int* pointer;
    int* decKey;
    size_t capacity;
    size_t size;

    Heap() :
        pointer(new int[1]),
        decKey(new int[1]),
        capacity(1),
        size(0)
    {} // конструктор

        ~Heap() { // деструктор
        delete[] pointer;
        delete[] decKey;
    }

    void expandHeap() { // расширяет массив кучи
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
    void constrictHeap() { // сужает массив кучи
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

    void push(const int& x, const int& key) {// добавляет элемент
        if (capacity - size <= 0)
            expandHeap();

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
    void outHeap(void) { // вывод элементов
        int i = 0;
        int k = 1;
        while (i < size) {
            while ((i < k) && (i < size)) {
                cout << pointer[i] << " ";
                i++;
            }
            cout << endl;
            k = k * 2 + 1;
        }
    }

    void decreaseKey(const int& x, const int& key) {
        for (size_t i = 0; i < size; ++i){
            if ( key == decKey[i]) {
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

    int removeMin() { // возвращает вершину
        if (size == 0)
            return 2000000000;

        if (4 * --size == capacity)
            constrictHeap();
        
        int x = pointer[0];
        pointer[0] = pointer[size];

        decKey[0] = decKey[size];
        decKey[size] = -1;

        heapify(0);

        return x;
    }

    int removeKey(const int& i) {
        return decKey[i];
    }

    void heapify(int i) { // исправляет кучу
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int temp;

        if (l < size && pointer[i] > pointer[l]) {
            swap(pointer[i], pointer[l]);
            swap(decKey[i], decKey[l]);
            heapify(l);
        }

        if (r < size && pointer[i] > pointer[r]) {
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
    int i=0;


    string str;

    while (cin >> str) {
        if (str == "lox")
            break;
        
        if (str == "push") {
            cin >> x;
            heap.push(x, i++);
        } else if (str == "extract-min") {
            i++;
            x = heap.removeMin();

            if (x == 2000000000)
                cout << '*' << "\n";
            else
                cout << x << "\n";
        } else if (str == "decrease-key") {
            i++;
            cin >> key >> x;
            heap.decreaseKey(x, key-1);
        }     
    }

    system ("pause");

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