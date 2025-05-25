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
unordered_map<string, int> happy, cost;
unordered_map<string, vector<string>> pre; // predecessor
unordered_map<string, vector<City>> g;

void dijkstra(string src) {
    cost[src] = 0;
    priority_queue<City> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, c] = q.top();
        q.pop();
        if (vis[u] || c > cost[u]) continue;
        vis[u] = true;
        if (g.count(u) != 0) {
            for (auto [v, c] : g[u]) {
                if (vis[v]) continue;
                if (cost[u] + c < cost[v]) {
                    cost[v] = cost[u] + c;
                    pre[v] = {u};
                    q.emplace(v, cost[v]);
                } else if (cost[u] + c == cost[v]) {
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}

int maxHappy = -1, path = 0;
double avgHappy = -1;
vector<string> res, temp;
void dfs(string u, string src) {
    temp.emplace_back(u);
    if (u == src) {
        path++;
        int sum = accumulate(temp.begin(), temp.end(), 0, [](int acc, string name) {
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
    if (pre.count(u) != 0) {
        for (string v : pre[u]) {
            dfs(v, src);
        }
    }
    temp.pop_back();
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
