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
    temp.emplace_back(weight[root]);
    sum += weight[root];
    if (tree[root].empty() && sum == target) {
        res.emplace_back(temp);
    }
    for (int child : tree[root]) {
        dfs(child, sum);
    }
    temp.pop_back();
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
    dfs(0, 0);
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
