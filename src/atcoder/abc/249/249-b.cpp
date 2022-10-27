#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    string s;
    cin >> s;
    int slen = s.length();

    bool hasb = false, hass = false;
    rep(i,slen){
        if(isupper(s[i])) hasb = true;
        if(islower(s[i])) hass = true;
    }
    if(hasb == false || hass == false){
        cout << "No";
        return 0;        
    }

    rep(i,slen-1){
        reps(j,i+1,slen){
            if(s[i] == s[j]){
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}