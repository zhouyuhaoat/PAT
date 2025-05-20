/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 20:31:57
 *	modified:	2023-03-27 10:12:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805390896644096 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1077 Kuchiguse
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805390896644096
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    getchar();
    vector<string> s(n);
    int len = 256;
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        reverse(s[i].begin(), s[i].end());
        len = min(len, (int)s[i].size());
    }
    string res; // the longest common prefix
    for (int i = 0; i < len; i++) {
        bool common = true; // assume the i-th character from the beginning is common
        char ch = s[0][i];
        for (int j = 1; j < n; j++) {
            if (s[j][i] != ch) {
                common = false;
                break;
            }
        }
        if (common) {
            res += ch; // append
        } else {
            break;
        }
    }
    reverse(res.begin(), res.end()); // prefix -> suffix
    !res.empty() ? cout << res << "\n" : cout << "nai\n";

    return 0;
}
// @pintia code=end
