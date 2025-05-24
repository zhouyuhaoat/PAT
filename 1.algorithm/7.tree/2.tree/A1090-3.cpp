/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:45:53
 *	modified:	2023-03-29 14:50:10
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
#include <queue>

using namespace std;

int cnt = 0;
double price, rate, maxLayer = -1;
vector<vector<int>> tree;

void bfs(int root, int layer) {
    queue<pair<int, int>> q; // {node, layer}
    q.emplace(root, layer);
    while (!q.empty()) {
        auto [node, layer] = q.front();
        q.pop();
        if (tree[node].empty()) {
            if (layer > maxLayer) {
                maxLayer = layer;
                cnt = 1;
            } else if (layer == maxLayer) {
                cnt++;
            }
        } else {
            for (int child : tree[node]) {
                q.emplace(child, layer + 1);
            }
        }
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
    bfs(root, 0);
    cout << fixed << setprecision(2) << price * pow(rate, maxLayer) << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
