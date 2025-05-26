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

struct Node {
    int val, dist;
    Node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Node a, Node b) {
        return a.dist > b.dist;
    }
};

struct edge { // for multiple edges between two vertices
    int to, dist, time;
    edge(int to, int dist, int time) : to(to), dist(dist), time(time) {
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
    priority_queue<Node> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, dis] = q.top();
        q.pop();
        if (vis[u] || dis > d1[u]) continue;
        vis[u] = true;
        for (auto [v, dis, t] : g[u]) {
            int weight = primary == "Distance" ? dis : t; // primary: distance or time
            int secondary = primary == "Distance" ? t : 1; // secondary: time or station
            if (vis[v]) continue;
            if (make_pair(d1[u] + weight, d2[u] + secondary) < make_pair(d1[v], d2[v])) {
                // pair: compare first by distance, then by time
                d1[v] = d1[u] + weight;
                d2[v] = d2[u] + secondary;
                pre[v] = u;
                q.emplace(v, d1[v]);
            }
        }
    }
    vector<int> path;
    for (int i = dst; i != src; i = pre[i]) {
        path.emplace_back(i);
    }
    pair<int, string> res = {d1[dst], to_string(src)};
    for (int i = path.size() - 1; i >= 0; i--) {
        res.second += " -> " + to_string(path[i]);
    }
    return res;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n), d1.resize(n), d2.resize(n), pre.resize(n), g.resize(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        g[v1].emplace_back(v2, length, time);
        if (way == 0) {
            g[v2].emplace_back(v1, length, time);
        }
    }
    cin >> src >> dst;
    auto resDist = dijkstra("Distance"), resTime = dijkstra("Time");
    if (resDist.second != resTime.second) {
        cout << "Distance = " << resDist.first << ": " << resDist.second << "\n";
        cout << "Time = " << resTime.first << ": " + resTime.second << "\n";
    } else {
        cout << "Distance = " << resDist.first << "; Time = " << resTime.first << ": " << resDist.second << "\n";
    }

    return 0;
}
// @pintia code=end
