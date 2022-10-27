#include <bits/stdc++.h>
using namespace std;

int main(){
    string w,t;
    cin >> w;
    int ans = 0;
    for(int i = 0; i < w.length(); ++i) if(isupper(w[i])) w[i] = tolower(w[i]);

    while(true){
        cin >> t;
        if(t == "END_OF_TEXT") break;
        for(int i = 0; i < t.length(); ++i) if(isupper(t[i])) t[i] = tolower(t[i]);
        if(t == w) ++ans;
    }
    cout << ans << endl;
}
