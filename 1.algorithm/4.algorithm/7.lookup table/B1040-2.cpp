/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:00:00
 *	modified:	2024-04-28 19:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805282389999616 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1040 有几个PAT
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805282389999616
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
