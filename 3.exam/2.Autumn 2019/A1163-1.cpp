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
    int v, dis; // vertex id, distance
    node(int v, int dis) : v(v), dis(dis) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for min-heap
        return a.dis > b.dis;
    }
};

vector<int> d;
vector<bool> vis;
vector<vector<node>> g;

void dijkstra(int s) { // Dijkstra's algorithm
    fill(d.begin(), d.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    priority_queue<node> q;
    d[s] = 0, q.emplace(s, 0);
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (!vis[v] && d[u] + g[u][i].dis < d[v]) { // relaxation
                d[v] = d[u] + g[u][i].dis;
                q.emplace(v, d[v]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int nv, ne;
    cin >> nv >> ne;
    d.resize(nv + 1), vis.resize(nv + 1), g.resize(nv + 1);
    for (int i = 0; i < ne; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c), g[b].emplace_back(a, c);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        vector<int> p(nv);
        for (int i = 0; i < nv; i++) {
            cin >> p[i];
        }
        dijkstra(p[0]);
        bool flag = true;
        // Dijkstra Sequence: the nodes in the path are in non-decreasing order of their distances
        for (int i = 1; i < nv; i++) {
            if (d[p[i]] < d[p[i - 1]]) {
                flag = false;
                break;
            }
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
