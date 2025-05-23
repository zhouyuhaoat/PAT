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

int n, k, p;
int maxFactorSum = -1;
vector<int> factorPower;
int temp[401], res[401]; // vector -> array
int cnt = 0; // track the size of array

void init() {
    int base = 0, exp = p;
    while (pow(base, exp) <= n) {
        factorPower.emplace_back(pow(base++, exp));
    }
}

void dfs(int factor, int factorCnt, int factorSum, int factorPowerSum) {
    if (factorCnt == k && factorPowerSum == n) {
        if (maxFactorSum < factorSum) {
            maxFactorSum = factorSum;
            cnt = factorCnt;
            for (int i = 0; i < factorCnt; i++) {
                res[i] = temp[i];
            }
        }
        return;
    }
    if (factor <= 0 || factorCnt > k || factorPowerSum > n) {
        return;
    }
    if (factorPowerSum + (k - factorCnt) * factorPower[factor] < n) {
        return;
    }
    temp[factorCnt] = factor; // indexing
    dfs(factor, factorCnt + 1, factorSum + factor, factorPowerSum + factorPower[factor]);
    dfs(factor - 1, factorCnt, factorSum, factorPowerSum);
}

int main(int argc, char const *argv[]) {

    cin >> n >> k >> p;
    init();
    dfs(factorPower.size() - 1, 0, 0, 0);
    if (maxFactorSum != -1) {
        cout << n << " = " << res[0] << "^" << p;
        for (int i = 1; i < cnt; i++) {
            cout << " + " << res[i] << "^" << p;
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
