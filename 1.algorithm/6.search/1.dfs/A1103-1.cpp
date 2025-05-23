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

int n, k, p; // K-P factorization: sum(x1^p + x2^p + ... + xk^p) = N
int maxFactorSum = -1;
vector<int> factorPower, temp, res;

void init() {
    int base = 0, exp = p; // base = factor = index of factorPower
    while (pow(base, exp) <= n) {
        factorPower.emplace_back(pow(base++, exp));
    }
    temp.resize(k);
}

void dfs(int factor, int factorCnt, int factorSum, int factorPowerSum) {
    if (factorCnt == k) { // base case
        if (factorPowerSum == n && maxFactorSum < factorSum) {
            maxFactorSum = factorSum;
            res = temp;
        }
        return;
    }
    while (factor >= 1) { // positive factor
        if (factorPowerSum + factorPower[factor] <= n) {
            temp[factorCnt] = factor;
            dfs(factor, factorCnt + 1, factorSum + factor, factorPowerSum + factorPower[factor]);
            // factor can be used repeatedly
        }
        factor--;
    }
}

int main(int argc, char const *argv[]) {

    cin >> n >> k >> p;
    init();
    dfs(factorPower.size() - 1, 0, 0, 0);
    if (maxFactorSum != -1) {
        cout << n << " = " << res[0] << "^" << p;
        for (int i = 1; i < (int)res.size(); i++) {
            cout << " + " << res[i] << "^" << p;
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
