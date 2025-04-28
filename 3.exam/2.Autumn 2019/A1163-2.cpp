/*
 *	author:		zhouyuhao
 *	created:	2025-04-21 20:10:52
 *	modified:	2025-04-21 20:36:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1478635670373253120 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1163 Dijkstra Sequence
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635670373253120
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val, dist;
    node(int val, int dis) : val(val), dist(dis) {
    }
};

vector<int> dist;
vector<bool> vis;
vector<vector<node>> g;

bool dijkstra(int n, vector<int>& seq) {
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[seq[1]] = 0;
    for (int i = 1; i <= n; i++) { // source -> destination
        int u = seq[i];
        vis[u] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < dist[u]) {
                // not yet visted and has a smaller minimum distance from source
                // if Dijkstra sequence, the current node must be the minimum distance node
                return false;
            }
        }
        for (auto [v, dis] : g[u]) { // explore and relax the edges
            if (!vis[v] && dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int nv, ne;
    cin >> nv >> ne;
    dist.resize(nv + 1), vis.resize(nv + 1), g.resize(nv + 1);
    for (int i = 0; i < ne; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c), g[b].emplace_back(a, c);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        vector<int> seq(nv + 1);
        for (int i = 1; i <= nv; i++) {
            cin >> seq[i];
        }
        dijkstra(nv, seq) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
