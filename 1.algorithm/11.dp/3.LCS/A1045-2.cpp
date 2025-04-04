/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 13:18:35
 *	modified:	2023-04-12 14:00:36
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
    int m;
    cin >> m;
    vector<int> a(m + 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i + 1];
    }
    int l;
    cin >> l;
    vector<int> b(l + 1);
    for (int i = 0; i < l; i++) {
        cin >> b[i + 1]; // no keep only favorite colors since common
    }
    vector<vector<int>> dp(m + 1, vector<int>(l + 1, 0)); // (m + 1) * (l + 1)
    // dp[i][j]: the longest common subsequence of a[1...i] and b[1...j]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= l; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // inherit from up and left
            if (a[i] == b[j]) { // match
                dp[i][j]++;
            }
        }
    }
    cout << dp[m][l] << "\n";

    return 0;
}
// @pintia code=end