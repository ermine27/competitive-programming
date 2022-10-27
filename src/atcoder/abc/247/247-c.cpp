#include <bits/stdc++.h>
using namespace std;

void dfs(int x){
    if(x == 1){
        cout << 1 << ' ';
        return;
    }

    dfs(x-1);
    cout << x << ' ';
    dfs(x-1);
}

int main(){
    int n;
    cin >> n;

    dfs(n);
}
