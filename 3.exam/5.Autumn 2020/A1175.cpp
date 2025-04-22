/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 14:59:32
 *	modified:	2023-04-14 18:54:50
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173571 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1175 Professional Ability Test
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173571
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v, sco, vou; // id, score, vouch
    node(int v, int sco, int vou) : v(v), sco(sco), vou(vou) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for minmax-heap
        if (a.sco != b.sco) {
            return a.sco > b.sco;
        } else {
            return a.vou < b.vou;
        }
    }
};

vector<int> inDeg, inDegTemp; // in degree
vector<int> s, d, pre; // score of shortest path, distance of vouch
vector<bool> vis;
vector<vector<node>> g;

bool topologicalSort(int n) { // check if the graph is a DAG
    queue<int> q;
    q.emplace(n);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (--inDegTemp[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return cnt == n + 1;
}

void dijkstra(int src) {
    priority_queue<node> q;
    q.emplace(src, 0, 0);
    s[src] = 0, d[src] = 0;
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
            if (!vis[v]) {
                if (s[u] + g[u][i].sco < s[v]) { // relaxation
                    s[v] = s[u] + g[u][i].sco;
                    d[v] = d[u] + g[u][i].vou;
                    pre[v] = u;
                    q.emplace(v, s[v], d[v]);
                } else if (s[u] + g[u][i].sco == s[v] && d[u] + g[u][i].vou > d[v]) {
                    d[v] = d[u] + g[u][i].vou;
                    pre[v] = u;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    inDeg.resize(n + 1), g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, sco, vou;
        cin >> u >> v >> sco >> vou;
        inDeg[v]++;
        g[u].emplace_back(v, sco, vou);
    }
    inDegTemp = inDeg; // multiple sources: add a virtual node as the super source
    for (int i = 0; i < n; i++) {
        if (inDegTemp[i] == 0) {
            inDegTemp[i]++;
            g[n].emplace_back(i, 0, 0);
        }
    }
    int k;
    cin >> k;
    bool flag = topologicalSort(n); // DAG: directed acyclic graph
    if (flag) {
        cout << "Okay.\n";
        s.resize(n + 1, INT_MAX), d.resize(n + 1, INT_MIN);
        pre.resize(n + 1), vis.resize(n + 1);
        dijkstra(n);
    } else {
        cout << "Impossible.\n";
    }
    for (int q = 0; q < k; q++) {
        int dst; // destination
        cin >> dst;
        if (inDeg[dst] == 0) { // no prerequisite
            cout << "You may take test " << dst << " directly.\n";
        } else if (flag) { // consistent plan
            vector<int> ans;
            while (dst != n) { // backtrack
                ans.emplace_back(dst);
                dst = pre[dst];
            }
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i];
                i > 0 ? cout << "->" : cout << "\n";
            }
        } else {
            cout << "Error.\n";
        }
    }

    return 0;
}
// @pintia code=end
