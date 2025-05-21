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
        value[i] += value[i - 1]; // prefix sum
    }
    bool found = false;
    while (!found) {
        for (int i = 0; i < n; i++) { // prefix[j] - prefix[i] = [i, j)
            int j = lower_bound(value.begin() + i + 1, value.end(), value[i] + m) - value.begin();
            if (j <= n && value[j] - value[i] == m) { // first >= value[i] + m
                cout << i + 1 << "-" << j << "\n"; // 0-based index -> 1-based index
                found = true;
            }
        }
        m++; // increase the target value if not found the exact match
    }

    return 0;
}
// @pintia code=end
