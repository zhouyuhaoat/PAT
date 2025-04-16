/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 21:36:42
 *	modified:	2025-04-16 22:19:55
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805379664297984 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1087 All Roads Lead to Rome
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805379664297984
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct city {
    string v;
    int cost;
    city(string v, int cost) : v(v), cost(cost) {
    }
    friend bool operator<(city a, city b) {
        return a.cost > b.cost;
    }
};

vector<string> cities;
unordered_map<string, bool> vis;
unordered_map<string, int> h, c, p, sumh, cntc; // cost, city
unordered_map<string, string> pre;
unordered_map<string, vector<city>> g;

void dijkstra(string s) {
    c[s] = 0, p[s] = 1, sumh[s] = h[s], cntc[s] = 0;
    priority_queue<city> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        city t = q.top();
        q.pop();
        string u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        if (g.count(u) != 0) {
            for (int i = 0; i < (int)g[u].size(); i++) {
                string v = g[u][i].v;
                if (!vis[v]) {
                    if (c[u] + g[u][i].cost < c[v]) {
                        c[v] = c[u] + g[u][i].cost;
                        pre[v] = u;
                        p[v] = p[u];
                        sumh[v] = sumh[u] + h[v];
                        cntc[v] = cntc[u] + 1;
                        q.emplace(v, c[v]);
                    } else if (c[u] + g[u][i].cost == c[v]) {
                        p[v] += p[u];
                        if (sumh[u] + h[v] > sumh[v]) {
                            sumh[v] = sumh[u] + h[v];
                            pre[v] = u;
                            cntc[v] = cntc[u] + 1;
                        } else if (sumh[u] + h[v] == sumh[v]) {
                            if (cntc[v] > 0 && (float)(sumh[u] + h[v]) / (cntc[u] + 1) > (float)sumh[v] / cntc[v]) {
                                pre[v] = u;
                                cntc[v] = cntc[u] + 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

vector<string> ans;
void dfs(string s, string v) {
    if (v == s) {
        ans.emplace_back(v);
        return;
    }
    if (pre.count(v) != 0) {
        dfs(s, pre[v]);
    }
    ans.emplace_back(v);
}

int main(int argc, char const *argv[]) {

    int n, k;
    string s;
    cin >> n >> k >> s;
    h[s] = 0;
    cities.emplace_back(s);
    for (int i = 1; i < n; i++) {
        string name;
        int happiness;
        cin >> name >> happiness;
        h[name] = happiness;
        cities.emplace_back(name);
    }
    for (const string& name : cities) {
        c[name] = INT_MAX, p[name] = 0;
        sumh[name] = 0, cntc[name] = 0;
    }
    for (int i = 0; i < k; i++) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g[c1].emplace_back(c2, cost);
        g[c2].emplace_back(c1, cost);
    }
    dijkstra(s);
    string Rome = "ROM";
    cout << p[Rome] << " " << c[Rome] << " " << sumh[Rome] << " " << (int)sumh[Rome] / cntc[Rome] << "\n";
    dfs(s, Rome);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
    }

    return 0;
}
// @pintia code=end
