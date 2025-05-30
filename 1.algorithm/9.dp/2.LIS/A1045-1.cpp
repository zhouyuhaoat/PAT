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

    int n, m;
    cin >> n >> m;
    vector<int> order(n + 1); // common -> index -> increasing
    for (int i = 1; i <= m; i++) {
        int color;
        cin >> color;
        order[color] = i;
    }
    int l;
    cin >> l;
    vector<int> stripe;
    for (int i = 0; i < l; i++) {
        int color;
        cin >> color;
        if (order[color] > 0) { // keep only favorite colors
            stripe.emplace_back(order[color]);
        }
    }
    int res = -1; // longest increasing subsequence
    vector<int> dp(stripe.size(), 1); // max length of increasing subsequence ending with stripe[i]
    for (int i = 0; i < (int)stripe.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (stripe[j] <= stripe[i]) { // increasing, non-decreasing
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
