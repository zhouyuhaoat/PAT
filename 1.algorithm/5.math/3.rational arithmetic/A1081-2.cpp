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

using namespace std;

typedef long long ll;

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
        ll g = gcd(abs(r.num), r.den);
        r.num /= g, r.den /= g;
    }
    return r;
}

fra add(fra f1, fra f2) {
    ll g = gcd(f1.den, f2.den); // covert fractions to common denominator before addition
    fra r = {f1.num * (f2.den / g) + f2.num * (f1.den / g), f1.den * (f2.den / g)};
    return reduct(r); // reduce fraction after addition
}

void print(fra r) {
    r = reduct(r);
    if (r.num == 0) { // zero
        cout << "0\n";
    } else if (abs(r.num) >= r.den) { // improper fraction
        cout << r.num / r.den;
        if (r.num % r.den != 0) {
            cout << " " << abs(r.num) % r.den << "/" << r.den;
        }
        cout << "\n";
    } else { // proper fraction
        cout << r.num << "/" << r.den << "\n";
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    fra sum = {0, 1};
    for (int i = 0; i < n; i++) {
        fra tmp;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%lld/%lld", &tmp.num, &tmp.den);
        sum = add(sum, reduct(tmp)); // reduce fraction before addition
    }
    print(sum);

    return 0;
}
// @pintia code=end