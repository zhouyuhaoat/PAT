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
        value[i] += value[i - 1];
    }
    int target = value[n] + 1;
    vector<pair<int, int>> res;
    for (int lo = 1, hi = 1; hi <= n; hi++) { // prefix(hi) - prefix(lo - 1) = value[lo - 1, hi - 1]
        while (lo <= hi && value[hi] - value[lo - 1] >= m) {
            int temp = value[hi] - value[lo - 1];
            if (temp >= m) { // a potential match
                if (temp < target) { // a better match
                    target = temp;
                    res.clear();
                    res.emplace_back(lo, hi);
                } else if (temp == target) { // another match
                    res.emplace_back(lo, hi);
                }
            }
            lo++;
        }
    }
    for (auto [i, j] : res) {
        cout << i << "-" << j << "\n";
    }

    return 0;
}
// @pintia code=end
