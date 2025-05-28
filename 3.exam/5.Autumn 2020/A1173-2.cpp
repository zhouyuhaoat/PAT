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
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> data(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        data[i] += data[i - 1];
    }
    data[n + 1] = data[n] + m + 1; // add a virtual node
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            if (data[j] - data[i] > m) { // [i, j)
                cnt += j - i - 1;
                /*
                    consecutive subarrays with sum <= m & beginning with i
                    - beginning with i: [i, j - 1), [i, j - 2), ..., [i, i + 1)
                    - each i contributes (j - i - 1) subarrays
                */
                break;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
