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
#include <climits>
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
        variant of 0/1 knapsack problem
        - dp[i][j]: max value of amount j with first i coins
        - INT_MIN: impossible or unreachable state
            - exactly: exactly meeting a condition
                - exact target
                - impossible or unreachable state -> sentinel value
            - at most: not exceeding a limit
                - at most capacity
                - naturally reachable
                - choose nothing, select no items
        - priority: prioritize larger coins first for the smallest sequence
    */
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
    sort(value.begin() + 1, value.end(), greater<int>());
    dp[0][0] = 0; // base case
    for (int coin = 1; coin <= n; coin++) {
        for (int amount = 0; amount <= m; amount++) {
            dp[coin][amount] = dp[coin - 1][amount]; // don't take
            if (amount >= value[coin]) { // take if possible
                dp[coin][amount] = max(dp[coin][amount], dp[coin - 1][amount - value[coin]] + value[coin]);
            }
        }
    }
    if (dp[n][m] != m) {
        cout << "No Solution\n";
        return 0;
    }
    vector<int> res;
    for (int coin = n; coin >= 1 && m > 0; coin--) {
        // check if coin is used in the optimal solution
        if (m >= value[coin] && dp[coin][m] == dp[coin - 1][m - value[coin]] + value[coin]) {
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
