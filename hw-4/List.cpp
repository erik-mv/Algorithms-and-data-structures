#include <iostream>
using namespace std;

class Node
{
    int field;
    class Node* ptr;
    friend class List;
};

class List
{
    Node* head;    // Корень списка
    int size; // Количество узлов списка
    int min;
    int sizeMin;


    Node* Prev(Node* node)
    {
        if (isEmpty()) return NULL;
        if (node == head) return NULL;
        Node* p = head;
        while (p->ptr != node)
            p = p->ptr;
        return p;
    } // Переход к предыдущему узлу (не интерфейсный метод)
public:
    List() :
        head(NULL),
        size(0),
        min(2147483647),
        sizeMin(0)
    {} // Инициализация списка

    ~List() {
        class Node* p = head;
        if (p == NULL) return;
        do {
            Node* d = p;
            p = next(p);
            delete d;
        } while (p != NULL);
        size = 0;
        head = NULL;
    }

    int removeMin() {
        return min;
    }

    int getSize() {// Получение количества узлов списка
        return size;
    }

    bool isEmpty() {// Проверка, пуст ли список
        return head == NULL;
    }

    int getValue(Node* p) {// Получение значения узла списка
        return p->field;
    }

    void setValue(Node* p, int val) {// Установка значения узла списка
        p->field = val;
    }

    Node* getFirst() { // Получение корневого узла списка
        return head;
    }

    Node* getLast() {// Получение последнего узла списка
        Node* p = head;
        while (next(p) != NULL)
            p = next(p);
        return p;
    }
    void clear() { // Очистка списка
        class Node* p = head;
        if (p == NULL) return;
        do {
            Node* d = p;
            p = next(p);
            delete d;
        } while (p != NULL);
        size = 0;
        head = NULL;
    }

    Node* next(Node* node) { // Переход к следующему узлу
        if (isEmpty()) return NULL;
        return node->ptr;
    }
    Node* push(int num, Node* node = NULL) { // Добавление узла списка
        Node* elem = new Node();
        elem->field = num;
        size++;

        if (num == min)
            sizeMin++;
        else if (num < min) {
            min = num;
            sizeMin = 1;
        }

        if (node == NULL) {
            if (head == NULL) {
                elem->ptr = NULL;
                head = elem;
            }
            else {
                elem->ptr = head;
                head = elem;
            }
            return elem;
        }

        elem->ptr = node->ptr;
        node->ptr = elem;

        return elem;
    }

    void findMin() {
        Node* p = head;
        int tempMin = getValue(p);

        while (next(p) != NULL) {
            p = next(p);
            int temp = getValue(p);
            if (tempMin > temp)
                tempMin = temp;
        }

        min = tempMin;
        sizeMin = 0;

        p = head;
        do {
            if (getValue(p) == min)
                sizeMin++;
            p = next(p);
        } while (p != NULL);
    }

    Node* pop(Node* node) { // Удаление узла списка
        if (node == NULL)
            return NULL;
        size--;

        int tempMin = getValue(node);

        if (node == head) {
            head = node->ptr;
            delete node;
            return head;
        }

        Node* prev = Prev(node);
        prev->ptr = node->ptr;
        delete node;
        return prev;

        if (tempMin == min) {
            sizeMin--;
            if (sizeMin == 0)
                findMin();
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Not list" << endl;
            return;
        }

        Node* p = head;
        do {
            cout << getValue(p) << " ";
            p = next(p);
        } while (p != NULL);
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    List list;
    int k;



    for (size_t i = 0; i < n; ++i) {
        cin >> k;

        if (k == 1) {
            cin >> k;
            list.push(k);
            //list.print();
            //cout << list.removeMin() << "\n\n";
        }
        else if (k == 2) {
            Node* p = list.getFirst();
            p = list.pop(p);
            //list.print();
        }
        else {
            cout << list.removeMin() << "\n";
        }
    }

    return 0;
}

/*
18
1 2
1 3
3
3
2
1 -3
1 -4
3
2
2
1 -10
1 16
1 10
3
3
2
2
3
*/