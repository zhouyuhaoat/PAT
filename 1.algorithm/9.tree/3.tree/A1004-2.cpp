/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 15:00:01
 *	modified:	2023-03-29 15:12:48
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805521431773184 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1004 Counting Leaves
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805521431773184
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int maxLevel = 0;
unordered_map<int, int> cnt;
vector<vector<int>> tree;

void bfs(int root) { // dfs -> bfs
    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        maxLevel++;
        for (int i = q.size() - 1; i >= 0; i--) {
            int cur = q.front();
            q.pop();
            if (tree[cur].empty()) {
                cnt[maxLevel]++;
            }
            for (int j = 0; j < (int)tree[cur].size(); j++) {
                q.emplace(tree[cur][j]);
            }
        }
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
    bfs(root);
    for (int i = 1; i <= maxLevel; i++) {
        cout << cnt[i];
        i <= maxLevel - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
