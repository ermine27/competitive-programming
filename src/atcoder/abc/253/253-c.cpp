#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int q;
    cin >> q;
    map<int,int> m;
    rep(i,q){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int x;
            cin >> x;
            m[x]++;
        }
        if(cmd == 2){
            int x,c;
            cin >> x >> c;
            m[x] -= min(c, m[x]);
            if(m[x] == 0) m.erase(x);
        }
        if(cmd == 3){
            auto max = prev(m.end());
            auto min = m.begin();
            cout << (*max).first - (*min).first << endl;

        }
    }
}
