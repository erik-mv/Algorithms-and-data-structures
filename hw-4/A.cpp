#include <iostream>
#include <climits>
using namespace std;
 
class Node
{
    int field;
    class Node* ptr;
    friend class List;
};
 
class List {
public:
    Node* head;
    int size;
    int min;
    int sizeMin;
 
 
    Node* Prev(Node* node) // переход к предыдущему узлу
    {
        if (head == NULL)
            return NULL;
 
        if (node == head)
            return NULL;
 
        Node* p = head;
        while (p->ptr != node)
            p = p->ptr;
 
        return p;
    }
 
    List() : // конструктор
        head(NULL),
        size(0),
        min(INT_MAX),
        sizeMin(0)
    {}
 
    ~List() { // деструктор
        class Node* p = head;
        if (p == NULL)
            return;
 
        do {
            Node* d = p;
            p = next(p);
            delete d;
        } while (p != NULL);
 
        size = 0;
        head = NULL;
    }
 
    int removeMin() { // возвращает минимальное значение
        return min;
    }
 
    int getValue(Node* p) {// возвращает значения узла
        return p->field;
    }
 
    Node* getFirst() { // возвращает корневой узел
        return head;
    }
 
    Node* next(Node* node) { // переход к следующему узлу
        if (head == NULL)
            return NULL;
 
        return node->ptr;
    }
    void push(int num, Node* node = NULL) { // добавляет узел списка
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
            
            return;
        }
 
        elem->ptr = node->ptr;
        node->ptr = elem;
 
        delete elem;
    }
 
    void findMin() { // находит минимальный элемент
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
 
    Node* pop(Node* node) { // удаляет узел и склеивает список, если удалили не с начала
        if (node == NULL)
            return NULL;
        size--;
 
        int tempMin = getValue(node);
 
        if (node == head) {
            head = node->ptr;
            delete node;
 
            if (size == 0)
                min = INT_MAX;
            else if (tempMin == min) {
                sizeMin--;
                if (sizeMin == 0)
                    findMin();
            }
 
            return head;
        }
 
        Node* prev = Prev(node);
        prev->ptr = node->ptr;
        delete node;
 
        if (size == 0)
            min = INT_MAX;
        else if (tempMin == min) {
            sizeMin--;
            if (sizeMin == 0)
                findMin();
        }
 
        return prev;
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
        }
        else if (k == 2) {
            Node* p = list.getFirst();
            p = list.pop(p);
        }
        else {
            cout << list.removeMin() << "\n";
        }
    }
 
    return 0;
}