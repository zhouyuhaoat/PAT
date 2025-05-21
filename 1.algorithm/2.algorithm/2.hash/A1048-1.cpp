/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 15:21:14
 *	modified:	2023-03-27 15:28:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805432256675840 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1048 Find Coins
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805432256675840
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    unordered_map<int, int> cnt; // coin -> count
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        cnt[coin[i]]++;
    }
    int res = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        if (cnt[m - coin[i]] > 0) {
            if (!(coin[i] == m / 2 && cnt[coin[i]] == 1)) { // ensure that the coin is not used twice
                res = min(res, coin[i]); // find the smallest one
            }
        }
    }
    if (res == 0x7fffffff) {
        cout << "No Solution\n";
    } else {
        cout << res << " " << m - res << "\n";
    }

    return 0;
}
// @pintia code=end
