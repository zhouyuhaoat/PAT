/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 22:25:16
 *	modified:	2023-03-30 23:12:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805396953219072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1072 Gas Station
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805396953219072
*/

// @pintia code=start
#include <climits>
#include <cmath>
#include <iomanip>
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
vector<int> dist;
vector<vector<Station>> g;

void dijkstra(int src) {
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
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
                q.emplace(v, dist[v]);
            }
        }
    }
}

int getID(string s, int n) {
    int id = 0;
    if (!isdigit(s[0])) {
        s.erase(0, 1);
        id += n; // gas station
    }
    return id + stoi(s);
}

int main(int argc, char const *argv[]) {

    int n, m, k, range;
    cin >> n >> m >> k >> range;
    vis.resize(n + m + 1), dist.resize(n + m + 1), g.resize(n + m + 1);
    for (int i = 0; i < k; i++) {
        string p1, p2;
        int dist;
        cin >> p1 >> p2 >> dist;
        int id1 = getID(p1, n), id2 = getID(p2, n);
        g[id1].emplace_back(id2, dist);
        g[id2].emplace_back(id1, dist);
    }
    int maxMinDist = -1, candidate = -1;
    double avgDist = -1;
    for (int id = n + 1; id <= n + m; id++) { // traverse all gas stations
        dijkstra(id);
        int minDist = INT_MAX, sumDist = 0;
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            minDist = min(minDist, dist[i]);
            sumDist += dist[i];
            if (dist[i] > range) { // out of range
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        if (minDist > maxMinDist) {
            maxMinDist = minDist;
            avgDist = (double)sumDist / n;
            candidate = id;
        } else if (minDist == maxMinDist && (double)sumDist / n < avgDist) {
            avgDist = (double)sumDist / n;
            candidate = id;
        }
    }
    if (candidate != -1) {
        cout << "G" << candidate - n << "\n";
        cout << fixed << setprecision(1) << (double)maxMinDist << " ";
        cout << fixed << setprecision(1) << round(avgDist * 10) / 10 << "\n";
    } else {
        cout << "No Solution\n";
    }

    return 0;
}
// @pintia code=end
