/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 14:01:53
 *	modified:	2023-04-12 14:14:26
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805446102073344 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1040 Longest Symmetric String
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805446102073344
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    getline(cin, s);
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    // dp[i][j] = true means s[i..j] is a symmetric string or palindrome
    int res = 1;
    for (int i = 0; i < (int)s.size(); i++) { // base case
        dp[i][i] = true; // single char
        if (i < (int)s.size() - 1 && s[i] == s[i + 1]) { // two same chars
            dp[i][i + 1] = true, res = 2;
        }
    }
    for (int len = 3; len <= (int)s.size(); len++) {
        for (int lo = 0; lo + len - 1 < (int)s.size(); lo++) {
            int hi = lo + len - 1;
            if (dp[lo + 1][hi - 1] == 1 && s[lo] == s[hi]) {
                // the middle is a palindrome, and two ends are the same
                dp[lo][hi] = true, res = len;
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
