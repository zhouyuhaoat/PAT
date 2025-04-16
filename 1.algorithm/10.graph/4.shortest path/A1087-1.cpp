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
#include <numeric>
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
unordered_map<string, int> h, c; // happiness, cost
unordered_map<string, vector<string>> pre; // predecessor
unordered_map<string, vector<city>> g;

void dijkstra(string s) {
    c[s] = 0;
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
                        pre[v].clear();
                        pre[v].emplace_back(u);
                        q.emplace(v, c[v]);
                    } else if (c[u] + g[u][i].cost == c[v]) {
                        pre[v].emplace_back(u);
                    }
                }
            }
        }
    }
}

int maxh = -1, p = 0; // path
float avgh = -1;
vector<string> ans, tmp;
void dfs(string s, string v) {
    if (v == s) {
        p++;
        tmp.emplace_back(v);
        int sumh = accumulate(tmp.begin(), tmp.end(), 0, [](int acc, const string& name) -> int {
            return acc + h[name];
        });
        if (maxh < sumh) {
            maxh = sumh;
            avgh = (float)sumh / (tmp.size() - 1);
            ans = tmp;
        } else if (maxh == sumh) {
            float havr = (float)sumh / (tmp.size() - 1);
            if (avgh < havr) {
                avgh = havr;
                ans = tmp;
            }
        }
        tmp.pop_back();
        return;
    }
    tmp.emplace_back(v);
    if (pre.count(v) != 0) {
        for (int i = 0; i < (int)pre[v].size(); i++) {
            dfs(s, pre[v][i]);
        }
    }
    tmp.pop_back();
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
        c[name] = INT_MAX;
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
    dfs(s, Rome);
    cout << p << " " << c[Rome] << " " << maxh << " " << (int)avgh << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
        i > 0 ? cout << "->" : cout << "\n";
    }

    return 0;
}
// @pintia code=end
