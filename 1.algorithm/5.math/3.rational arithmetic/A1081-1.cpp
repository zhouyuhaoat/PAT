/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 20:35:38
 *	modified:	2023-04-11 21:20:11
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

using ll = long long;

ll gcd(ll a, ll b) { // greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    ll num = 0, den = 1; // numerator, denominator
    for (int i = 0; i < n; i++) {
        ll a, b;
        scanf("%lld/%lld", &a, &b);
        ll g1 = gcd(abs(a), b); // reduce fraction before addition
        a /= g1, b /= g1;
        ll g = gcd(den, b); // covert fractions to common denominator before addition
        num = num * (b / g) + a * (den / g), den *= b / g;
        ll g2 = gcd(abs(num), den); // reduce fraction after addition
        num /= g2, den /= g2;
    }
    if (num == 0) { // zero
        cout << "0\n";
    } else if (abs(num) >= den) { // improper fraction
        cout << num / den;
        if (num % den != 0) {
            cout << " " << abs(num) % den << "/" << den;
        }
        cout << "\n";
    } else { // proper fraction
        cout << num << "/" << den << "\n";
    }

    return 0;
}
// @pintia code=end
