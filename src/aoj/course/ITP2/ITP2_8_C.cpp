#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    map<string,int> m;
    cin >> q;

    for(int i=0; i<q; ++i){
        int cmd,x;
        string key,l,r;
        cin >> cmd;
        if(cmd==3) cin >> l >> r;
        else cin >> key;

        if(cmd == 0){
            cin >> x;
            m[key] = x;
        }
        if(cmd == 1){
            // [] は対応する要素が存在しない場合は初期値で生成して返してしまう
            // dumpの際に存在しないキーの値が出力されてしまうので次行の書き方はNG
            // cout << (m[key] ?: 0) << endl;
            cout << (m.count(key) ? m[key] : 0) << endl;
        }
        if(cmd == 2){
            m.erase(key);
        }
        if(cmd == 3){
            for(auto it=m.lower_bound(l); it!=m.upper_bound(r); ++it){
                cout << it->first << ' ' << it->second << endl;
            }
        }
    }

    return 0;
}
