/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 14:03:16
 *	modified:	2023-03-22 14:19:45
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    vector<int> cp(s.size());
    int cntP = 0; // counter
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') {
            cp[i] = cntP;
        } else if (s[i] == 'P') {
            cntP++;
        }
    }
    vector<int> ct(s.size());
    int cntT = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            ct[i] = cntT;
        } else if (s[i] == 'T') {
            cntT++;
        }
    }
    long long res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res += cp[i] * ct[i];
    }
    cout << res % 1000000007 << "\n";

    return 0;
}
// @pintia code=end
