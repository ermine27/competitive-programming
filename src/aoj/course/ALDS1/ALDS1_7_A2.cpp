#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;


const int  NIL = -1;

// 左子右兄弟表現によって木を表す
struct Node{
    int parent, left_child, right_sibling;
};
vector<Node> tree;
vi d;


void setDepth(int u, int p){
    d[u] = p;
    if(tree[u].right_sibling != NIL)
        setDepth(tree[u].right_sibling, p);
    if(tree[u].left_child != NIL){
        setDepth(tree[u].left_child, p+1);
    }
}

int main(){
    int n;
    cin >> n;
    tree.resize(n);
    rep(i,n)  tree[i].parent = tree[i].left_child = tree[i].right_sibling = NIL;
    d.resize(n);

    int id, k, c, preleft;
    rep(i,n){
        cin >> id >> k;

        rep(j,k){
            cin >> c;
            if(j == 0)
                tree[id].left_child = c;
            else 
                tree[preleft].right_sibling = c;
            preleft = c;
            tree[c].parent = id;
        }
    }
    
    int r;
    rep(i,n){
        if(tree[i].parent == NIL) r = i;
    }

    setDepth(r,0);

    rep(i,n){
        string type;
        if(tree[i].parent == -1) type = "root";
        else {
            if(tree[i].left_child == -1) type = "leaf";
            else type = "internal node";
        }

        int cs = tree[i].left_child;
        int ct = 0;
        string st = "";
        while(cs != NIL){
            if(ct != 0) st += ", ";
            st += to_string(cs);
            ++ct;
            cs = tree[cs].right_sibling;
        }

        printf("node %d: parent = %d, depth = %d, %s, [%s]\n", i, tree[i].parent, d[i], type.c_str(), st.c_str());
    }

    return 0;
}

