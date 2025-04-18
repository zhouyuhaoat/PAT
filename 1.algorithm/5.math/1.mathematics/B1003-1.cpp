/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 21:51:01
 *	modified:	2023-04-10 22:17:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805323154440192 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1003 我要通过！
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805323154440192
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int q = 0; q < n; q++) {
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T') {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
            continue;
        }
        int ip = -1; // position of P
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'P') {
                ip = i;
                break;
            }
        }
        int it = -1; // position of T
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                it = i;
                break;
            }
        }
        for (int i = ip + 1; i < it; i++) {
            if (s[i] == 'P' || s[i] == 'T') { // all A between P and T
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
            continue;
        }
        // xPATx: if middle only one A, left = right
        // aPbTc => aPbATca: if middle add one A, right add one left
        int la = ip, ma = it - ip, ra = s.size() - it - 1;
        if (ma > 1 && la * (ma - 1) == ra) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
// @pintia code=end
