#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    map<string,int> m;
    cin >> q;

    for(int i=0; i<q; ++i){
        int cmd;
        string key;
        cin >> cmd >> key;

        if(cmd == 0){
            int x;
            cin >> x;
            m[key] = x;
        }
        if(cmd == 1){
            // [] は対応する要素が存在しない場合は初期値で生成して返す。
            cout << m[key] << endl;
        }
        if(cmd == 2){
            m.erase(key);
        }
    }

    return 0;
}
