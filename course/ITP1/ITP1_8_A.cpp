#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    for(int i = 0; i < s.size(); ++i){
        char c = s[i];
        if(islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
        cout << c;
    }
    cout << endl;
}

