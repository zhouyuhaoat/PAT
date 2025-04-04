/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 09:57:40
 *	modified:	2023-04-12 13:18:13
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805437411475456 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1045 Favorite Color Stripe
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805437411475456
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> ht(n + 1); // hash table
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int v;
        cin >> v;
        ht[v] = i; // common -> index -> increasing
    }
    int l;
    cin >> l;
    vector<int> c;
    for (int i = 0; i < l; i++) {
        int v;
        cin >> v;
        if (ht[v] != 0) { // keep only favorite colors
            c.emplace_back(v);
        }
    }
    int ans = -1; // longest increasing subsequence
    vector<int> dp(c.size()); // max length of increasing subsequence ending with c[i]
    for (int i = 0; i < (int)c.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) { // prefix
            if (ht[c[j]] <= ht[c[i]] && dp[i] < dp[j] + 1) {
                // ht[c[j]] <= ht[c[i]]: increasing, non-decreasing
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

    return 0;
}
// @pintia code=end