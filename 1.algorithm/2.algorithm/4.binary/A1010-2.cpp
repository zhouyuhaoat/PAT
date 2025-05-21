/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 18:16:00
 *	modified:	2024-04-28 18:26:00
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
    ll sum = 0, weight = 1;
    for (ll i = s.size() - 1; i >= 0; i--) {
        sum += (isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10) * weight;
        weight *= base;
    }
    return sum;
}

ll lower_bound(string s, ll target) { // find the radix of string that equals and greater than a given target
    char ch = *max_element(s.begin(), s.end());
    ll lo = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
    ll hi = max(lo, target) + 1;
    while (lo < hi) { // boundary of radix: [lo, hi)
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
    ll res = lower_bound(n2, target); // first convert(n2, res) >= target
    if (convert(n2, res) == target) { // check whether equal
        cout << res << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
