/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 12:45:43
 *	modified:	2023-03-29 14:49:47
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805372601090048 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1094 The Largest Generation
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805372601090048
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> cnt; // level -> number of people
vector<vector<int>> tree;

void dfs(int root, int level) {
    cnt[level]++;
    for (int i = 0; i < (int)tree[root].size(); i++) {
        dfs(tree[root][i], level + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    tree.resize(n + 1);
    vector<bool> isRoot(n + 1, true);
    for (int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            tree[id].emplace_back(child);
            isRoot[child] = false;
        }
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin() + 1;
    dfs(root, 0);
    vector<pair<int, int>> res(cnt.begin(), cnt.end());
    sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });
    cout << res[0].second << " " << res[0].first + 1 << "\n";

    return 0;
}
// @pintia code=end
