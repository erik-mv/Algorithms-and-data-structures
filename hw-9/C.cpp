#include <iostream>

using namespace std;

class Node {
public:

    int prev;
    int treeHeight;
    int val;

    Node* left, * right;
};

Node* newNode(int val) {
    Node* result = new Node;
    result->prev = rand();
    result->treeHeight = 1;

    result->val = val;
    result->left = result->right = nullptr;
    return result;
}


int getTreeHeight(Node* t) {
    if (t == nullptr) { return 0; }
    return t->treeHeight;
}


void updTreeHeight(Node* t) {
    if (t == nullptr) {
        t->treeHeight = 0;
    }
    else {
        t->treeHeight = 1 + getTreeHeight(t->left) + getTreeHeight(t->right);
    }
}

Node* merge(Node* t1, Node* t2) {
    if (t1 == nullptr) { return t2; }
    if (t2 == nullptr) { return t1; }
    if (t1->prev > t2->prev) {
        t1->right = merge(t1->right, t2);
        updTreeHeight(t1);
        return t1;
    }
    else {
        t2->left = merge(t1, t2->left);
        updTreeHeight(t2);
        return t2;
    }
}


void split(Node* t, int x, Node*& t1, Node*& t2) {
    if (t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }

    if (getTreeHeight(t->left) < x) {
        split(t->right, x - getTreeHeight(t->left) - 1, t->right, t2);
        t1 = t;
    }
    else {
        split(t->left, x, t1, t->left);
        t2 = t;
    }
    updTreeHeight(t);
}

Node* add(Node* t, int pos, int val) {
    Node* t1, * t2;
    split(t, pos, t1, t2);
    Node* new_tree = newNode(val);
    return merge(merge(t1, new_tree), t2);
}

Node* remove(Node* t, int pos) {
    Node* t1, * t2, * t3, * t4;
    split(t, pos, t1, t2);
    split(t2, 1, t3, t4);
    t = merge(t1, t4);

    delete t3;
    return t;
}

void print(Node* t) {
    if (t == nullptr) { return; }
    print(t->left);
    cout << t->val << " ";
    print(t->right);
}

Node* toFront(Node* t, int l, int r)
{
    Node* t1, * t2, * t3, * t4;

    split(t, r + 1, t1, t2);
    split(t1, l, t3, t4);

    return merge(merge(t4, t3), t2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    Node* treap = nullptr;

    for (size_t i = 0; i < n; ++i) {
        treap = add(treap, i, i + 1);
    }

    for (size_t i = 0; i < m; ++i) {
        int left;
        int right;
        cin >> left >> right;
        treap = toFront(treap, left - 1, right - 1);
    }

    print(treap);

    while (getTreeHeight(treap)) {
        treap = remove(treap, 0);
    }

    return 0;
}