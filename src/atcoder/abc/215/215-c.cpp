#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()


int main(){
    string s;
    int k;
    cin >> s >> k;
    sort(all(s));

    do{
        --k;
        if(k == 0) break;
    } while(next_permutation(all(s)));

    cout << s;
}