/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 21:33:00
 *	modified:	2023-04-11 23:18:19
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805378443755520 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1088 Rational Arithmetic
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805378443755520
*/

// @pintia code=start
#include <iostream>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { // greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

struct fra { // fraction
    ll num, den; // numerator, denominator
};

fra reduct(fra r) { // reduction
    if (r.den < 0) {
        r.num = -r.num, r.den = -r.den;
    }
    if (r.num == 0) {
        r.den = 1;
    } else {
        int g = gcd(abs(r.num), r.den);
        r.num /= g, r.den /= g;
    }
    return r;
}

fra add(fra f1, fra f2) { // addition
    fra r = {f1.num * f2.den + f2.num * f1.den, f1.den * f2.den};
    return reduct(r);
}

fra subtract(fra f1, fra f2) { // subtraction
    fra r = {f1.num * f2.den - f2.num * f1.den, f1.den * f2.den};
    return reduct(r);
}

fra multiply(fra f1, fra f2) { // multiplication
    fra r = {f1.num * f2.num, f1.den * f2.den};
    return reduct(r);
}

fra divide(fra f1, fra f2) { // division
    fra r = {f1.num * f2.den, f1.den * f2.num};
    return reduct(r);
}

void print(fra r) { // print
    r = reduct(r);
    if (r.num < 0) {
        cout << "(";
    }
    if (r.den == 1) {
        cout << r.num;
    } else if (abs(r.num) > r.den) {
        cout << r.num / r.den << " " << abs(r.num) % r.den << "/" << r.den;
    } else {
        cout << r.num << "/" << r.den;
    }
    if (r.num < 0) {
        cout << ")";
    }
}

void printInf() {
    cout << "Inf";
}

int main(int argc, char const *argv[]) {

    fra a, b;
    scanf("%lld/%lld %lld/%lld", &a.num, &a.den, &b.num, &b.den);
    print(a), cout << " + ", print(b), cout << " = ", print(add(a, b)), cout << "\n";
    print(a), cout << " - ", print(b), cout << " = ", print(subtract(a, b)), cout << "\n";
    print(a), cout << " * ", print(b), cout << " = ", print(multiply(a, b)), cout << "\n";
    print(a), cout << " / ", print(b), cout << " = ", !b.num ? printInf() : print(divide(a, b)), cout << "\n";

    return 0;
}
// @pintia code=end
