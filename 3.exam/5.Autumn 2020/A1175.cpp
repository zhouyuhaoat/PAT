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
    int val, score, vouch;
    node(int val, int score, int vouch) : val(val), score(score), vouch(vouch) { // constructor
    }
    friend bool operator<(node a, node b) { // overload < operator for minmax-heap
        if (a.score != b.score) {
            return a.score > b.score;
        } else {
            return a.vouch < b.vouch;
        }
    }
};

vector<int> degree, temp; // all in degree
vector<int> score, dist, pre; // for shortest path
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
            int v = g[u][i].val;
            if (--temp[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return cnt == n + 1;
}

void dijkstra(int src) {
    priority_queue<node> q;
    q.emplace(src, 0, 0);
    score[src] = 0, dist[src] = 0;
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
            if (!vis[v]) {
                if (score[u] + g[u][i].score < score[v]) {
                    score[v] = score[u] + g[u][i].score;
                    dist[v] = dist[u] + g[u][i].vouch;
                    pre[v] = u;
                    q.emplace(v, score[v], dist[v]);
                } else if (score[u] + g[u][i].score == score[v] && dist[u] + g[u][i].vouch > dist[v]) {
                    dist[v] = dist[u] + g[u][i].vouch;
                    pre[v] = u;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    degree.resize(n + 1), g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, score, vouch;
        cin >> u >> v >> score >> vouch;
        degree[v]++;
        g[u].emplace_back(v, score, vouch);
    }
    temp = degree; // multiple sources: add a virtual node as the super source
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            temp[i]++;
            g[n].emplace_back(i, 0, 0);
        }
    }
    int k;
    cin >> k;
    bool flag = topologicalSort(n); // DAG: directed acyclic graph
    if (flag) {
        cout << "Okay.\n";
        score.resize(n + 1, INT_MAX), dist.resize(n + 1, INT_MIN);
        pre.resize(n + 1), vis.resize(n + 1);
        dijkstra(n);
    } else {
        cout << "Impossible.\n";
    }
    for (int q = 0; q < k; q++) {
        int dst; // destination
        cin >> dst;
        if (degree[dst] == 0) { // no prerequisite
            cout << "You may take test " << dst << " directly.\n";
        } else if (flag) { // consistent plan
            vector<int> res;
            while (dst != n) { // backtrack
                res.emplace_back(dst);
                dst = pre[dst];
            }
            for (int i = res.size() - 1; i >= 0; i--) {
                cout << res[i];
                i > 0 ? cout << "->" : cout << "\n";
            }
        } else {
            cout << "Error.\n";
        }
    }

    return 0;
}
// @pintia code=end
