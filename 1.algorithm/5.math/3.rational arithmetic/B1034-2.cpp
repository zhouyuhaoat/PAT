/*
 *	author:		zhouyuhao
 *	created:	2024-05-02 20:10:46
 *	modified:	2024-05-02 20:16:46
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
  @pintia psid=994805260223102976 pid=994805287624491008 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1034 有理数四则运算
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805287624491008
*/

// @pintia code=start
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { // greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

void print(ll a, ll b) { // print(fraction) -> print(numerator, denominator)
    if (a * b == 0) {
        !b ? cout << "Inf" : cout << "0";
        return;
    }
    if (b < 0) {
        a = -a, b = -b;
    }
    int g = gcd(abs(a), b);
    a /= g, b /= g;
    if (a < 0) {
        cout << "(";
    }
    if (b == 1) {
        cout << a;
    } else if (abs(a) > b) {
        cout << a / b << " " << abs(a) % b << "/" << b;
    } else {
        cout << a << "/" << b;
    }
    if (a < 0) {
        cout << ")";
    }
}

int main(int argc, char const *argv[]) {

    ll a, b, c, d;
    int unused __attribute__((unused)) = 0;
    unused = scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    print(a, b), cout << " + ", print(c, d), cout << " = ", print(a * d + b * c, b * d), cout << "\n";
    print(a, b), cout << " - ", print(c, d), cout << " = ", print(a * d - b * c, b * d), cout << "\n";
    print(a, b), cout << " * ", print(c, d), cout << " = ", print(a * c, b * d), cout << "\n";
    print(a, b), cout << " / ", print(c, d), cout << " = ", print(a * d, b * c), cout << "\n";

    return 0;
}
// @pintia code=end