#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


struct node {
    int key;
    node *parent, *left, *right;
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
    z->parent = y;

    if(y == NIL) root = z;
    else if(z->key < y->key) y->left = z;
    else y->right = z;
}

// 探索
node* find(int k){
    node *x;
    x = root;
    while(x != NIL){
        if(x->key == k) return x;
        if(x->key > k) x = x->left;
        else x = x->right;
    }

    return NIL;
}

// 削除
void del(int k){
    node *z, *p, *y;
    z = find(k);

    // 削除する節点yを決める
    // 子が0個または1個の場合は、削除するキーがある節点になる
    // 子が2個の場合は、次節点（中間順巡回で次に得られる節点）になる
    if(z->left == NIL || z->right == NIL){
        y = z;
    } else {
        // 次接点を探す
        y = z->right;
        while(true){
            if(y->left != NIL) y = y->left;
            else if(y->right != NIL) y = y->right;
            else break;
        }

    }
    
    p = y->parent;

    // zの子が2つある場合
    // 1. zの親の子を削除にする
    // 2. zの次接点yのキーをzのキーへコピーする
    if(z->left != NIL && z->right != NIL){
        if(p->left == y){
            p->left = NIL;
        } else {
            p->right = NIL;
        }

        z->key = y->key;

    // zの子が1個の場合
    // 1. zの親の子を自身の子にする
    // 2. zの子の親を自身の親にする

    // 削除する節点の左側に子がある
    } else if(z->left != NIL){
        // zが親の左側の子である
        if(p->left == y){
            p->left = y->left;
        // zが親の右側の子である
        } else {
            p->right = y->left;
        }
        // zの子の親をzの親にする
        y->left->parent = p;

    // 削除する節点の右側に子がある
    } else if(z->right != NIL){
        if(p->left == y){
            p->left = y->right;
        } else {
            p->right = y->right;
        }
        y->right->parent = p;

    // zの子が0個の場合
    // zの親の子を削除にする
    } else {
        if(p->left == y){
            p->left = NIL;
        } else {
            p->right = NIL;
        }
    }

    // yを木から削除
    delete y;
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
            cout << (find(val) != NIL ? "yes" : "no") << endl;
        } else if(cmd == "delete"){
            cin >> val;
            del(val);
        } else {
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}
