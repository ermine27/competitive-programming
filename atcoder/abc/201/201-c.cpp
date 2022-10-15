#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define npos string::npos


int main(){
    const string digit = "0123456789";
    string s;
    cin >> s;

    set<char> ok,ng;
    rep(i,10){
        char c = s[i];
        if(s[i] == 'o')  ok.insert(digit[i]);
        if(s[i] == 'x')  ng.insert(digit[i]);
    }

    int ans = 0;
    rep(i,10000){
        string si = to_string(i);
        int silen = si.length();
        rep(j, 4-silen){
            si = '0' + si;
        }

        bool judge = true;
        fore(x,ok){
            if(si.find(x) == npos) judge = false;
        }
        if(judge == false) continue;

        judge = true;
        fore(x,ng){
            if(si.find(x) != npos) judge = false;
        }
        if(judge == false) continue;

        ++ans;
    }

    cout << ans;
}