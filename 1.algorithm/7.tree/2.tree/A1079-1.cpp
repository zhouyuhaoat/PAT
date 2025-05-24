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
#include <vector>

using namespace std;

double price, rate, sale = 0;
vector<double> leaf;
vector<vector<int>> tree;

void dfs(int root, int layer) {
    if (tree[root].empty()) { // leaf node
        sale += price * pow(rate, layer) * leaf[root];
        return;
    }
    for (int child : tree[root]) {
        dfs(child, layer + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n >> price >> rate;
    rate = rate / 100 + 1; // percentage rate of increase
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
        } else { // leaf node
            cin >> leaf[i];
        }
    }
    dfs(0, 0);
    cout << fixed << setprecision(1) << sale << "\n";

    return 0;
}
// @pintia code=end
