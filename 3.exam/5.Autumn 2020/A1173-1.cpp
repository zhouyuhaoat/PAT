/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 14:26:30
 *	modified:	2023-04-14 14:35:05
 *	item:		Programming Ability Test
 *	site:		Shahu
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
    vector<int> data(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        data[i] += data[i - 1]; // prefix sum
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++) { // two loops for all pairs
        for (int j = i + 1; j <= n; j++) {
            if (data[j] - data[i] <= m) { // prefix[j] - prefix[i] = [i, j)
                cnt++;
            } else {
                break;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
