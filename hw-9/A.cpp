#include <iostream>
#include<climits>


using namespace std;

class Node {
public:

    int key;
    int prev;
    int treeHeight;
    Node* left;
    Node* right;

    Node(int newKey)
    {
        key = newKey;
        prev = rand();
        treeHeight = 1;
        left = right = nullptr;
    }
};

int getTreeHeight(Node* t) {

    if (t == nullptr) { return 0; }

    return t->treeHeight;
}

void update(Node* t)
{
    if (t != nullptr)
    {
        t->treeHeight = 1 + getTreeHeight(t->left) + getTreeHeight(t->right);
    }
}

Node* merge(Node* t1, Node* t2) {
    if (t1 == nullptr) { return t2; }
    if (t2 == nullptr) { return t1; }

    if (t1->prev > t2->prev) {

        t1->right = merge(t1->right, t2);

        update(t1);
        return t1;
    }
    else {
        t2->left = merge(t1, t2->left);

        update(t2);
        return t2;
    }
}

void split(Node* t, int key, Node*& t1, Node*& t2) {

    if (t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }

    if (t->key < key) {
        split(t->right, key, t->right, t2);
        t1 = t;
    }
    else {
        split(t->left, key, t1, t->left);
        t2 = t;
    }

    update(t);
}

void add(Node*& t, int key)
{
    Node* t1, * t2;
    split(t, key, t1, t2);

    Node* new_tree = new Node(key);
    t = merge(merge(t1, new_tree), t2);
}

void remove(Node*& t, int key)
{
    Node* t1, * t2, * t3, * t4;
    split(t, key, t1, t2);
    split(t2, key + 1, t3, t4);

    t = merge(t1, t4);
    delete t3;
}

string exists(Node* t, int key) {
    if (t == nullptr) {
        return "false";
    }
    if (t->key == key) {
        return "true";
    }

    return exists(t->key > key ? t->left : t->right, key);
}

int next(Node* t, int key, int tempKey) {
    if (t == nullptr) {
        return tempKey;
    }

    if (t->key > key) {
        if (t->key < tempKey) {
            tempKey = t->key;
            tempKey = next(t->left, key, tempKey);
        }
    }
    else {
        tempKey = next(t->right, key, tempKey);
    }

    return tempKey;
}

int prev(Node* t, int key, int tempKey) {
    if (t == nullptr) {
        return tempKey;
    }

    if (t->key < key) {
        if (t->key > tempKey) {
            tempKey = t->key;
            tempKey = prev(t->right, key, tempKey);
        }
    }
    else {
        tempKey = prev(t->left, key, tempKey);

    }

    return tempKey;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node* treap = nullptr;
    int key;
    string str;

    while (cin >> str) {
        if (str == "insert") {
            cin >> key;
            if (exists(treap, key) == "false") {
                add(treap, key);
            }

        }
        else if (str == "delete") {
            cin >> key;
            if (exists(treap, key) == "true") {
                remove(treap, key);
            }

        }
        else if (str == "exists") {
            cin >> key;
            cout << exists(treap, key) << "\n";
        }
        else if (str == "next") {
            cin >> key;
            key = next(treap, key, INT_MAX);
            if (key == INT_MAX) {
                cout << "none\n";
            }
            else {
                cout << key << "\n";
            }
        }
        else {
            cin >> key;
            key = prev(treap, key, INT_MIN);
            if (key == INT_MIN) {
                cout << "none\n";
            }
            else {
                cout << key << "\n";
            }
        }
    }

    while (getTreeHeight(tree)) {
        tree = remove(tree, 0);
    }

    return 0;
}