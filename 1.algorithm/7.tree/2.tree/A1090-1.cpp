/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 12:29:53
 *	modified:	2023-03-29 14:40:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805376476626944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1090 Highest Price in Supply Chain
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805376476626944
*/

// @pintia code=start
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0; // number of highest price
double price, rate, maxSale = -1;
vector<vector<int>> tree;

void dfs(int root, int layer) {
    if (tree[root].empty()) { // leaf node
        double sale = price * pow(rate, layer);
        if (sale > maxSale) {
            maxSale = sale;
            cnt = 1;
        } else if (sale == maxSale) {
            cnt++;
        }
        return;
    }
    for (int child : tree[root]) {
        dfs(child, layer + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n >> price >> rate;
    rate = rate / 100 + 1;
    tree.resize(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == -1) {
            root = i;
        } else {
            tree[k].emplace_back(i);
        }
    }
    dfs(root, 0);
    cout << fixed << setprecision(2) << maxSale << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
