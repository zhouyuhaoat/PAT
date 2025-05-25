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

struct City {
    string val;
    int cost;
    City(string val, int cost) : val(val), cost(cost) {
    }
    friend bool operator<(City a, City b) {
        return a.cost > b.cost;
    }
};

unordered_map<string, bool> vis;
unordered_map<string, int> happy, cost, path, sumHappy, cntCity;
unordered_map<string, string> pre;
unordered_map<string, vector<City>> g;

void dijkstra(string src) {
    cost[src] = 0, path[src] = 1, sumHappy[src] = happy[src], cntCity[src] = 0;
    priority_queue<City> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, c] = q.top();
        q.pop();
        if (vis[u] || c > cost[u]) continue;
        vis[u] = true;
        for (auto [v, c] : g[u]) {
            if (vis[v]) continue;
            if (cost[u] + c < cost[v]) {
                cost[v] = cost[u] + c;
                pre[v] = u;
                path[v] = path[u];
                sumHappy[v] = sumHappy[u] + happy[v];
                cntCity[v] = cntCity[u] + 1;
                q.emplace(v, cost[v]);
            } else if (cost[u] + c == cost[v]) {
                path[v] += path[u];
                if (sumHappy[u] + happy[v] > sumHappy[v]) {
                    sumHappy[v] = sumHappy[u] + happy[v];
                    pre[v] = u;
                    cntCity[v] = cntCity[u] + 1;
                } else if (sumHappy[u] + happy[v] == sumHappy[v]) {
                    if ((double)(sumHappy[u] + happy[v]) / (cntCity[u] + 1) > (double)sumHappy[v] / cntCity[v]) {
                        pre[v] = u;
                        cntCity[v] = cntCity[u] + 1;
                    }
                }
            }
        }
    }
}

vector<string> res;
void dfs(string u, string src) {
    if (u == src) {
        res.emplace_back(u);
        return;
    }
    if (pre.count(u) != 0) {
        dfs(pre[u], src);
    }
    res.emplace_back(u);
}

int main(int argc, char const *argv[]) {

    int n, k;
    string src;
    cin >> n >> k >> src;
    happy[src] = 0;
    for (int i = 1; i < n; i++) {
        string name;
        int happiness;
        cin >> name >> happiness;
        happy[name] = happiness;
    }
    for (auto [name, _] : happy) {
        cost[name] = INT_MAX, path[name] = 0;
        sumHappy[name] = 0, cntCity[name] = 0;
    }
    for (int i = 0; i < k; i++) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g[c1].emplace_back(c2, cost);
        g[c2].emplace_back(c1, cost);
    }
    dijkstra(src);
    string dst = "ROM";
    cout << path[dst] << " " << cost[dst] << " " << sumHappy[dst] << " " << (int)sumHappy[dst] / cntCity[dst] << "\n";
    dfs(dst, src);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << "->" : cout << "\n";
    }

    return 0;
}
// @pintia code=end
