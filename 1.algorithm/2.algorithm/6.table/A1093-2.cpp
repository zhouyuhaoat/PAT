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
    // inherited from neighbor
    vector<int> cntP(s.size()); // count of 'P' before index i
    for (int i = 1; i < (int)s.size(); i++) {
        cntP[i] = cntP[i - 1] + (s[i - 1] == 'P');
    }
    vector<int> cntT(s.size()); // count of 'T' after index i
    for (int i = (int)s.size() - 2; i >= 0; i--) {
        cntT[i] = cntT[i + 1] + (s[i + 1] == 'T');
    }
    long long res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') { // index i is 'A'
            res += cntP[i] * cntT[i];
        }
    }
    cout << res % MOD << "\n";

    return 0;
}
// @pintia code=end
