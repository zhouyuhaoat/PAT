/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 14:59:06
 *	modified:	2023-04-04 09:06:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805356599820288 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1114 Family Property
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805356599820288
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct fam {
    int id, num;
    double avgEs, avgAr;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, double> es, ar;
    unordered_set<int> ps;
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n; i++) {
        int id, fa, ma;
        cin >> id >> fa >> ma;
        ps.emplace(id);
        if (fa != -1) {
            g[id].emplace_back(fa), g[fa].emplace_back(id);
            ps.emplace(fa);
        }
        if (ma != -1) {
            g[id].emplace_back(ma), g[ma].emplace_back(id);
            ps.emplace(ma);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int chi;
            cin >> chi;
            g[id].emplace_back(chi), g[chi].emplace_back(id);
            ps.emplace(chi);
        }
        double a, b;
        cin >> a >> b;
        es[id] = a, ar[id] = b;
    }
    unordered_map<int, bool> vis;
    vector<fam> ans;
    for (int p : ps) {
        if (vis[p]) continue;
        queue<int> q;
        q.emplace(p);
        vis[p] = true;
        int minID = 10000, famNum = 0;
        double famEs = 0.0, famAr = 0.0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            minID = min(minID, u), famNum++;
            if (es.count(u)) {
                famEs += es[u], famAr += ar[u];
            }
            if (g.count(u) != 0) {
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.emplace(v);
                    }
                }
            }
        }
        ans.emplace_back(fam{minID, famNum, famEs / famNum, famAr / famNum});
    }
    sort(ans.begin(), ans.end(), [](fam a, fam b) -> bool {
        if (a.avgAr != b.avgAr) {
            return a.avgAr > b.avgAr;
        } else {
            return a.id < b.id;
        }
    });
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << setfill('0') << setw(4) << it.id << " " << it.num;
        cout << " " << fixed << setprecision(3) << it.avgEs << " " << it.avgAr << "\n";
    }

    return 0;
}
// @pintia code=end
