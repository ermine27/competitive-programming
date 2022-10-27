#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,p;
    cin >> s >> p;
    s = s + s;

    for(int i = 0; i < s.size(); ++i){
        if(s.substr(i,p.length()) == p){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
