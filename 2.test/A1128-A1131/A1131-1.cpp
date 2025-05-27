/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 23:27:37
 *	modified:	2023-04-03 23:50:16
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805347523346432 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1131 Subway Map
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805347523346432
*/

// @pintia code=start
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int ID = 1e4;

struct Station {
    int id, dist; // distance = 1 for each edge
    Station(int id, int dist) : id(id), dist(dist) {
    }
    friend bool operator<(Station a, Station b) {
        return a.dist > b.dist;
    }
};

vector<bool> vis(ID);
vector<int> dist(ID);
vector<vector<int>> pre(ID); // predecessor
vector<vector<Station>> g(ID);
map<pair<int, int>, int> line;

void dijkstra(int src) {
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    pre.clear();
    priority_queue<Station> q;
    dist[src] = 0, q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, dis] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis] : g[u]) {
            if (!vis[v]) {
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
}

int transfer(vector<int>& path) {
    int trans = 0;
    for (int i = 1; i < (int)path.size() - 1; i++) { // traverse the path wholely
        if (line[{path[i], path[i - 1]}] != line[{path[i], path[i + 1]}]) {
            trans++;
        }
    }
    return trans;
}

int minDist = INT_MAX, minTrans = INT_MAX;
vector<int> res, temp;
void dfs(int u, int src) { // backtracking by dfs
    temp.emplace_back(u);
    if (u == src) {
        int trans = transfer(temp); // count of transfer
        if ((int)temp.size() < minDist) { // distance = stations - 1
            minDist = temp.size();
            minTrans = trans;
            res = temp;
        } else if ((int)temp.size() == minDist && trans < minTrans) {
            minTrans = trans;
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

void print(vector<int>& path) {
    cout << path.size() - 1 << "\n"; // the number of stations
    int cur = line[{path.back(), path[path.size() - 2]}];
    cout << "Take Line#" << cur << " from ";
    cout << setfill('0') << setw(4) << path.back() << " to ";
    for (int i = path.size() - 2; i > 0; i--) { // traverse the path wholely
        int next = line[{path[i], path[i - 1]}];
        if (next != cur) { // transfer
            cout << setfill('0') << setw(4) << path[i] << ".\n";
            cout << "Take Line#" << next << " from ";
            cout << setfill('0') << setw(4) << path[i] << " to ";
            cur = next;
        }
    }
    cout << setfill('0') << setw(4) << path[0] << ".\n";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, last;
        cin >> m >> last;
        for (int j = 1; j < m; j++) {
            int id;
            cin >> id;
            line[{last, id}] = i + 1, line[{id, last}] = i + 1; // bi-directional
            g[last].emplace_back(id, 1), g[id].emplace_back(last, 1);
            last = id;
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int src, dst;
        cin >> src >> dst;
        dijkstra(src);
        minDist = minTrans = INT_MAX;
        res.clear(), temp.clear();
        dfs(dst, src);
        print(res);
    }

    return 0;
}
// @pintia code=end
