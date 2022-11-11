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
        } else {            
            cout << m[key] << endl;
        }
    }

    return 0;
}
