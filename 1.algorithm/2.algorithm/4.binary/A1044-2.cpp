/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 11:37:11
 *	modified:	2023-03-27 12:25:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805439202443264 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1044 Shopping in Mars
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805439202443264
*/

// @pintia code=start
#include <algorithm>
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
    int target = value[n] + 1; // the exact match at least
    vector<pair<int, int>> res; // index pair
    for (int i = 0; i < n; i++) {
        int j = lower_bound(value.begin() + i + 1, value.end(), value[i] + m) - value.begin();
        if (j > n) { // out of bound => done
            break;
        }
        int temp = value[j] - value[i];
        if (temp <= target) {
            if (temp < target) { // better
                target = temp;
                res.clear();
            }
            res.emplace_back(i + 1, j);
        }
    }
    for (auto [i, j] : res) {
        cout << i << "-" << j << "\n";
    }

    return 0;
}
// @pintia code=end
