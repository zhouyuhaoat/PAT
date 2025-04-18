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

int src, dst; // source -> destination
vector<bool> vis;
vector<int> d1, d2, pre; // for shortest path
vector<vector<int>> g, l, t; // weight (length & time) between two nodes

void add(int u, int v, int length, int time) {
    g[u].emplace_back(v);
    l[u][v] = length, t[u][v] = time;
}

pair<int, string> dijkstra(vector<vector<int>>& w1, vector<vector<int>>& w2, string primary) {
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
            int v = g[u][i], secondary = primary == "Distance" ? w2[u][v] : 1;
            if (!vis[v]) {
                if (d1[u] + w1[u][v] < d1[v]) {
                    d1[v] = d1[u] + w1[u][v];
                    d2[v] = d2[u] + secondary;
                    pre[v] = u;
                    q.emplace(v, d1[v]);
                } else if (d1[u] + w1[u][v] == d1[v] && d2[u] + secondary < d2[v]) {
                    d2[v] = d2[u] + secondary;
                    pre[v] = u;
                }
            }
        }
    }
    vector<int> path; // reversed path
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
    l.resize(n, vector<int>(n)), t.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        add(v1, v2, length, time);
        if (way == 0) {
            add(v2, v1, length, time);
        }
    }
    cin >> src >> dst;
    auto ans1 = dijkstra(l, t, "Distance"), ans2 = dijkstra(t, l, "Time");
    if (ans1.second != ans2.second) {
        cout << "Distance = " << ans1.first << ": " << ans1.second << "\n";
        cout << "Time = " << ans2.first << ": " + ans2.second << "\n";
    } else {
        cout << "Distance = " << ans1.first << "; Time = " << ans2.first << ": " << ans1.second << "\n";
    }

    return 0;
}
// @pintia code=end
