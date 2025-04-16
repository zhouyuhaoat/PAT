/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 10:40:09
 *	modified:	2025-04-16 13:00:00
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
unordered_map<string, int> w;
unordered_set<string> ps;

void dfs(string u, int& num, int& total, int& maxw, string& head) {
    // update the information between dfs
    vis[u] = true;
    num++;
    total += w[u];
    if (maxw < w[u]) { // head of gang
        maxw = w[u];
        head = u;
    }
    if (g.count(u) != 0) {
        for (const string& v : g[u]) {
            if (!vis[v]) {
                dfs(v, num, total, maxw, head);
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
        ps.insert(n1), ps.insert(n2);
        g[n1].emplace_back(n2), g[n2].emplace_back(n1);
        w[n1] += t, w[n2] += t;
    }
    map<string, int> gang;
    for (const string& p : ps) {
        if (!vis[p]) {
            int total = 0, maxw = -1, num = 0;
            string head; // the information of connected component
            dfs(p, num, total, maxw, head);
            if (total > 2 * k && num > 2) {
                gang[head] = num;
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
