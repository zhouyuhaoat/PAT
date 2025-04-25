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

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int cntP = 0, cntPA = 0, res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        switch (s[i]) {
            case 'P':
                cntP++; // Count P's
                break;
            case 'A':
                cntPA += cntP; // Count PA's
                break;
            case 'T':
                res += cntPA; // Count PAT's
                res %= 1000000007;
                break;
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
