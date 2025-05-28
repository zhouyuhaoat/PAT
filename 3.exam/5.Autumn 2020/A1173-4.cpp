/*
 *	author:		zhouyuhao
 *	created:	2025-04-21 14:26:30
 *	modified:	2025-04-21 14:35:05
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173569 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1173 How Many Ways to Buy a Piece of Land
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173569
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int res = 0; // consecutive subarrays with sum <= m
    for (int lo = 0, hi = 0, sum = 0; lo < n; lo++) { // [lo, hi)
        while (hi < n && sum + data[hi] <= m) { // valid -> invalid
            sum += data[hi++];
        }
        res += hi - lo;
        /*
            consecutive subarrays with sum <= m & beginning with lo
            - beginning with lo: [lo, hi), [lo, hi - 1), ..., [lo, lo + 1)
            - each lo contributes (hi - lo) subarrays
        */
        sum -= data[lo];
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
