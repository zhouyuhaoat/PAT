/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 14:06:06
 *	modified:	2025-04-16 14:36:38
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805456881434624 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1034 Head of a Gang
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805456881434624
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<string, bool> vis;
unordered_map<string, vector<string>> g;
unordered_set<string> ps; // persons
unordered_map<string, int> pw; // person weight
unordered_map<string, unordered_map<string, int>> w; // weight between two persons
vector<vector<string>> comps; // components

void dfs(string u, vector<string>& comp) {
    vis[u] = true;
    comp.emplace_back(u);
    if (g.count(u) != 0) {
        for (const string& v : g[u]) {
            if (!vis[v]) {
                dfs(v, comp);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int t;
        cin >> n1 >> n2 >> t;
        ps.emplace(n1), ps.emplace(n2);
        g[n1].emplace_back(n2), g[n2].emplace_back(n1);
        pw[n1] += t, pw[n2] += t;
        w[n1][n2] += t, w[n2][n1] += t;
    }
    for (const string& p : ps) {
        if (!vis[p]) {
            vector<string> comp; // connected component
            dfs(p, comp);
            comps.emplace_back(comp);
        }
    }
    map<string, int> gang;
    for (auto& comp : comps) {
        if (comp.size() > 2) {
            int total = 0; // each pair of people in the component
            for (size_t i = 0; i < comp.size(); i++) {
                for (size_t j = i + 1; j < comp.size(); j++) {
                    string u = comp[i], v = comp[j];
                    if (w.count(u) != 0 && w[u].count(v) != 0) {
                        total += w[u][v];
                    }
                }
            }
            if (total > k) { // head of gang
                sort(comp.begin(), comp.end(), [](const string& a, const string& b) {
                    if (pw[a] != pw[b]) {
                        return pw[a] > pw[b];
                    } else {
                        return a < b;
                    }
                });
                gang[comp[0]] = comp.size();
            }
        }
    }
    cout << gang.size() << "\n";
    for (auto const& [head, size] : gang) {
        cout << head << " " << size << "\n";
    }

    return 0;
}
// @pintia code=end
