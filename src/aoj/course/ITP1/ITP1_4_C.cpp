#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    char op;
    while(true){
        cin >> a >> op >> b;
        if(op == '?'){
            return 0;
        }

        if(op == '+'){
            cout << a + b << endl;
        }
        if(op == '-'){
            cout << a - b << endl;
        }
        if(op == '*'){
            cout << a * b << endl;
        }
        if(op == '/'){
            cout << a / b << endl;
        }

    }
}
