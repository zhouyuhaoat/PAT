/*
 *	author:		zhouyuhao
 *	created:	2025-04-21 14:26:30
 *	modified:	2025-04-21 14:35:05
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173569 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1173 How Many Ways to Buy a Piece of Land
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173569
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> data(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        data[i] += data[i - 1];
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        // no need to add a virtual node, since upper_bound will return n + 1 if not found
        int j = upper_bound(data.begin() + i, data.end(), data[i] + m) - data.begin();
        cnt += j - i - 1;
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
