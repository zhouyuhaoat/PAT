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
    int v, s; // id, score
    node(int v, int s) : v(v), s(s) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for min-heap
        return a.s > b.s;
    }
};

vector<int> ind, indtemp; // in degree
vector<int> s, d, pre; // score of shortest path, distance of vouch
vector<bool> vis;
vector<vector<int>> vouch;
vector<vector<node>> g;

bool topologicalsort(int n) { // check if the graph is a DAG
    queue<int> q;
    q.emplace(n);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (--indtemp[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return cnt == n + 1;
}

void dijkstra(int st) {
    s[st] = 0, d[st] = 0;
    priority_queue<node> q;
    q.emplace(st, 0);
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
                if (s[u] + g[u][i].s < s[v]) { // relaxation
                    s[v] = s[u] + g[u][i].s;
                    d[v] = d[u] + vouch[u][v];
                    pre[v] = u;
                    q.emplace(v, s[v]);
                } else if (s[u] + g[u][i].s == s[v] && d[u] + vouch[u][v] > d[v]) {
                    d[v] = d[u] + vouch[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    ind.resize(n + 1), g.resize(n + 1);
    vouch.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v, sco, vou;
        cin >> u >> v >> sco >> vou;
        ind[v]++;
        g[u].emplace_back(v, sco);
        vouch[u][v] = vou;
    }
    indtemp = ind;
    // multiple sources: add a virtual node as the super source
    for (int i = 0; i < n; i++) {
        if (indtemp[i] == 0) {
            indtemp[i]++;
            g[n].emplace_back(i, 0);
        }
    }
    int k;
    cin >> k;
    bool flag = topologicalsort(n); // DAG: directed acyclic graph
    if (flag) {
        cout << "Okay.\n";
        s.resize(n + 1, INT_MAX), d.resize(n + 1, INT_MIN);
        pre.resize(n + 1), vis.resize(n + 1);
        dijkstra(n);
    } else {
        cout << "Impossible.\n";
    }
    for (int q = 0; q < k; q++) {
        int en; // end
        cin >> en;
        if (ind[en] == 0) { // no prerequisite
            cout << "You may take test " << en << " directly.\n";
        } else if (flag) { // consistent plan
            vector<int> ans;
            while (en != n) { // backtrack
                ans.emplace_back(en);
                en = pre[en];
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