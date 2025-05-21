/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 13:15:10
 *	modified:	2023-03-27 13:26:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805381845336064 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1085 Perfect Sequence
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805381845336064
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, p;
    cin >> n >> p;
    vector<long long> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    int res = 1;
    for (int lo = 0, hi = 0; lo < n; lo++) { // perfect sequence if max <= min * p
        while (hi < n && seq[hi] <= seq[lo] * p) {
            hi++;
        }
        res = max(res, hi - lo); // [lo, hi)
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
