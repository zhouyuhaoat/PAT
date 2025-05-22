/*
 *	author:		zhouyuhao
 *	created:	2024-04-29 10:01:00
 *	modified:	2024-04-29 10:10:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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
    while (n--) {
        string s;
        cin >> s;
        bool flag = true;
        int P = -1, T = -1; // position of P and T
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'P' && P == -1) { // only one P
                P = i;
            } else if (s[i] == 'T' && T == -1) { // only one T
                T = i;
            } else if (s[i] != 'A') { // only P, A, T
                flag = false;
                break;
            }
        }
        if (flag && P != -1 && T != -1 && P < T - 1) {
            // xPATx: if middle only one A, left = right
            // aPbTc => aPbATca: if middle add one A, right add one left
            int left = P, middle = T - P, right = s.size() - 1 - T;
            if (middle > 1 && left * (middle - 1) == right) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
