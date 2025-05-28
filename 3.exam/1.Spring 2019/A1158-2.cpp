/*
 *	author:		zhouyuhao
 *	created:	2025-04-20 16:15:13
 *	modified:	2025-04-20 16:33:33
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1478635060278108160 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1158 Telefraud Detection
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635060278108160
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> duration;
vector<pair<int, bool>> suspects; // bool to mark if visited

vector<int> bfs(int head) {
    vector<int> gang;
    queue<int> q;
    gang.emplace_back(head);
    q.emplace(head);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& [v, vis] : suspects) {
            if (!vis && duration[u][v] > 0 && duration[v][u] > 0) {
                vis = true;
                gang.emplace_back(v);
                q.emplace(v);
            }
        }
    }
    return gang;
}

int main(int argc, char const *argv[]) {

    int k, n, m;
    cin >> k >> n >> m;
    duration.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        duration[u][v] += t;
    }
    for (int u = 1; u <= n; u++) {
        int call = 0, callBack = 0;
        for (int v = 1; v <= n; v++) {
            if (duration[u][v] > 0 && duration[u][v] <= 5) {
                call++;
                if (duration[v][u] > 0) {
                    callBack++;
                }
            }
        }
        if (call > k && callBack * 5 <= call) {
            suspects.emplace_back(u, false);
        }
    }
    if (suspects.empty()) {
        cout << "None\n";
    } else {
        for (auto& [head, vis] : suspects) {
            if (vis) continue;
            vis = true;
            vector<int> gang = bfs(head);
            sort(gang.begin(), gang.end());
            for (int i = 0; i < (int)gang.size(); i++) {
                cout << gang[i];
                i < (int)gang.size() - 1 ? cout << " " : cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
