#include <iostream>
using namespace std;

class Vector {
public:
    int* pointer;
    size_t capacity;
    size_t size;
    size_t begin;

    Vector() :
        pointer(new int[1]),
        capacity(1),
        size(0),
        begin(0)
    {} // конструктор

    ~Vector() { // деструктор
        delete[] pointer;
    }

    void expand() { // расширяет массивы
        int newCapacity = 2 * capacity;
        int* newPointer = new int[newCapacity];

        for (size_t i = 0; i < capacity; ++i)
            newPointer[i] = pointer[(i + begin) % capacity];

        capacity = newCapacity;
        begin = 0;

        delete[] pointer;
        pointer = newPointer;
    }

    void constrict() { // сужает массивы
        int newCapacity = capacity / 2;
        int* newPointer = new int[newCapacity];

        for (size_t i = 0; i < newCapacity; ++i)
            newPointer[i] = pointer[(i + begin) % capacity];

        capacity = newCapacity;
        begin = 0;

        delete[] pointer;
        pointer = newPointer;
    }

    void push(const int& x) { // добавляет элемент
        if (capacity - size <= 0)
            expand();

        *(pointer + (begin + size++) % capacity) = x;
    }

    int pop() { // удаляет и возвращает элемент
        if (4 * --size == capacity)
            constrict();

        return pointer[begin++ % capacity];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Vector calc;
    int m;
    cin >> m;

    char sgn;

    while (m--) {
        cin >> sgn;

        if (sgn == '-')
            cout << calc.pop() << "\n";
        else {
            int x;
            cin >> x;

            calc.push(x);
        }
    }

    return 0;
}

/*
4
+ 1
+ 10
-
-
*/
/*
33
+ 1
+ 2
+ 3
+ 4
+ 5
+ 6
+ 7
+ 8
-
-
+ 9
+ 10
+ 11
+ 12
+ 13
+ 14
+ 15
+ 16
+ 17
+ 18
-
-
-
-
-
-
-
-
-
-
-
-
-


*/