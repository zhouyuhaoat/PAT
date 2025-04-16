/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 15:54:25
 *	modified:	2025-04-16 10:05:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805392092020736 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1076 Forwards on Weibo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805392092020736
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

struct user {
    int id, layer;
};

vector<bool> vis;
vector<vector<int>> g;

int bfs(int s, int l) {
    queue<user> q;
    q.emplace(s, 0);
    vis[s] = true;
    int cnt = 0;
    while (!q.empty()) {
        user t = q.front();
        q.pop();
        for (int i = 0; i < (int)g[t.id].size(); i++) {
            int next = g[t.id][i];
            if (!vis[next] && t.layer < l) {
                vis[next] = true;
                q.emplace(next, t.layer + 1);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {

    int n, l;
    cin >> n >> l;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int follower;
            cin >> follower;
            g[follower].emplace_back(i);
        }
    }
    int k;
    cin >> k;
    vis.resize(n + 1);
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        fill(vis.begin(), vis.end(), false);
        cout << bfs(id, l) << "\n";
    }

    return 0;
}
// @pintia code=end
