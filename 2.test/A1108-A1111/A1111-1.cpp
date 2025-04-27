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

struct nodeDist { // distance first
    int val, dist, time;
    nodeDist(int val, int dist, int time) : val(val), dist(dist), time(time) {
    }
    friend bool operator<(nodeDist a, nodeDist b) {
        return a.dist > b.dist;
    }
};

struct nodeTime { // time first
    int val, dist, time;
    nodeTime(int val, int dist, int time) : val(val), dist(dist), time(time) {
    }
    friend bool operator<(nodeTime a, nodeTime b) {
        return a.time > b.time;
    }
};

vector<bool> vis;
vector<int> dist, times; // shortest distance, time
vector<vector<nodeDist>> gDist;
vector<vector<nodeTime>> gTime;
vector<vector<int>> preDist, preTime; // predecessor
vector<vector<int>> matDist, matTime; // weight matrix (distance & time) between two nodes

void dijkstraDist(int src) { // dijkstra with distance first
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(times.begin(), times.end(), INT_MAX);
    dist[src] = 0;
    priority_queue<nodeDist> q;
    q.emplace(src, 0, 0);
    while (!q.empty()) {
        nodeDist top = q.top();
        q.pop();
        int u = top.val;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)gDist[u].size(); i++) {
            int v = gDist[u][i].val;
            if (!vis[v]) {
                if (dist[u] + gDist[u][i].dist < dist[v]) {
                    dist[v] = dist[u] + gDist[u][i].dist;
                    times[v] = times[u] + gDist[u][i].time;
                    preDist[v].clear();
                    preDist[v].emplace_back(u);
                    q.emplace(v, dist[v], times[v]);
                } else if (dist[u] + gDist[u][i].dist == dist[v]) {
                    preDist[v].emplace_back(u);
                }
            }
        }
    }
}

void dijkstraTime(int src) { // dijkstra with time first
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(times.begin(), times.end(), INT_MAX);
    times[src] = 0;
    priority_queue<nodeTime> q;
    q.emplace(src, 0, 0);
    while (!q.empty()) {
        nodeTime top = q.top();
        q.pop();
        int u = top.val;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)gTime[u].size(); i++) {
            int v = gTime[u][i].val;
            if (!vis[v]) {
                if (times[u] + gTime[u][i].time < times[v]) {
                    times[v] = times[u] + gTime[u][i].time;
                    dist[v] = dist[u] + gTime[u][i].dist;
                    preTime[v].clear();
                    preTime[v].emplace_back(u);
                    q.emplace(v, dist[v], times[v]);
                } else if (times[u] + gTime[u][i].time == times[v]) {
                    preTime[v].emplace_back(u);
                }
            }
        }
    }
}

int minTime = INT_MAX;
vector<int> tempDist, resDist;
void dfsDist(int u, int src) { // dfs to find the shortest path with distance first and time second
    if (u == src) {
        tempDist.emplace_back(u);
        int sum = 0;
        for (int i = tempDist.size() - 1; i > 0; i--) {
            sum += matTime[tempDist[i]][tempDist[i - 1]];
        }
        if (sum < minTime) {
            minTime = sum;
            resDist = tempDist;
        }
        tempDist.pop_back();
        return;
    }
    tempDist.emplace_back(u);
    for (int i = 0; i < (int)preDist[u].size(); i++) {
        dfsDist(preDist[u][i], src);
    }
    tempDist.pop_back();
}

int minStation = INT_MAX;
vector<int> tempTime, resTime;
void dfsTime(int u, int src) { // dfs to find the shortest path with time first and station second
    if (u == src) {
        tempTime.emplace_back(u);
        if ((int)tempTime.size() < minStation) {
            minStation = tempTime.size();
            resTime = tempTime;
        }
        tempTime.pop_back();
        return;
    }
    tempTime.emplace_back(u);
    for (int i = 0; i < (int)preTime[u].size(); i++) {
        dfsTime(preTime[u][i], src);
    }
    tempTime.pop_back();
}

void print(vector<int>& v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
        i > 0 ? cout << " -> " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n), dist.resize(n), times.resize(n);
    gDist.resize(n), gTime.resize(n), preDist.resize(n), preTime.resize(n);
    matDist.resize(n, vector<int>(n)), matTime.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int v1, v2, way, length, time;
        cin >> v1 >> v2 >> way >> length >> time;
        gDist[v1].emplace_back(v2, length, time);
        gTime[v1].emplace_back(v2, length, time);
        matDist[v1][v2] = length, matTime[v1][v2] = time;
        if (way == 0) { // bi-direction
            gDist[v2].emplace_back(v1, length, time);
            gTime[v2].emplace_back(v1, length, time);
            matDist[v2][v1] = length, matTime[v2][v1] = time;
        }
    }
    int src, dst;
    cin >> src >> dst;
    dijkstraDist(src), dfsDist(dst, src);
    int distance = dist[dst]; // store the shortest distance before next dijkstra
    dijkstraTime(src), dfsTime(dst, src);
    if (resDist == resTime) {
        cout << "Distance = " << distance << "; Time = " << times[dst] << ": ";
        print(resDist);
    } else {
        cout << "Distance = " << distance << ": ";
        print(resDist);
        cout << "Time = " << times[dst] << ": ";
        print(resTime);
    }

    return 0;
}
// @pintia code=end
