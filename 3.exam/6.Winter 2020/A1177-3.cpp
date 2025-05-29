/*
 *	author:		zhouyuhao
 *	created:	2025-04-22 20:39:06
 *	modified:	2025-04-22 20:42:25
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1729419732192542721 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1177 Subsequence in Substring
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542721
*/

// @pintia code=start
#include <iostream>

using namespace std;

string minWindow(string s, string p) {
    int res = -1, len = 10001;
    for (int lo = 0, hi = 0, id = 0; lo < (int)s.size(); lo++) { // [lo, hi)
        while (hi < (int)s.size() && id < (int)p.size()) {
            if (s[hi] == p[id]) {
                id++;
            }
            hi++;
        }
        if (id == (int)p.size() && hi - lo < len) {
            len = hi - lo;
            res = lo;
        }
        if (s[lo] == p[0]) {
            hi = lo + 1; // next window from lo + 1
            id = 0; // reset id
        }
    }
    return s.substr(res, len);
}

int main(int argc, char const *argv[]) {

    string s, p;
    cin >> s >> p;
    cout << minWindow(s, p) << "\n";

    return 0;
}
// @pintia code=end
