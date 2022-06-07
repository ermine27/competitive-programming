#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int q;
    cin >> s >> q;
    
    for(int i = 0; i < q; ++i){
        string cmd, p;
        int a, b;
        cin >> cmd >> a >> b;

        if(cmd == "replace"){
            cin >> p;
            s = s.replace(a, b-a+1, p);
        }

        if(cmd == "reverse"){
            string sr = s;
            for(int j = 0; j < b-a+1; ++j){
                s[a+j] = sr[b-j];
            }
        }

        if(cmd == "print"){
            cout << s.substr(a,b-a+1) << endl;
        }

    }
}

