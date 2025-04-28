/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 20:10:52
 *	modified:	2023-04-05 20:36:00
 *	item:		Programming Ability Test
 *	site:		Shahu
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
#include <queue>

using namespace std;

struct node {
    int val, dist;
    node(int val, int dist) : val(val), dist(dist) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for min-heap
        return a.dist > b.dist;
    }
};

vector<int> dist;
vector<bool> vis;
vector<vector<node>> g;

void dijkstra(int src) { // Dijkstra's algorithm
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    priority_queue<node> q;
    dist[src] = 0, q.emplace(src, 0);
    while (!q.empty()) {
        node top = q.top();
        q.pop();
        int u = top.val;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].val;
            if (!vis[v] && dist[u] + g[u][i].dist < dist[v]) {
                dist[v] = dist[u] + g[u][i].dist;
                q.emplace(v, dist[v]);
            }
        }
    }
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
        vector<int> seq(nv);
        for (int i = 0; i < nv; i++) {
            cin >> seq[i];
        }
        dijkstra(seq[0]);
        bool flag = true;
        // Dijkstra Sequence: the nodes in the path are in non-decreasing order of their distances
        for (int i = 1; i < nv; i++) {
            if (dist[seq[i]] < dist[seq[i - 1]]) {
                flag = false;
                break;
            }
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
