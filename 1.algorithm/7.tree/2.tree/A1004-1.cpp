/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 13:12:14
 *	modified:	2023-03-29 15:00:45
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
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLevel = -1;
unordered_map<int, int> cnt; // level -> leaf nodes
vector<vector<int>> tree;

void dfs(int root, int level) {
    maxLevel = max(maxLevel, level);
    if (tree[root].empty()) { // leaf node
        cnt[level]++;
        return;
    }
    for (int child : tree[root]) {
        dfs(child, level + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    tree.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            tree[id].emplace_back(child);
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= maxLevel; i++) {
        cout << cnt[i];
        i <= maxLevel - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
