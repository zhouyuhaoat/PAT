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

struct sta {
    int v, dis;
    sta(int v, int dis) : v(v), dis(dis) {
    }
    friend bool operator<(sta a, sta b) {
        return a.dis > b.dis;
    }
};

vector<bool> vis;
vector<int> d, b; // bike
vector<vector<sta>> g;
vector<vector<int>> pre;

void dijkstra(int s) {
    d[s] = 0;
    priority_queue<sta> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        sta t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (!vis[v]) {
                if (d[u] + g[u][i].dis < d[v]) {
                    d[v] = d[u] + g[u][i].dis;
                    pre[v].clear();
                    pre[v].emplace_back(u);
                    q.emplace(v, d[v]);
                } else if (d[u] + g[u][i].dis == d[v]) {
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}

int minSend = INT_MAX, minBack = INT_MAX;
vector<int> ans, tmp;
void dfs(int s, int v) {
    if (v == s) {
        tmp.emplace_back(v);
        int send = 0, back = 0;
        for (int i = tmp.size() - 2; i >= 0; i--) { // simulate the process step by step
            int net = b[tmp[i]]; // net bike
            if (net < 0) { // not enough
                if (back >= abs(net)) { // enough in hand at the moment
                    back += net; // take back less
                } else { // not enough in hand at the moment
                    send += abs(net) - back; // send more in the beginning
                    back = 0; // more: just enough, empty in hand at the moment
                }
            } else { // enough: take back
                back += net;
            }
        }
        if (minSend > send) {
            minSend = send;
            minBack = back;
            ans = tmp;
        } else if (send == minSend && back < minBack) {
            minBack = back;
            ans = tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.emplace_back(v);
    for (int i = 0; i < (int)pre[v].size(); i++) {
        dfs(s, pre[v][i]);
    }
    tmp.pop_back();
}

int main(int argc, char const *argv[]) {

    int cmax, n, sp, m;
    cin >> cmax >> n >> sp >> m;
    d.resize(n + 1, INT_MAX), vis.resize(n + 1, false);
    b.resize(n + 1), g.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] -= cmax / 2; // perfect: halt full
    }
    for (int i = 0; i < m; i++) {
        int id1, id2, dist;
        cin >> id1 >> id2 >> dist;
        g[id1].emplace_back(id2, dist);
        g[id2].emplace_back(id1, dist);
    }
    dijkstra(0);
    dfs(0, sp);
    cout << minSend << " ";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
        i > 0 ? cout << "->" : cout << " " << minBack << "\n";
    }

    return 0;
}
// @pintia code=end
