/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 10:58:14
 *	modified:	2023-03-31 19:16:35
 *	item:		Programming Ability Test
 *	site:		Yuting
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

ll convert(string s, ll base) { // convert string to decimal with base radix
    ll sum = 0, weight = 1;
    for (ll i = s.size() - 1; i >= 0; i--) {
        sum += (isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10) * weight;
        weight *= base;
    }
    return sum;
}

ll binary_search(string s, ll target) { // find the radix of string that equals to a given target
    char ch = *max_element(s.begin(), s.end());
    ll lo = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1; // minimum radix: max(s) + 1
    ll hi = max(lo, target); // maximum radix: max(s) or target
    while (lo <= hi) { // boundary of radix: [lo, hi]
        ll mi = (lo + hi) >> 1;
        ll temp = convert(s, mi);
        if (temp > target || temp < 0) { // overflow
            hi = mi - 1;
        } else if (temp < target) {
            lo = mi + 1;
        } else {
            return mi;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {

    string n1, n2;
    ll tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        swap(n1, n2);
    }
    ll target = convert(n1, radix);
    ll res = binary_search(n2, target);
    if (res != -1) {
        cout << res << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
