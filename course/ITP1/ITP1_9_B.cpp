#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        string s;
        int m;
        cin >> s;
        if(s == "-") break;
        cin >> m;

        for(int i = 0; i < m; ++i){
            int h;
            cin >> h;
            s = s.substr(h) + s.substr(0,h);
        }
        cout << s << endl;
    }
}
