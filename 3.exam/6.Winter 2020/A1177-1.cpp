/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 20:39:06
 *	modified:	2023-04-14 20:42:25
 *	item:		Programming Ability Test
 *	site:		Shahu
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
    for (int lo = 0; lo < (int)s.size(); lo++) {
        int id = 0; // match id
        for (int hi = lo; hi < (int)s.size(); hi++) {
            if (s[hi] == p[id]) {
                id++; // subsequence, not substring
                if (id == (int)p.size()) {
                    if (hi - lo + 1 < len) {
                        len = hi - lo + 1;
                        res = lo;
                    }
                    break;
                }
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
