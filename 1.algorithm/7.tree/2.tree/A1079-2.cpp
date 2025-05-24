/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 11:21:26
 *	modified:	2023-03-29 14:36:57
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805388447170560 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1079 Total Sales of Supply Chain
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805388447170560
*/

// @pintia code=start
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

double price, rate, sale = 0;
vector<double> leaf;
vector<vector<int>> tree;

void bfs(int root, int layer) {
    queue<pair<int, int>> q; // {node, layer}
    q.emplace(root, layer);
    while (!q.empty()) {
        auto [node, layer] = q.front();
        q.pop();
        if (tree[node].empty()) {
            sale += price * pow(rate, layer) * leaf[node];
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
    tree.resize(n), leaf.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k != 0) {
            for (int j = 0; j < k; j++) {
                int id;
                cin >> id;
                tree[i].emplace_back(id);
            }
        } else {
            cin >> leaf[i];
        }
    }
    bfs(0, 0);
    cout << fixed << setprecision(1) << sale << "\n";

    return 0;
}
// @pintia code=end
