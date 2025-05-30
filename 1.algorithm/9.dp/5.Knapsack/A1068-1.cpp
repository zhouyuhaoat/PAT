/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 14:38:00
 *	modified:	2023-04-12 15:25:37
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805402305150976 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1068 Find More Coins
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805402305150976
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    /*
        0/1 knapsack problem: choose the largest value of coins to make amount m
        - dp[j]: max value of amount j
        - choose[i][j] = true if i-th coin is used to make amount j
        - descending order: choose larger coins first for the smallest sequence
    */
    vector<int> dp(m + 1);
    vector<vector<bool>> choose(n + 1, vector<bool>(m + 1));
    sort(value.begin() + 1, value.end(), greater<int>());
    for (int coin = 1; coin <= n; coin++) {
        // not complete knapsack: ensure each coin is used once
        for (int amount = m; amount >= value[coin]; amount--) { // 1-dim dp => reverse order
            if (dp[amount] <= dp[amount - value[coin]] + value[coin]) {
                // <=, not <: for the smallest sequence
                dp[amount] = dp[amount - value[coin]] + value[coin];
                choose[coin][amount] = true;
            }
        }
    }
    if (dp[m] != m) {
        cout << "No Solution\n";
        return 0;
    }
    vector<int> res;
    for (int coin = n; coin >= 1; coin--) { // backtrack with ascending order
        if (choose[coin][m]) {
            res.emplace_back(value[coin]);
            m -= value[coin];
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
