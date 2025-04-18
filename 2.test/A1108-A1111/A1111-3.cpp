/*
 *	author:		zhouyuhao
 *	created:	2025-04-17 17:14:38
 *	modified:	2025-04-17 17:30:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805358663417856 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1111 Online Map
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805358663417856
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v, dis;
    node(int v, int dis) : v(v), dis(dis) {
    }
    friend bool operator<(node a, node b) {
        return a.dis > b.dis;
    }
};

struct edge { // for multiple edges between two vertices
    int to, length, time;
    edge(int to, int length, int time) : to(to), length(length), time(time) {
    }
};

int src, dst;
vector<bool> vis;
vector<int> d1, d2, pre;
vector<vector<edge>> g;

pair<int, string> dijkstra(string primary) {
    fill(vis.begin(), vis.end(), false);
    fill(d1.begin(), d1.end(), INT_MAX);
    fill(d2.begin(), d2.end(), INT_MAX);
    d1[src] = 0, d2[src] = 0;
    priority_queue<node> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u] || t.dis > d1[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].to;
            int weight = primary == "Distance" ? g[u][i].length : g[u][i].time;
            int secondary = primary == "Distance" ? g[u][i].time : 1;
            if (!vis[v]) {
                if (make_pair(d1[u] + weight, d2[u] + secondary) < make_pair(d1[v], d2[v])) {
                    d1[v] = d1[u] + weight;
                    d2[v] = d2[u] + secondary;
                    pre[v] = u;
                    q.emplace(v, d1[v]);
                }
            }
        }
    }
    vector<int> path;
    for (int i = dst; i != src; i = pre[i]) {
        path.emplace_back(i);
    }
    pair<int, string> ans = {d1[dst], to_string(src)};
    for (int i = path.size() - 1; i >= 0; i--) {
        ans.second += " -> " + to_string(path[i]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n), d1.resize(n), d2.resize(n);
    pre.resize(n), g.resize(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        g[v1].emplace_back(v2, length, time);
        if (way == 0) {
            g[v2].emplace_back(v1, length, time);
        }
    }
    cin >> src >> dst;
    auto ans1 = dijkstra("Distance"), ans2 = dijkstra("Time");
    if (ans1.second != ans2.second) {
        cout << "Distance = " << ans1.first << ": " << ans1.second << "\n";
        cout << "Time = " << ans2.first << ": " + ans2.second << "\n";
    } else {
        cout << "Distance = " << ans1.first << "; Time = " << ans2.first << ": " << ans1.second << "\n";
    }

    return 0;
}
// @pintia code=end
