/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 07:42:10
 *	modified:	2023-04-12 08:08:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805514284679168 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1007 Maximum Subsequence Sum
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805514284679168
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    vector<int> d(k);
    bool flag = true;
    for (int i = 0; i < k; i++) {
        cin >> d[i];
        if (d[i] >= 0) {
            flag = false;
        }
    }
    if (flag) { // all negative
        cout << "0 " << d[0] << " " << d[k - 1] << "\n";
        return 0;
    }
    vector<int> dp(k), s(k);
    // dp: maximum subsequence sum ending at i
    // s: start index of the subsequence
    dp[0] = d[0], s[0] = 0;
    for (int i = 1; i < k; i++) {
        if (d[i] <= dp[i - 1] + d[i]) { // extend
            // <=, not <: not unique, for the smallest indices
            dp[i] = dp[i - 1] + d[i], s[i] = s[i - 1];
        } else { // cut
            dp[i] = d[i], s[i] = i;
        }
    }
    int id = max_element(dp.begin(), dp.end()) - dp.begin();
    // id: for the first and the last numbers of the maximum subsequence
    cout << dp[id] << " " << d[s[id]] << " " << d[id] << "\n";

    return 0;
}
// @pintia code=end