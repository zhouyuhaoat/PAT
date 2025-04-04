/*
 *	author:		zhouyuhao
 *	created:	2025-04-04 11:00:00
 *	modified:	2025-04-04 12:34:56
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805446102073344 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1040 Longest Symmetric String
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805446102073344
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

const long long BASE = 131, MOD = 1000000007;

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    int n = s.size();
    vector<long long> hf(n + 1), hb(n + 1), p(n + 1, 1);
    // forward hash, backward hash, power of BASE
    for (int i = 0; i < n; i++) {
        hf[i + 1] = (hf[i] * BASE + s[i]) % MOD;
        if (i > 0) p[i] = (p[i - 1] * BASE) % MOD;
    }
    for (int i = n - 1; i >= 0; i--) {
        hb[n - i] = (hb[n - i - 1] * BASE + s[i]) % MOD;
    }
    auto getForwardHash = [&](int l, int r) -> long long { // [l, r]
        long long h = hf[r + 1] - (hf[l] * p[r - l + 1]) % MOD; // prefix hash - prefix hash
        if (h < 0) h += MOD;
        return h;
    };
    auto getBackwardHash = [&](int l, int r) -> long long {
        int lo = n - r - 1, hi = n - l - 1; // reverse the range
        long long h = hb[hi + 1] - (hb[lo] * p[hi - lo + 1]) % MOD;
        if (h < 0) h += MOD;
        return h;
    };
    int res = 0;
    for (int len = 1; len <= n; len++) {
        for (int lo = 0; lo + len - 1 < n; lo++) {
            int hi = lo + len - 1;
            if (getForwardHash(lo, hi) == getBackwardHash(lo, hi)) {
                res = len;
                break;
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end