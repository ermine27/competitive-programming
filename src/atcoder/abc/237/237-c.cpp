#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()


int main(){
    string s;
    cin >> s;

    int len = s.length();
    int left = 0, right = 0;
    while(s[left] == 'a')  ++left;
    while(s[len-right-1] == 'a')  ++right;

    int c = min(left,right);
    int d = 0;
    if(left < right){
        d = right - left;
    }
    s = s.substr(c, len - c*2 - d);

    string rs;
    rs = s;
    reverse(all(rs));

    if(s == rs)  cout << "Yes";
    else cout << "No";
}
