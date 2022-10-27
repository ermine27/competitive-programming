#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    string w;
    cin >> w;
    rep(i,w.length()){
        char c = w[i];
        if(c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') cout << c;
    }
    cout << endl;
}
