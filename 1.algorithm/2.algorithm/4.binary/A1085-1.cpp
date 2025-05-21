/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 10:46:47
 *	modified:	2023-03-27 10:53:12
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
    for (int i = 0; i < n; i++) { // perfect sequence if max <= min * p
        int j = upper_bound(seq.begin() + i, seq.end(), seq[i] * p) - seq.begin(); // first > min * p
        res = max(res, j - i); // [i, j)
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
