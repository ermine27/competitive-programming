/*

参考

C++で数値と文字列の相互変換
https://qiita.com/seal_qiita/items/d62192f8d0b1e4ca8de2

C++ 数値を 2進数 8進数 10進数 16進数 文字列に変換する方法
https://marycore.jp/prog/cpp/convert-number-to-binary-octal-decimal-hex-string/

*/

#include "header.cpp"

void StringTest() {
    char c;
    int intval = 123456789;
    long long llval = 12345678901234;
    double dblval = 34567.89;
    string strint = "123456789";
    string strll = "12345678901234";
    string strdouble = "34567.89";

    // string --> 数値 stoX
    int strtoint = stoi(strint);
    long long strtoll = stoll(strll);
    double strtodbl = stod(strdouble);

    assert(strtoint != intval);
    assert(strtoll != llval);
    assert(strtodbl != dblval);
    cout << strtoint << " type: " << typeid(strtoint).name() << endl;
    cout << strtoll << " type: " << typeid(strtoll).name() << endl;
    cout << strtodbl << " type: " << typeid(strtodbl).name() << endl;
    assert(strtoint == intval);
    assert(strtoll == llval);
    assert(strtodbl == dblval);

    // 数値 --> 文字列
    string inttostr = to_string(intval);
    string lltostr = to_string(llval);
    string dbltostr = to_string(dblval);

    assert(inttostr != strint);
    assert(lltostr != strll);
    assert(dbltostr != strdouble);
    cout << inttostr << " type: " << typeid(inttostr).name() << endl;
    cout << lltostr << " type: " << typeid(lltostr).name() << endl;
    cout << dbltostr << " type: " << typeid(dbltostr).name() << endl;
    assert(inttostr == strint);
    assert(lltostr == strll);
    assert(dbltostr == strdouble);

    // 文字 --> 数値 c - '0'
    intval = 8;
    c = '8';
    int chartoint = c - '0';
    assert(chartoint == intval);
    cout << "char('8') " << c << " type: " << typeid(c).name() << endl;
    cout << "char-->int " << chartoint << " type: " << typeid(chartoint).name() << endl;

    // 数値 --> 文字 int : 'a'
    int val = 9;
    char charval = '9';
    char inttochar = 'a' + val;
    assert(inttochar == charval);
}

// wip
/*
void baseNNumberTest(){

    // 10進数 --> 2進数
    // 2進数 --> 10進数
    // 10進数 --> 16進数
    // 10進数 --> N進数

    // 10進数→8進数変換
    stringstream ss;
    ss << std::oct << i;
    s = ss.str();
}
*/

int main() {
    StringTest();
    // baseNNumberTest();
    return 0;
}
