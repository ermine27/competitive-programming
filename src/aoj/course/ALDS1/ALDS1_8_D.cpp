#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)

struct node {
    int key, priority;
    node *parent, *left, *right;
};

node *root, *NIL;

node* rightRotate(node* t);
node* leftRotate(node* t);
node* insert(node* t, int key, int priority);
node* find(int k);
node* del(node* t, int key);
node* _del(node* t, int key);
void preOrder(node* x);
void inOrder(node* x);

// 右回転
node* rightRotate(node* t) {
    node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

// 左回転
node* leftRotate(node* t) {
    node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

// 追加
node* insert(node* t, int key, int priority) {
    node* z = new node;
    z->key = key;
    z->priority = priority;
    z->left = z->right = NIL;

    if (t == NIL)
        return z;

    if (key == t->key)
        return t;

    if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority)
            t = rightRotate(t);
    } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority)
            t = leftRotate(t);
    }

    return t;
}

// 探索
node* find(int k) {
    node* x;
    x = root;
    while (x != NIL) {
        if (x->key == k)
            return x;
        if (x->key > k)
            x = x->left;
        else
            x = x->right;
    }

    return NIL;
}

// 削除
node* del(node* t, int key) {
    if (t == NIL)
        return NIL;

    if (key < t->key)
        t->left = del(t->left, key);
    else if (key > t->key)
        t->right = del(t->right, key);
    else
        return _del(t, key);

    return t;
}

// 削除対象の節点の場合
node* _del(node* t, int key) {
    if (t->left == NIL && t->right == NIL)
        return NIL;
    else if (t->left == NIL)
        t = leftRotate(t);
    else if (t->right == NIL)
        t = rightRotate(t);
    else {
        if (t->left->priority > t->right->priority)
            t = rightRotate(t);
        else
            t = leftRotate(t);
    }

    return del(t, key);
}

// 木の先行順巡回（根接点、左部分木、右部分木の順に出力する）
void preOrder(node* x) {
    if (x == NIL)
        return;
    cout << ' ' << x->key;
    preOrder(x->left);
    preOrder(x->right);
}

// 木の中間順巡回（左部分木、根接点、右部分木の順に出力する）
void inOrder(node* x) {
    if (x == NIL)
        return;
    inOrder(x->left);
    cout << ' ' << x->key;
    inOrder(x->right);
}

int main() {
    int n;
    cin >> n;
    string cmd;
    int val, pri;

    rep(i, n) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> val >> pri;
            root = insert(root, val, pri);
        } else if (cmd == "find") {
            cin >> val;
            cout << (find(val) != NIL ? "yes" : "no") << endl;
        } else if (cmd == "delete") {
            cin >> val;
            root = del(root, val);
        } else {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}
