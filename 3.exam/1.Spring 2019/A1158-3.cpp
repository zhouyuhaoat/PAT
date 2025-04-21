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
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> dur(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        dur[a][b] += t;
    }
    vector<pair<int, bool>> sus;
    for (int i = 1; i <= n; i++) {
        int c = 0, cb = 0;
        for (int j = 1; j <= n; j++) {
            if (dur[i][j] > 0 && dur[i][j] <= 5) {
                c++;
                if (dur[j][i] > 0) {
                    cb++;
                }
            }
        }
        if (c > k && cb * 5 <= c) {
            sus.emplace_back(i, false);
        }
    }
    if (sus.empty()) {
        cout << "None\n";
    } else {
        for (auto& s1 : sus) {
            auto& [head, visit] = s1;
            if (visit) continue;
            vector<int> gang;
            queue<int> q;
            gang.emplace_back(head);
            visit = true;
            q.emplace(head);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto& s2 : sus) {
                    auto& [v, vis] = s2;
                    if (!vis && dur[u][v] > 0 && dur[v][u] > 0) {
                        vis = true;
                        gang.emplace_back(v);
                        q.emplace(v);
                    }
                }
            }
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
