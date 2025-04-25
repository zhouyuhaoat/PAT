/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 12:57:40
 *	modified:	2023-03-27 13:14:02
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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    for (int i = 0; i < n - 1; i++) { // exactly two coins: i < n - 1, begin() + i + 1
        int j = lower_bound(coin.begin() + i + 1, coin.end(), m - coin[i]) - coin.begin();
        if (j < n && coin[i] + coin[j] == m) { // first >= m - coin[i] after i
            cout << coin[i] << " " << coin[j] << "\n";
            return 0;
        }
    }
    cout << "No Solution\n";

    return 0;
}
// @pintia code=end
