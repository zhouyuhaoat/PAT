/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:54:56
 *	modified:	2023-04-02 20:23:52
 *	item:		Programming Ability Test
 *	site:		Yuting
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

struct NodeDist { // distance first
    int val, dist, time;
    NodeDist(int val, int dist, int time) : val(val), dist(dist), time(time) {
    }
    friend bool operator<(NodeDist a, NodeDist b) {
        return a.dist > b.dist;
    }
};

struct NodeTime { // time first
    int val, dist, time;
    NodeTime(int val, int dist, int time) : val(val), dist(dist), time(time) {
    }
    friend bool operator<(NodeTime a, NodeTime b) {
        return a.time > b.time;
    }
};

vector<bool> vis;
vector<int> dist, times; // shortest distance, time
vector<vector<NodeDist>> gDist;
vector<vector<NodeTime>> gTime;
vector<vector<int>> preDist, preTime; // predecessor
vector<vector<int>> edgeDist, edgeTime; // weight matrix (distance & time) between two nodes

void dijkstraDist(int src) { // dijkstra with distance first
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(times.begin(), times.end(), INT_MAX);
    dist[src] = 0;
    priority_queue<NodeDist> q;
    q.emplace(src, 0, 0);
    while (!q.empty()) {
        auto [u, dis, _] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis, t] : gDist[u]) {
            if (vis[v]) continue;
            if (dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                times[v] = times[u] + t;
                preDist[v] = {u};
                q.emplace(v, dist[v], times[v]);
            } else if (dist[u] + dis == dist[v]) {
                preDist[v].emplace_back(u);
            }
        }
    }
}

void dijkstraTime(int src) { // dijkstra with time first
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(times.begin(), times.end(), INT_MAX);
    times[src] = 0;
    priority_queue<NodeTime> q;
    q.emplace(src, 0, 0);
    while (!q.empty()) {
        auto [u, _, t] = q.top();
        q.pop();
        if (vis[u] || t > times[u]) continue;
        vis[u] = true;
        for (auto [v, dis, t] : gTime[u]) {
            if (vis[v]) continue;
            if (times[u] + t < times[v]) {
                times[v] = times[u] + t;
                dist[v] = dist[u] + dis;
                preTime[v] = {u};
                q.emplace(v, dist[v], times[v]);
            } else if (times[u] + t == times[v]) {
                preTime[v].emplace_back(u);
            }
        }
    }
}

int minTime = INT_MAX;
vector<int> tempDist, resDist;
void dfsDist(int u, int src, int sum) { // dfs to find the shortest path with distance first and time second
    tempDist.emplace_back(u);
    if (u == src) {
        if (sum < minTime) {
            minTime = sum;
            resDist = tempDist;
        }
        tempDist.pop_back();
        return;
    }
    for (auto v : preDist[u]) {
        dfsDist(v, src, sum + edgeTime[v][u]); // update the information during dfs
    }
    tempDist.pop_back();
}

int minStation = INT_MAX;
vector<int> tempTime, resTime;
void dfsTime(int u, int src) { // dfs to find the shortest path with time first and station second
    tempTime.emplace_back(u);
    if (u == src) {
        if ((int)tempTime.size() < minStation) {
            minStation = tempTime.size();
            resTime = tempTime;
        }
        tempTime.pop_back();
        return;
    }
    for (auto v : preTime[u]) {
        dfsTime(v, src);
    }
    tempTime.pop_back();
}

void print(vector<int>& vec) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
        i > 0 ? cout << " -> " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n), dist.resize(n), times.resize(n);
    gDist.resize(n), gTime.resize(n), preDist.resize(n), preTime.resize(n);
    edgeDist.resize(n, vector<int>(n)), edgeTime.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        gDist[v1].emplace_back(v2, length, time);
        gTime[v1].emplace_back(v2, length, time);
        edgeDist[v1][v2] = length, edgeTime[v1][v2] = time;
        if (way == 0) { // bi-direction
            gDist[v2].emplace_back(v1, length, time);
            gTime[v2].emplace_back(v1, length, time);
            edgeDist[v2][v1] = length, edgeTime[v2][v1] = time;
        }
    }
    int src, dst;
    cin >> src >> dst;
    dijkstraDist(src), dfsDist(dst, src, 0);
    int dis = dist[dst]; // store the shortest distance before next dijkstra
    dijkstraTime(src), dfsTime(dst, src);
    if (resDist == resTime) {
        cout << "Distance = " << dis << "; Time = " << times[dst] << ": ";
        print(resDist);
    } else {
        cout << "Distance = " << dis << ": ";
        print(resDist);
        cout << "Time = " << times[dst] << ": ";
        print(resTime);
    }

    return 0;
}
// @pintia code=end
