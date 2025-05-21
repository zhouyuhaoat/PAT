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

#define MOD 1000000007

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    vector<int> cntP(s.size()); // count of 'P' before 'A'
    int P = 0; // counter
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') {
            cntP[i] = P;
        } else if (s[i] == 'P') {
            P++;
        }
    }
    vector<int> cntT(s.size()); // count of 'T' after 'A'
    int T = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            cntT[i] = T;
        } else if (s[i] == 'T') {
            T++;
        }
    }
    long long res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res += cntP[i] * cntT[i]; // before * after
    }
    cout << res % MOD << "\n";

    return 0;
}
// @pintia code=end
