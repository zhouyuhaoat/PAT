/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 13:10:27
 *	modified:	2023-03-29 14:53:22
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

int cnt = 0; // number of lowest price
double price, rate, lowSale = INT_MAX;
vector<vector<int>> tree;

void dfs(int root, int layer) {
    if (tree[root].empty()) { // leaf node
        double sale = price * pow(rate, layer);
        if (sale < lowSale) {
            lowSale = sale;
            cnt = 1;
        } else if (sale == lowSale) {
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
    cout << fixed << setprecision(4) << lowSale << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
