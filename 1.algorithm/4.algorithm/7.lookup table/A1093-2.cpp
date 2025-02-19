/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:00:00
 *	modified:	2024-04-28 19:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805373582557184 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1093 Count PAT's
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805373582557184
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int cntT = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'T') {
            ++cntT;
        }
    }
    int cntP = 0, res = 0;
    for (int i = 0; i < (int)s.size(); i++) { // online
        switch (s[i]) {
            case 'P':
                ++cntP;
                break;
            case 'A':
                res += cntP * cntT;
                res %= 1000000007;
                break;
            case 'T':
                --cntT;
                break;
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end