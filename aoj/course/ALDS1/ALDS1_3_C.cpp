#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string cmd;
    int x;
    
    list<int> ls;

    for(int i = 0; i < n; ++i){
        cin >> cmd;
        if(cmd == "insert"){
            cin >> x;
            ls.push_front(x);
        }else if(cmd == "delete"){
            cin >> x;
            int ct = 0;
            for(auto it = ls.begin(); it != ls.end(); ++it){
                if(*it == x){
                    ls.erase(it);
                    break;
                }
            }
        }else if(cmd == "deleteFirst"){
            ls.pop_front();
        }else if(cmd == "deleteLast"){
            ls.pop_back();
        }
    }

    for(auto it = ls.begin(); it != ls.end(); ++it){
        if(it != ls.begin()) cout << ' ';
        cout << *it;
    }
    cout << endl;
}
