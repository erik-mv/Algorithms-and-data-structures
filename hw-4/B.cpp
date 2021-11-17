#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Vector {
public:
    int* pointer;
    size_t capacity;
    size_t size;

    Vector() :
        pointer(new int[1]),
        capacity(1),
        size(0)
    {} // конструктор

    ~Vector() { // деструктор
        delete[] pointer;
    }

    void expand() { // расширяет массивы
        int* newPointer = new int[2 * capacity];

        for (size_t i = 0; i < capacity; ++i)
            newPointer[i] = pointer[i];

        capacity *= 2;

        delete[] pointer;
        pointer = newPointer;
    }

    void constrict() { // сужает массивы
        capacity /= 2;
        int* newPointer = new int[capacity];

        for (size_t i = 0; i < capacity; ++i)
            newPointer[i] = pointer[i];

        delete[] pointer;
        pointer = newPointer;
    }

    void push(const int& x) { // добавляет элемент
        if (capacity - size <= 0)
            expand();

        *(pointer + size++) = x;
    }

    int pop() { // удаляет и возвращает элемент
        if (4 * --size == capacity)
            constrict();

        return pointer[size];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);
    str += " ";
    istringstream s(str);

    Vector calc;
    int x;
    char sgn;

    while (!s.eof())
    {
        while (s >> x)
            calc.push(x);

        if (!s.eof())
        {
            s.clear();
            s.unget();
            s >> sgn;

            int b = calc.pop();
            int a = calc.pop();

            switch (sgn) {
            case '+':
                calc.push(a + b);
                break;
            case '-':
                calc.push(a - b);
                break;
            case '*':
                calc.push(a * b);
                break;
            }
        }
    }

    cout << calc.pop() << "\n";

    return 0;
}

/*
8 9 + 1 7 - * 102 - 10 10 -
8 9 + 1 7 - *
*/

/*
8 9 1 + -
*/