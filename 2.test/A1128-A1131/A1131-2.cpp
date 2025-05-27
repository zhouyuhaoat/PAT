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

vector<int> dist(ID);
vector<vector<int>> pre(ID), g(ID);
map<pair<int, int>, int> line;

void bfs(int src) { // dijkstra -> equal edge weights -> bfs
    fill(dist.begin(), dist.end(), INT_MAX);
    pre.clear();
    queue<int> q;
    dist[src] = 0, q.emplace(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pre[v] = {u};
                q.emplace(v);
            } else if (dist[u] + 1 == dist[v]) {
                pre[v].emplace_back(u);
            }
        }
    }
}

int transfer(vector<int>& path) {
    int trans = 0;
    for (int i = 1; i < (int)path.size() - 1; i++) {
        if (line[{path[i], path[i - 1]}] != line[{path[i], path[i + 1]}]) {
            trans++;
        }
    }
    return trans;
}

int minTrans = INT_MAX;
vector<int> res, temp;
void dfs(int u, int src) {
    temp.emplace_back(u);
    if (u == src) { // the shortest path
        int trans = transfer(temp);
        if (trans < minTrans) {
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
    cout << path.size() - 1 << "\n";
    int cur = line[{path.back(), path[path.size() - 2]}];
    cout << "Take Line#" << cur << " from ";
    cout << setfill('0') << setw(4) << path.back() << " to ";
    for (int i = path.size() - 2; i > 0; i--) {
        int next = line[{path[i], path[i - 1]}];
        if (next != cur) {
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
            line[{last, id}] = i + 1, line[{id, last}] = i + 1;
            g[last].emplace_back(id), g[id].emplace_back(last);
            last = id;
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int src, dst;
        cin >> src >> dst;
        bfs(src);
        minTrans = INT_MAX;
        res.clear(), temp.clear();
        dfs(dst, src);
        print(res);
    }

    return 0;
}
// @pintia code=end
