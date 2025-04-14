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
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> d[i + 1];
        d[i + 1] += d[i];
    }
    int minsum = d[n];
    vector<pair<int, int>> ans;
    for (int i = 0; i <= n; i++) {
        int j = lower_bound(d.begin() + i, d.end(), m + d[i]) - d.begin();
        if (j > n) break; // minimum lost
        if (d[j] - d[i] > minsum) continue;
        if (d[j] - d[i] >= m) {
            if (minsum > d[j] - d[i]) {
                minsum = d[j] - d[i];
                ans.clear();
            }
            ans.emplace_back(i + 1, j);
        }
    }
    for (auto& it : ans) {
        cout << it.first << "-" << it.second << "\n";
    }

    return 0;
}
// @pintia code=end
