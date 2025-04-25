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
    string val;
    int cost;
    city(string val, int cost) : val(val), cost(cost) {
    }
    friend bool operator<(city a, city b) {
        return a.cost > b.cost;
    }
};

vector<string> cities;
unordered_map<string, bool> vis;
unordered_map<string, int> happy, cost; // happy, cost
unordered_map<string, vector<string>> pre; // predecessor
unordered_map<string, vector<city>> g;

void dijkstra(string src) {
    cost[src] = 0;
    priority_queue<city> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        city top = q.top();
        q.pop();
        string u = top.val;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        if (g.count(u) != 0) {
            for (int i = 0; i < (int)g[u].size(); i++) {
                string v = g[u][i].val;
                if (!vis[v]) {
                    if (cost[u] + g[u][i].cost < cost[v]) {
                        cost[v] = cost[u] + g[u][i].cost;
                        pre[v].clear();
                        pre[v].emplace_back(u);
                        q.emplace(v, cost[v]);
                    } else if (cost[u] + g[u][i].cost == cost[v]) {
                        pre[v].emplace_back(u);
                    }
                }
            }
        }
    }
}

int maxHappy = -1, path = 0;
double avgHappy = -1;
vector<string> res, temp;
void dfs(string u, string src) {
    if (u == src) {
        path++;
        temp.emplace_back(u);
        int sum = accumulate(temp.begin(), temp.end(), 0, [](int acc, string name) -> int {
            return acc + happy[name];
        });
        if (sum > maxHappy) {
            maxHappy = sum;
            avgHappy = (double)sum / (temp.size() - 1);
            res = temp;
        } else if (sum == maxHappy) {
            double avg = (double)sum / (temp.size() - 1);
            if (avgHappy < avg) {
                avgHappy = avg;
                res = temp;
            }
        }
        temp.pop_back();
        return;
    }
    temp.emplace_back(u);
    if (pre.count(u) != 0) {
        for (int i = 0; i < (int)pre[u].size(); i++) {
            dfs(pre[u][i], src);
        }
    }
    temp.pop_back();
}

int main(int argc, char const *argv[]) {

    int n, k;
    string src;
    cin >> n >> k >> src;
    happy[src] = 0;
    cities.emplace_back(src);
    for (int i = 1; i < n; i++) {
        string name;
        int happiness;
        cin >> name >> happiness;
        happy[name] = happiness;
        cities.emplace_back(name);
    }
    for (string& name : cities) {
        cost[name] = INT_MAX;
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
    dfs(dst, src);
    cout << path << " " << cost[dst] << " " << maxHappy << " " << (int)avgHappy << "\n";
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
        i > 0 ? cout << "->" : cout << "\n";
    }

    return 0;
}
// @pintia code=end
