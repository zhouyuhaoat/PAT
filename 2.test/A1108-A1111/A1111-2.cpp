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
    int val, dist; // dist can be distance or time
    Node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Node a, Node b) {
        return a.dist > b.dist;
    }
};

int src, dst; // source -> destination
vector<bool> vis;
vector<int> d1, d2, pre; // for shortest path
vector<vector<int>> g, edgeDist, edgeTime;

void add(int u, int v, int length, int time) {
    g[u].emplace_back(v);
    edgeDist[u][v] = length, edgeTime[u][v] = time;
}

pair<int, string> dijkstra(vector<vector<int>>& w1, vector<vector<int>>& w2, string primary) {
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
        for (auto v : g[u]) {
            int secondary = primary == "Distance" ? w2[u][v] : 1; // time or station
            if (vis[v]) continue;
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
    vector<int> path; // reversed path
    for (int i = dst; i != src; i = pre[i]) {
        path.emplace_back(i);
    }
    pair<int, string> res = {d1[dst], to_string(src)}; // {distance or time, path}
    for (int i = path.size() - 1; i >= 0; i--) {
        res.second += " -> " + to_string(path[i]);
    }
    return res;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n), d1.resize(n), d2.resize(n), pre.resize(n), g.resize(n);
    edgeDist.resize(n, vector<int>(n)), edgeTime.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        add(v1, v2, length, time);
        if (way == 0) {
            add(v2, v1, length, time);
        }
    }
    cin >> src >> dst;
    auto resDist = dijkstra(edgeDist, edgeTime, "Distance"); // distance, path
    auto resTime = dijkstra(edgeTime, edgeDist, "Time"); // time, path
    if (resDist.second != resTime.second) {
        cout << "Distance = " << resDist.first << ": " << resDist.second << "\n";
        cout << "Time = " << resTime.first << ": " + resTime.second << "\n";
    } else {
        cout << "Distance = " << resDist.first << "; Time = " << resTime.first << ": " << resDist.second << "\n";
    }

    return 0;
}
// @pintia code=end
