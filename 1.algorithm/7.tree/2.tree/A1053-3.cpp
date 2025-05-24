/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 16:09:30
 *	modified:	2023-03-29 16:47:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805424153280512 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1053 Path of Equal Weight
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805424153280512
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int target;
vector<int> weight, temp;
vector<vector<int>> tree, res;

void dfs(int root, int sum) {
    if (sum > target) return;
    if (sum == target) {
        if (tree[root].empty()) {
            res.emplace_back(temp);
        }
        return;
    }
    for (int child : tree[root]) {
        temp.emplace_back(weight[child]); // update the state before recursion
        dfs(child, sum + weight[child]);
        temp.pop_back(); // restore the state after recursion
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m >> target;
    weight.resize(n), tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            tree[id].emplace_back(child);
        }
    }
    temp.emplace_back(weight[0]); // initialize the state firstly
    dfs(0, weight[0]);
    sort(res.begin(), res.end(), greater<vector<int>>());
    for (auto path : res) {
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i];
            i < (int)path.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
