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
    vector<int> path; // sequence of factors
    bool operator>(const Factorization& rhs) const {
        if (factorSum != rhs.factorSum) {
            return factorSum > rhs.factorSum;
        }
        return path > rhs.path;
    }
};

int n, k, p;
vector<int> factorPrime;
vector<vector<Factorization>> dp;
// dp[i][j]: best factorization using i terms for sum j

void init() {
    int base = 0, exp = p;
    while (pow(base, exp) <= n) {
        factorPrime.emplace_back(pow(base, exp));
        base++;
    }
    dp.resize(k + 1, vector<Factorization>(n + 1));
    dp[0][0].factorSum = 0; // base case
}

int main(int argc, char const *argv[]) {

    cin >> n >> k >> p;
    init();
    for (int f = factorPrime.size() - 1; f >= 1; f--) { // factors (items)
        for (int i = 1; i <= k; i++) { // number of terms
            for (int j = factorPrime[f]; j <= n; j++) { // sum
                if (dp[i - 1][j - factorPrime[f]].factorSum != -1) { // reachable state
                    Factorization pre = dp[i - 1][j - factorPrime[f]], cur = pre;
                    cur.factorSum += f, cur.path.emplace_back(f); // candidate
                    if (cur > dp[i][j]) { // operator overload
                        dp[i][j] = cur;
                    }
                }
            }
        }
    }
    Factorization res = dp[k][n];
    if (res.factorSum != -1) {
        cout << n << " = " << res.path[0] << "^" << p;
        for (int i = 1; i < (int)res.path.size(); i++) {
            cout << " + " << res.path[i] << "^" << p;
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end
