/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 21:33:00
 *	modified:	2023-04-11 23:18:19
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805287624491008 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1034 有理数四则运算
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805287624491008
*/

// @pintia code=start
#include <iostream>
#include <numeric>

using namespace std;

using ll = long long;

struct Fraction {
    ll num, denom; // numerator, denominator
};

Fraction reduct(Fraction res) {
    if (res.denom < 0) {
        res.num = -res.num, res.denom = -res.denom;
    }
    if (res.num == 0) {
        res.denom = 1;
    } else {
        ll gcd = std::gcd(abs(res.num), res.denom);
        res.num /= gcd, res.denom /= gcd;
    }
    return res;
}

Fraction add(Fraction f1, Fraction f2) { // addition
    Fraction res = {f1.num * f2.denom + f2.num * f1.denom, f1.denom * f2.denom};
    return reduct(res);
}

Fraction subtract(Fraction f1, Fraction f2) { // subtraction
    Fraction res = {f1.num * f2.denom - f2.num * f1.denom, f1.denom * f2.denom};
    return reduct(res);
}

Fraction multiply(Fraction f1, Fraction f2) { // multiplication
    Fraction res = {f1.num * f2.num, f1.denom * f2.denom};
    return reduct(res);
}

Fraction divide(Fraction f1, Fraction f2) { // division
    Fraction res = {f1.num * f2.denom, f1.denom * f2.num};
    return reduct(res);
}

void print(Fraction res) {
    res = reduct(res);
    if (res.num < 0) {
        cout << "(";
    }
    if (res.denom == 1) { // integer (numerator % denominator = 0), including 0 (numerator = 0)
        cout << res.num;
    } else if (abs(res.num) > res.denom) { // improper fraction
        cout << res.num / res.denom << " " << abs(res.num) % res.denom << "/" << res.denom;
    } else { // proper fraction
        cout << res.num << "/" << res.denom;
    }
    if (res.num < 0) {
        cout << ")";
    }
}

void printInf() {
    cout << "Inf";
}

int main(int argc, char const *argv[]) {

    Fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.num, &a.denom, &b.num, &b.denom);
    print(a), cout << " + ", print(b), cout << " = ", print(add(a, b)), cout << "\n";
    print(a), cout << " - ", print(b), cout << " = ", print(subtract(a, b)), cout << "\n";
    print(a), cout << " * ", print(b), cout << " = ", print(multiply(a, b)), cout << "\n";
    print(a), cout << " / ", print(b), cout << " = ", !b.num ? printInf() : print(divide(a, b)), cout << "\n";

    return 0;
}
// @pintia code=end
