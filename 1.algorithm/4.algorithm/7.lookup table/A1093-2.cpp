/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 14:03:16
 *	modified:	2023-03-22 14:19:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805373582557184 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1093 Count PAT's
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805373582557184
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    vector<int> cp(s.size()); // inherited from neighbor
    for (int i = 1; i < (int)s.size(); i++) {
        cp[i] = cp[i - 1] + (s[i - 1] == 'P');
    }
    vector<int> ct(s.size());
    for (int i = (int)s.size() - 2; i >= 0; i--) {
        ct[i] = ct[i + 1] + (s[i + 1] == 'T');
    }
    long long res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') {
            res += cp[i] * ct[i];
        }
    }
    cout << res % 1000000007 << "\n";

    return 0;
}
// @pintia code=end
