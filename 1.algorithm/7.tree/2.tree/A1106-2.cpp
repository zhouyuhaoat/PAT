/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:53:34
 *	modified:	2023-03-29 14:57:36
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805362341822464 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1106 Lowest Price in Supply Chain
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805362341822464
*/

// @pintia code=start
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0, minLayer = INT_MAX;
vector<vector<int>> tree;

void dfs(int root, int layer) {
    if (layer > minLayer) return;
    if (tree[root].empty()) { // leaf node
        if (layer < minLayer) { // update the minimum layer, not the lowest price
            minLayer = layer;
            cnt = 1;
        } else if (layer == minLayer) {
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
    double price, rate;
    cin >> n >> price >> rate;
    rate = rate / 100 + 1;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            tree[i].emplace_back(id);
        }
    }
    dfs(0, 0);
    cout << fixed << setprecision(4) << price * pow(rate, minLayer) << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
