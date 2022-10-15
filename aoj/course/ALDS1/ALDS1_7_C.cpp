#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


const int NIL = -1;

struct Node{
    int parent, left_child, right_child;
};
vector<Node> tree;

// 木の先行順巡回（根接点、左部分木、右部分木の順に出力する）
void preOrder(int x){
    if(x == NIL) return;

    cout << ' ' << x;
    preOrder(tree[x].left_child);
    preOrder(tree[x].right_child);
}

// 木の中間順巡回（左部分木、根接点、右部分木の順に出力する）
void inOrder(int x){
    if(x == NIL) return;

    inOrder(tree[x].left_child);
    cout << ' ' << x;
    inOrder(tree[x].right_child);
}

// 木の後行順巡回（左部分木、右部分木、根接点の順に出力する）
void postOrder(int x){
    if(x == NIL) return;

    postOrder(tree[x].left_child);
    postOrder(tree[x].right_child);
    cout << ' ' << x;
}

int main(){
    int n;
    cin >> n;
    tree.resize(n);
    rep(i,n)  tree[i].parent = tree[i].left_child = tree[i].right_child = NIL;

    int id, l, r;
    rep(i,n){
        cin >> id >> l >> r;

        tree[id].left_child = l;
        tree[id].right_child = r;
        if(l != NIL){
            tree[l].parent = id;
        }
        if(r != NIL){
            tree[r].parent = id;
        }
    }

    int root;
    rep(i,n){
        if(tree[i].parent == NIL) root = i;
    }

    cout << "Preorder" << endl;
    preOrder(root);
    cout << endl;

    cout << "Inorder" << endl;
    inOrder(root);
    cout << endl;

    cout << "Postorder" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
