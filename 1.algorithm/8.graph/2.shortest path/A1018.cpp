/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 23:09:15
 *	modified:	2023-03-31 11:41:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805489282433024 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1018 Public Bike Management
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805489282433024
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct Station {
    int val, dist;
    Station(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Station a, Station b) {
        return a.dist > b.dist;
    }
};

vector<bool> vis;
vector<int> dist, bike;
vector<vector<Station>> g;
vector<vector<int>> pre;

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<Station> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, dis] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis] : g[u]) {
            if (vis[v]) continue;
            if (dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                pre[v] = {u};
                q.emplace(v, dist[v]);
            } else if (dist[u] + dis == dist[v]) {
                pre[v].emplace_back(u);
            }
        }
    }
}

pair<int, int> traverse(vector<int>& path) {
    int send = 0, back = 0;
    for (int i = path.size() - 2; i >= 0; i--) { // simulate the process step by step
        int netBike = bike[path[i]];
        if (netBike < 0) { // not enough
            if (back >= abs(netBike)) { // enough in hand at the moment
                back += netBike; // take back less
            } else { // not enough in hand at the moment
                send += abs(netBike) - back; // send more in the beginning
                back = 0; // more: just enough, empty in hand at the moment
            }
        } else { // enough: take back
            back += netBike;
        }
    }
    return {send, back};
}

int minSend = INT_MAX, minBack = INT_MAX;
vector<int> res, temp;
void dfs(int u, int src) {
    temp.emplace_back(u);
    if (u == src) {
        auto [send, back] = traverse(temp);
        if (send < minSend) {
            minSend = send;
            minBack = back;
            res = temp;
        } else if (send == minSend && back < minBack) {
            minBack = back;
            res = temp;
        }
        temp.pop_back();
        return;
    }
    for (int v : pre[u]) {
        dfs(v, src);
    }
    temp.pop_back();
}

int main(int argc, char const *argv[]) {

    int cap, n, dst, m;
    cin >> cap >> n >> dst >> m;
    dist.resize(n + 1, INT_MAX), vis.resize(n + 1);
    bike.resize(n + 1), pre.resize(n + 1), g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
        bike[i] -= cap / 2; // perfect: half full
    }
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        g[u].emplace_back(v, dist);
        g[v].emplace_back(u, dist);
    }
    dijkstra(0);
    dfs(dst, 0);
    cout << minSend << " ";
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
        i > 0 ? cout << "->" : cout << " " << minBack << "\n";
    }

    return 0;
}
// @pintia code=end
