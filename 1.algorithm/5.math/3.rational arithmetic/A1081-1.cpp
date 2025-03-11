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

typedef long long ll;

ll gcd(ll a, ll b) { // greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    ll num = 0, den = 1; // numerator, denominator
    for (int i = 0; i < n; i++) {
        ll a, b;
        int unused __attribute__((unused)) = 0;
        unused = scanf("%lld/%lld", &a, &b);
        num = num * b + a * den, den *= b;
        int g = gcd(num, den);
        num /= g, den /= g;
    }
    if (num >= den) {
        cout << num / den;
        if (num % den != 0) {
            cout << " " << num % den << "/" << den;
        }
        cout << "\n";
    } else {
        if (num != 0) {
            cout << num << "/" << den << "\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
// @pintia code=end