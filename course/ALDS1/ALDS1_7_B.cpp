#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;


const int  NIL = -1;

struct Node{
    int parent, left_child, right_child;
};
vector<Node> tree;
vi d;
vi h;


void setDepth(int u, int p){
    d[u] = p;
    if(tree[u].right_child != NIL)
        setDepth(tree[u].right_child, p+1);
    if(tree[u].left_child != NIL){
        setDepth(tree[u].left_child, p+1);
    }
}

int setHeight(int u){
    int h1 = 0, h2 = 0;

    if(tree[u].left_child != NIL)
        h1 = setHeight(tree[u].left_child) + 1;
    if(tree[u].right_child != NIL)
        h2 = setHeight(tree[u].right_child) + 1;

    return max(h1,h2);
}

int main(){
    int n;
    cin >> n;
    tree.resize(n);
    rep(i,n)  tree[i].parent = tree[i].left_child = tree[i].right_child = NIL;
    d.resize(n);
    h.resize(n);

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

    rep(i,n){
        h[i] = setHeight(i);
    }

    int root;
    rep(i,n){
        if(tree[i].parent == NIL) root = i;
    }

    setDepth(root,0);

    rep(i,n){
        int sibling, left, right, degree, depth, height;
        sibling = tree[i].parent;
        if(sibling != NIL){
            left = tree[sibling].left_child;
            right = tree[sibling].right_child;
            sibling = i == left ? right : left;
        }

        degree = 0;
        if(tree[i].left_child != NIL) ++degree;
        if(tree[i].right_child != NIL) ++degree;

        string type;
        if(tree[i].parent == -1) type = "root";
        else {
            if(tree[i].left_child == -1 && tree[i].right_child == -1) type = "leaf";
            else type = "internal node";
        }

        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
         i, tree[i].parent, sibling, degree,  d[i], h[i], type.c_str());
    }

    return 0;
}
