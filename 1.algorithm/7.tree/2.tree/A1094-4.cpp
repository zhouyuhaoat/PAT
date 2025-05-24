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
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

pair<int, int> res = {0, 0}; // the largest generation
unordered_map<int, int> cnt;
vector<vector<int>> tree;

void bfs(int root, int level) {
    queue<pair<int, int>> q;
    q.emplace(root, level);
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        cnt[level]++;
        if (cnt[level] > res.first) {
            res = {cnt[level], level};
        }
        for (int child : tree[node]) {
            q.emplace(child, level + 1);
        }
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
    bfs(1, 1);
    cout << res.first << " " << res.second << "\n";

    return 0;
}
// @pintia code=end
