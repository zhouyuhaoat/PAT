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
    vector<long long> hashForward(n + 1), power(n + 1, 1);
    for (int i = 0; i < n; i++) { // prefix hash
        hashForward[i + 1] = (hashForward[i] * BASE + s[i]) % MOD;
        if (i > 0) power[i] = (power[i - 1] * BASE) % MOD;
    }
    vector<long long> hashBackward(n + 1);
    for (int i = n - 1; i >= 0; i--) { // suffix hash
        hashBackward[n - i] = (hashBackward[n - 1 - i] * BASE + s[i]) % MOD;
    }
    auto getForwardHash = [&](int left, int right) { // [left, right]
        int lo = left, hi = right;
        long long hash = (hashForward[hi + 1] - (hashForward[lo] * power[hi - lo + 1])) % MOD;
        // BASE^(hi - lo + 1): adjust for the positional weight difference
        if (hash < 0) hash += MOD;
        return hash;
    };
    auto getBackwardHash = [&](int left, int right) {
        int lo = n - 1 - right, hi = n - 1 - left; // reverse the range
        long long hash = (hashBackward[hi + 1] - (hashBackward[lo] * power[hi - lo + 1])) % MOD;
        if (hash < 0) hash += MOD;
        return hash;
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
