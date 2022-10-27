/*
構造体を使わず二次元配列を使って解く
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;


int main(){
    int n;
    cin >> n;

    int id,k,ci;
    vi parent(n,-1);
    vvi child(n);

    rep(i,n){
        cin >> id >> k;
        rep(j,k){
            cin >> ci;
            parent[ci] = id;
            child[id].emplace_back(ci);
        }
    }

    rep(i,n){
        int d = 0;
        int di = i;
        while(parent[di] != -1) {
            di = parent[di];
            ++d;
        }
        string type;
        if(parent[i] == -1) type = "root";
        else {
            if(child[i].size() > 0) type = "internal node";
            else type = "leaf";
        }

        int ct = 0;
        string st = "";
        for(int c: child[i]){
            if(ct != 0) st += ", ";
            st += to_string(c);
            ++ct;
        }

        printf("node %d: parent = %d, depth = %d, %s, [%s]\n", i, parent[i], d, type.c_str(), st.c_str());
    }

    return 0;
}
