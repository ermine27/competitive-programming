#include <bits/stdc++.h>
using namespace std;

#include "../ModInt.hpp"

// AC Library Modint 使用例より
// https://atcoder.github.io/ac-library/production/document_ja/modint.html

void test() {
    using mint = ModInt<11>;

    mint a = 10;
    mint b(3);

    // equal
    assert(a == 21);
    assert(a == -1);  // QQQ
    // 左辺がint型、long long型の場合は未対応
    // assert(-1 == a);
    assert(mint(-1) == a);

    // negative
    assert(-b == 8);

    // plus
    assert(a + b == 2);  // (10 + 3) mod 11
    // assert(1 + a == 0);
    assert(a + 1 == 0);

    // minus
    assert(a - b == 7);  // (10 - 3) mod 11
    assert(b - a == 4);

    // mul
    assert(a * b == 8);  // (10 * 3) mod 11

    // inv
    assert(b.inv() == 4);  // (3 * 4) mod 11 == 1

    // div
    assert(a / b == 7);  // (10 * 4) mod 11

    // +=, -=, *=, /=
    a += b;
    assert(a == 2 && b == 3);
    a -= b;
    assert(a == 10 && b == 3);
    a *= b;
    assert(a == 8 && b == 3);
    a /= b;
    assert(a == 10 && b == 3);

    // pow
    assert(mint(2).pow(4) == 5);  // 16 mod 11

    // print value
    printf("%lld\n", a.val);  // 10
    cout << a << endl;        // 10

    // get mod
    assert(a.getmod() == 11);

    // 未対応
    // mint(x) と書くとmodを取る操作が発生します((x % mod + mod) % modをmodintに代入します)
    // mint::raw(x) はxをmodを取らずに代入するので高速です(もちろんxが[0,
    // mod)であることを利用者が保証しないといけません) assert(mint::raw(3) == 3);
}

// 追加した機能の検証用
void test2() {
    using mint = ModInt<11>;
    mint a = 10;
    mint b(10), c(3), d(-8), e(4);
    assert(a == b);
    assert(a != c);
    assert(c == d);
    assert(!(c != d));
    assert(~c == e);  // (3*4) mod 11 = 1
}

// 剰余の出力について
void test3() {
    using mint = ModInt<4>;
    // 法が負数の場合の考慮はしていない
    // using mint2 = ModInt<-1>;

    mint a1, a2, a3, a4;
    a1 = 17;   // 1
    a2 = -17;  // 3
    a3 = -a1;  // 3
    a4 = -a2;  // 1
    assert(a1 == 1);
    assert(a2 == 3);
    assert(a3 == 3);
    assert(a4 == 1);

    // 参考：c++ の負数のmodの処理
    int b1, b2, b3, b4;
    b1 = 17 % 4;    // 1
    b2 = -17 % 4;   // -1
    b3 = 17 % -4;   // 1
    b4 = -17 % -4;  // -1
    assert(b1 == 1 && b2 == -1 && b3 == 1 && b4 == -1);
}

// AOJ NTL_1_B
void testModPow() {
    using mint = ModInt<1000000007>;

    assert(mint(31).pow(8) == 891031477);
    assert(mint(39).pow(1000) == 430776345);
    assert(mint(55).pow(1024) == 989051574);
    assert(mint(93).pow(200023) == 415192366);
    assert(mint(1).pow(1) == 1);
    assert(mint(12).pow(11) == 8365487);
    assert(mint(7).pow(15) == 561476714);
    assert(mint(23).pow(13) == 408212877);
    assert(mint(39).pow(5325621) == 717283387);
    assert(mint(97).pow(9999782) == 500346330);
    assert(mint(99).pow(999999991) == 631782380);
    assert(mint(100).pow(1000000000) == 591857147);
    assert(mint(1).pow(999999999) == 1);
    assert(mint(83).pow(999999570) == 642657703);
}

void testInput() {
    using mint = ModInt<4>;
    mint a, b, c;
    cin >> a >> b >> c;
    cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
    test();
    test2();
    test3();
    testModPow();
    testInput();
    return 0;
}
