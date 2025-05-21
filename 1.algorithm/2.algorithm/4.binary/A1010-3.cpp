/*
 *	author:		zhouyuhao
 *	created:	2025-05-18 18:16:00
 *	modified:	2025-05-18 18:26:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805507225665536 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1010 Radix
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805507225665536
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

ll convert(string s, ll base) {
    /*
        秦九韶算法, Horner's Rule
            1. value = a * base^2 + b * base^1 + c * base^0
            2. value = ((0 * base + a) * base + b) * base + c
    */
    ll sum = 0;
    for (char ch : s) {
        sum = sum * base + (isdigit(ch) ? ch - '0' : ch - 'a' + 10);
    }
    return sum;
}

ll lower_bound(string s, ll target) {
    char ch = *max_element(s.begin(), s.end());
    ll lo = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
    ll hi = max(lo, target) + 1;
    while (lo < hi) {
        ll mi = (lo + hi) >> 1;
        ll temp = convert(s, mi);
        if (temp >= target || temp < 0) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}

int main(int argc, char const *argv[]) {

    string n1, n2;
    ll tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        swap(n1, n2);
    }
    ll target = convert(n1, radix);
    ll res = lower_bound(n2, target);
    if (convert(n2, res) == target) {
        cout << res << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
