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

struct Test {
    int id, score, voucher;
    Test(int id, int score, int voucher) : id(id), score(score), voucher(voucher) {
    }
    friend bool operator<(Test a, Test b) {
        if (a.score != b.score) {
            return a.score > b.score;
        } else {
            return a.voucher < b.voucher;
        }
    }
};

vector<int> degree, temp; // in degree
vector<int> scores, vouchers, pre; // for shortest path
vector<bool> vis;
vector<vector<Test>> g;

bool topologicalSort(int src, int size) { // check whether the graph is a DAG
    queue<int> q;
    q.emplace(src);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto it : g[u]) {
            int v = it.id;
            if (--temp[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return cnt == size;
}

void dijkstra(int src) {
    priority_queue<Test> q;
    q.emplace(src, 0, 0);
    scores[src] = 0, vouchers[src] = 0;
    while (!q.empty()) {
        auto [u, score, _] = q.top();
        q.pop();
        if (vis[u] || score > scores[u]) continue;
        vis[u] = true;
        for (auto [v, score, voucher] : g[u]) {
            if (vis[v]) continue;
            if (scores[u] + score < scores[v]) {
                scores[v] = scores[u] + score;
                vouchers[v] = vouchers[u] + voucher;
                pre[v] = u;
                q.emplace(v, scores[v], vouchers[v]);
            } else if (scores[u] + score == scores[v] && vouchers[u] + voucher > vouchers[v]) {
                vouchers[v] = vouchers[u] + voucher;
                pre[v] = u;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    degree.resize(n + 1), g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, score, voucher;
        cin >> u >> v >> score >> voucher;
        degree[v]++;
        g[u].emplace_back(v, score, voucher);
    }
    temp = degree; // multiple sources: add a virtual node 'n' as the super source
    int src = n;
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            temp[i]++;
            g[n].emplace_back(i, 0, 0);
        }
    }
    int k;
    cin >> k;
    bool DAG = topologicalSort(src, n + 1); // DAG: directed acyclic graph
    if (DAG) {
        cout << "Okay.\n";
        scores.resize(n + 1, INT_MAX), vouchers.resize(n + 1, INT_MIN);
        pre.resize(n + 1), vis.resize(n + 1);
        dijkstra(n);
    } else {
        cout << "Impossible.\n";
    }
    while (k--) {
        int dst; // destination
        cin >> dst;
        if (degree[dst] == 0) { // no prerequisite
            cout << "You may take test " << dst << " directly.\n";
        } else if (DAG) { // consistent plan
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
