// 標準ライブラリ priority_queueを使って解く
#include <bits/stdc++.h>
using namespace std;


int main(){
    string cmd;
    int k;
    priority_queue<int> q;

    while(cin >> cmd && cmd != "end"){
        if(cmd == "insert"){
            cin >> k;
            q.push(k);
        } else {
            cout << q.top() << endl;
            q.pop();
        }
    }

    return 0;
}
