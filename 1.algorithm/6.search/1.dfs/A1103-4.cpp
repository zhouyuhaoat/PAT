/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 16:54:00
 *	modified:	2024-05-04 17:00:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805364711604224 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1103 Integer Factorization
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805364711604224
*/

// @pintia code=start
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Factorization {
    int factorSum = -1;
    vector<int> seq; // sequence of factors
    bool operator>(const Factorization& other) const {
        if (factorSum != other.factorSum) {
            return factorSum > other.factorSum;
        }
        return seq > other.seq;
    }
};

int n, k, p;
vector<int> factorPower;
vector<vector<Factorization>> dp; // dp[i][j]: best factorization using i terms for sum j

void init() {
    int base = 0, exp = p;
    while (pow(base, exp) <= n) {
        factorPower.emplace_back(pow(base++, exp));
    }
    dp.resize(k + 1, vector<Factorization>(n + 1));
    dp[0][0].factorSum = 0; // base case
}

int main(int argc, char const *argv[]) {

    cin >> n >> k >> p;
    init();
    for (int factor = factorPower.size() - 1; factor >= 1; factor--) { // item
        for (int factorCnt = 1; factorCnt <= k; factorCnt++) { // number of item
            for (int factorPowerSum = factorPower[factor]; factorPowerSum <= n; factorPowerSum++) {
                if (dp[factorCnt - 1][factorPowerSum - factorPower[factor]].factorSum != -1) { // reachable state
                    Factorization pre = dp[factorCnt - 1][factorPowerSum - factorPower[factor]], cur = pre;
                    cur.factorSum += factor, cur.seq.emplace_back(factor); // candidate
                    if (cur > dp[factorCnt][factorPowerSum]) { // better by operator overload
                        dp[factorCnt][factorPowerSum] = cur;
                    }
                }
            }
        }
    }
    Factorization res = dp[k][n];
    if (res.factorSum != -1) {
        cout << n << " = " << res.seq[0] << "^" << p;
        for (int i = 1; i < (int)res.seq.size(); i++) {
            cout << " + " << res.seq[i] << "^" << p;
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
