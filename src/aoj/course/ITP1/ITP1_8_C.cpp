#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    vector<int> a(26);

    while(cin >> c){
        if(isupper(c)) a[c-'A']++;
        if(islower(c)) a[c-'a']++;
    }

    for(int i = 0; i < 26; ++i){
        char c = 'a' + i;
        cout << c << " : " << a[i] << endl;
    }
}

