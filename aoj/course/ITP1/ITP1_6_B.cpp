#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> suit(n);
    vector<int> number(n);
    char suitkind[4] = {'S', 'H', 'C', 'D'};

    for(int i = 0; i < n; ++i) cin >> suit[i] >> number[i];

    for(int i = 0; i < 4; ++i){
        for(int j = 1; j <= 13; ++j){
            bool ok = false;
            for(int k = 0; k < n; ++k){
                
                if(suit[k] == suitkind[i] && number[k] == j) ok = true;
            }
            if(ok == false){
                cout << suitkind[i] << ' ' << j << endl;
            }
        }
    }
}
