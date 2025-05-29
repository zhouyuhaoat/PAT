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
    for (int hi = 0, id = 0; hi < (int)s.size(); hi++) { // forward
        if (s[hi] == p[id]) {
            id++;
            if (id == (int)p.size()) {
                int lo = hi;
                for (int id = (int)p.size() - 1; id >= 0; lo--) { // backward
                    if (s[lo] == p[id]) {
                        id--;
                    }
                }
                if (hi - lo < len) { // (lo, hi]
                    len = hi - lo;
                    res = lo + 1;
                }
                hi = lo + 1; // next window from lo + 2
                id = 0;
            }
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
