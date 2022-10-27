#include <bits/stdc++.h>
using namespace std;

string solve(string s,int a,int b){
    swap(s[a-1],s[b-1]);
    return s;
}

int main() {
    int a,b;
    string s,ans;
    cin >> s;
    cin >> a >> b;
    
    ans = solve(s,a,b);
    
    cout << ans;
}
