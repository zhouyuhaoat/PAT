/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 21:04:19
 *	modified:	2023-04-11 21:05:09
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805386161274880 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1081 Rational Sum
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805386161274880
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

Fraction add(Fraction f1, Fraction f2) {
    ll gcd = std::gcd(f1.denom, f2.denom); // covert fractions to common denominator before addition
    Fraction res = {f1.num * (f2.denom / gcd) + f2.num * (f1.denom / gcd), f1.denom * (f2.denom / gcd)};
    return reduct(res); // reduce fraction after addition
}

void print(Fraction res) {
    res = reduct(res);
    if (res.num == 0) { // zero
        cout << "0\n";
    } else if (abs(res.num) >= res.denom) { // improper fraction
        cout << res.num / res.denom;
        if (res.num % res.denom != 0) {
            cout << " " << abs(res.num) % res.denom << "/" << res.denom;
        }
        cout << "\n";
    } else { // proper fraction
        cout << res.num << "/" << res.denom << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Fraction sum = {0, 1};
    for (int i = 0; i < n; i++) {
        Fraction fra;
        scanf("%lld/%lld", &fra.num, &fra.denom);
        sum = add(sum, reduct(fra)); // reduce fraction before addition
    }
    print(sum);

    return 0;
}
// @pintia code=end
