/*
 *	author:		zhouyuhao
 *	created:	2025-04-25 11:37:11
 *	modified:	2025-04-25 12:25:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805439202443264 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1044 Shopping in Mars
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805439202443264
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        value[i] += value[i - 1]; // prefix sum
    }
    int target = value[n] + 1; // the exact match at least
    vector<pair<int, int>> res; // index pair
    for (int lo = 0, hi = 0; hi <= n; hi++) { // prefix[hi] - prefix[lo] = [lo, hi)
        while (lo < hi && value[hi] - value[lo] >= m) { // potential
            int temp = value[hi] - value[lo];
            if (temp <= target) {
                if (temp < target) { // better
                    target = temp;
                    res.clear();
                }
                res.emplace_back(lo + 1, hi);
            }
            lo++;
        }
    }
    for (auto [lo, hi] : res) {
        cout << lo << "-" << hi << "\n";
    }

    return 0;
}
// @pintia code=end
