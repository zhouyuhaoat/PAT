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
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }
    // 0/1 knapsack problem: choose the largest value of coins to make amount m
    sort(v.begin() + 1, v.end(), greater<int>()); // descending order
    // choose larger coins first for the smallest sequence
    vector<int> dp(m + 1); // dp[j] = max value of amount j
    vector<vector<bool>> c(n + 1, vector<bool>(m + 1));
    // c[i][j] = true if i-th coin is used to make amount j
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            // not complete knapsack: ensure each coin is used once
            if (dp[j] <= dp[j - v[i]] + v[i]) { // choose
                // <=, not <: for the smallest sequence
                dp[j] = dp[j - v[i]] + v[i];
                c[i][j] = true;
            }
        }
    }
    if (dp[m] != m) {
        cout << "No Solution\n";
        return 0;
    }
    vector<int> ans;
    for (int i = n; i >= 1; i--) { // backtrack with ascending order
        if (c[i][m]) {
            ans.emplace_back(i);
            m -= v[i];
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << v[ans[i]];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end