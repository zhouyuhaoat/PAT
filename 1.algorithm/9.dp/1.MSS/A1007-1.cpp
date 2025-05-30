/*
 *	author:		zhouyuhao
 *	created:	2025-05-12 07:42:10
 *	modified:	2025-05-12 08:08:52
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805514284679168 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1007 Maximum Subsequence Sum
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805514284679168
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    vector<int> data(k);
    /*
        dp[i + 1]: maximum subsequence sum ending at i
        first: the index of the first number in the maximum subsequence
        last: the index of the last number in the maximum subsequence
    */
    vector<int> dp(k + 1);
    int res = -1, first = 0, last = k - 1, id = 0;
    for (int i = 0; i < k; i++) {
        cin >> data[i];
        dp[i + 1] = max(dp[i] + data[i], data[i]);
        if (dp[i + 1] > res) { // update
            res = dp[i + 1];
            first = id, last = i;
        } else if (dp[i + 1] < 0) { // cut
            id = i + 1;
        }
    }
    if (res < 0) res = 0; // all negative
    cout << res << " " << data[first] << " " << data[last] << "\n";

    return 0;
}
// @pintia code=end
