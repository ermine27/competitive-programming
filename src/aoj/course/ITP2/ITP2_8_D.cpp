#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    multimap<string,int> mm;
    cin >> q;

    for(int i=0; i<q; ++i){
        int cmd,x;
        string key,l,r;
        cin >> cmd;

        if(cmd == 0){
            cin >> key >> x;
            mm.insert(make_pair(key,x));
        }
        if(cmd == 1){
            cin >> key;
            auto range = mm.equal_range(key);
            for(auto it = range.first; it != range.second; ++it){
                cout << it->second << endl;
            }
        }
        if(cmd == 2){
            cin >> key;
            mm.erase(key);
        }
        if(cmd == 3){
            cin >> l >> r;
            for(auto it=mm.lower_bound(l); it!=mm.upper_bound(r); ++it){
                cout << it->first << ' ' << it->second << endl;
            }
        }
    }

    return 0;
}
