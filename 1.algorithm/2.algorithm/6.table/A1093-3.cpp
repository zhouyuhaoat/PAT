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

#define MOD 1000000007

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int cntT = 0;
    for (char ch : s) {
        if (ch == 'T') {
            cntT++;
        }
    }
    int cntP = 0, res = 0;
    for (char ch : s) { // online
        if (ch == 'P') {
            cntP++; // count of P before index i
        } else if (ch == 'A') {
            res += cntP * cntT;
            res %= MOD;
        } else if (ch == 'T') {
            cntT--; // count of T after index i
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
