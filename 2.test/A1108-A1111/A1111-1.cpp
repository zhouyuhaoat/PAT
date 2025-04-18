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

struct nodeL { // length, distance first
    int v, l, t;
    nodeL(int v, int l, int t) : v(v), l(l), t(t) {
    }
    friend bool operator<(nodeL a, nodeL b) {
        return a.l > b.l;
    }
};

struct nodeT { // time first
    int v, l, t;
    nodeT(int v, int l, int t) : v(v), l(l), t(t) {
    }
    friend bool operator<(nodeT a, nodeT b) {
        return a.t > b.t;
    }
};

vector<bool> vis;
vector<int> dl, dt; // shortest distance, time
vector<vector<nodeL>> gl;
vector<vector<nodeT>> gt;
vector<vector<int>> prel, pret; // previous
vector<vector<int>> ll, tt; // distance, time between two nodes

void dijkstraL(int s) { // dijkstra with distance first
    dl[s] = 0;
    priority_queue<nodeL> q;
    q.emplace(s, 0, 0);
    while (!q.empty()) {
        nodeL t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)gl[u].size(); i++) {
            int v = gl[u][i].v;
            if (!vis[v]) {
                if (dl[u] + gl[u][i].l < dl[v]) {
                    dl[v] = dl[u] + gl[u][i].l;
                    dt[v] = dt[u] + gl[u][i].t;
                    prel[v].clear();
                    prel[v].emplace_back(u);
                    q.emplace(v, dl[v], dt[v]);
                } else if (dl[u] + gl[u][i].l == dl[v]) {
                    prel[v].emplace_back(u);
                }
            }
        }
    }
}

void dijkstraT(int s) { // dijkstra with time first
    dt[s] = 0;
    priority_queue<nodeT> q;
    q.emplace(s, 0, 0);
    while (!q.empty()) {
        nodeT t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)gt[u].size(); i++) {
            int v = gt[u][i].v;
            if (!vis[v]) {
                if (dt[u] + gt[u][i].t < dt[v]) {
                    dt[v] = dt[u] + gt[u][i].t;
                    dl[v] = dl[u] + gt[u][i].l;
                    pret[v].clear();
                    pret[v].emplace_back(u);
                    q.emplace(v, dl[v], dt[v]);
                } else if (dt[u] + gt[u][i].t == dt[v]) {
                    pret[v].emplace_back(u);
                }
            }
        }
    }
}

int maxT = INT_MAX;
vector<int> tempL, ansL;
void dfsL(int s, int v) { // dfs to find the shortest path with distance first
    if (v == s) {
        tempL.emplace_back(v);
        int sumT = 0;
        for (int i = tempL.size() - 1; i > 0; i--) {
            sumT += tt[tempL[i]][tempL[i - 1]];
        }
        if (sumT < maxT) {
            maxT = sumT;
            ansL = tempL;
        }
        tempL.pop_back();
        return;
    }
    tempL.emplace_back(v);
    for (int i = 0; i < (int)prel[v].size(); i++) {
        dfsL(s, prel[v][i]);
    }
    tempL.pop_back();
}

int maxL = INT_MAX;
vector<int> tempT, ansT;
void dfsT(int s, int v) { // dfs to find the shortest path with time first
    if (v == s) {
        tempT.emplace_back(v);
        if ((int)tempT.size() < maxL) {
            maxL = tempT.size();
            ansT = tempT;
        }
        tempT.pop_back();
        return;
    }
    tempT.emplace_back(v);
    for (int i = 0; i < (int)pret[v].size(); i++) {
        dfsT(s, pret[v][i]);
    }
    tempT.pop_back();
}

void print(vector<int> v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
        i > 0 ? cout << " -> " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vis.resize(n, false), dl.resize(n, INT_MAX), dt.resize(n, INT_MAX);
    gl.resize(n), gt.resize(n), prel.resize(n), pret.resize(n);
    ll.resize(n, vector<int>(n)), tt.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int v1, v2, w, l, t;
        cin >> v1 >> v2 >> w >> l >> t;
        gl[v1].emplace_back(v2, l, t), gt[v1].emplace_back(v2, l, t);
        ll[v1][v2] = l, tt[v1][v2] = t;
        if (w == 0) { // bi-direction
            gl[v2].emplace_back(v1, l, t), gt[v2].emplace_back(v1, l, t);
            ll[v2][v1] = l, tt[v2][v1] = t;
        }
    }
    int s, e;
    cin >> s >> e;
    dijkstraL(s);
    dfsL(s, e);
    int dis = dl[e];
    fill(vis.begin(), vis.end(), false);
    fill(dl.begin(), dl.end(), INT_MAX);
    fill(dt.begin(), dt.end(), INT_MAX);
    dijkstraT(s);
    dfsT(s, e);
    if (ansL == ansT) {
        cout << "Distance = " << dis << "; Time = " << dt[e] << ": ";
        print(ansL);
    } else {
        cout << "Distance = " << dis << ": ";
        print(ansL);
        cout << "Time = " << dt[e] << ": ";
        print(ansT);
    }

    return 0;
}
// @pintia code=end
