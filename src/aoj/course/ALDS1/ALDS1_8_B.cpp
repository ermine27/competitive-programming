#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


struct node {
    int key;
    // node *parent, *left, *right;
    node *left, *right;
};

node *root, *NIL;

// 追加
void insert(int k){
    node *x,*y,*z;
    y = NIL;
    x = root;
    z = new node;

    z->key = k;
    z->left = z->right = NIL;
    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    // z->parent = y;

    if(y == NIL) root = z;
    else if(z->key < y->key) y->left = z;
    else y->right = z;
}

// 探索
bool find(int k){
    node *x;
    x = root;
    while(x != NIL){
        if(x->key == k) return true;
        if(x->key > k) x = x->left;
        else x = x->right;
    }

    return false;
}

// 木の先行順巡回（根接点、左部分木、右部分木の順に出力する）
void preOrder(node *x){
    if(x == NIL) return;
    cout << ' ' << x->key;
    preOrder(x->left);
    preOrder(x->right);
}

// 木の中間順巡回（左部分木、根接点、右部分木の順に出力する）
void inOrder(node *x){
    if(x == NIL) return;
    inOrder(x->left);
    cout << ' ' << x->key;
    inOrder(x->right);
}


int main(){
    int n;
    cin >> n;
    string cmd;
    int val;

    rep(i,n){
        cin >> cmd;
        if(cmd == "insert"){
            cin >> val;
            insert(val);
        } else if(cmd == "find"){
            cin >> val;
            cout << (find(val) ? "yes" : "no") << endl;
        } else {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}
