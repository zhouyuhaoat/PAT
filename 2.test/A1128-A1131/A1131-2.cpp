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

const int maxn = 1e4;

vector<int> dist(maxn);
vector<vector<int>> pre(maxn), g(maxn);
map<pair<int, int>, int> line;

void bfs(int src) { // dijkstra -> equal edge weights -> bfs
    fill(dist.begin(), dist.end(), INT_MAX);
    pre.clear();
    queue<int> q;
    dist[src] = 0, q.emplace(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i];
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pre[v].clear();
                pre[v].emplace_back(u);
                q.emplace(v);
            } else if (dist[u] + 1 == dist[v]) {
                pre[v].emplace_back(u);
            }
        }
    }
}

int transfer(vector<int>& path) {
    int cnt = 0;
    for (int i = 1; i < (int)path.size() - 1; i++) {
        if (line[{path[i], path[i - 1]}] != line[{path[i], path[i + 1]}]) {
            cnt++;
        }
    }
    return cnt;
}

int minTrans = INT_MAX, minDist = INT_MAX;
vector<int> res, temp;
void dfs(int u, int src) {
    if (u == src) {
        temp.emplace_back(u);
        int cnt = transfer(temp);
        if ((int)temp.size() < minDist) {
            minDist = temp.size();
            minTrans = cnt;
            res = temp;
        } else if ((int)temp.size() == minDist && cnt < minTrans) {
            minTrans = cnt;
            res = temp;
        }
        temp.pop_back();
        return;
    }
    temp.emplace_back(u);
    for (int i = 0; i < (int)pre[u].size(); i++) {
        dfs(pre[u][i], src);
    }
    temp.pop_back();
}

void print(vector<int>& path) {
    cout << path.size() - 1 << "\n";
    cout << "Take Line#" << line[{path[path.size() - 1], path[path.size() - 2]}] << " from ";
    cout << setfill('0') << setw(4) << path[path.size() - 1] << " to ";
    for (int i = path.size() - 2; i > 0; i--) {
        if (line[{path[i], path[i - 1]}] != line[{path[i], path[i + 1]}]) {
            cout << setfill('0') << setw(4) << path[i] << ".\n";
            cout << "Take Line#" << line[{path[i], path[i - 1]}] << " from ";
            cout << setfill('0') << setw(4) << path[i] << " to ";
        }
    }
    cout << setfill('0') << setw(4) << path[0] << ".\n";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int lastID;
        cin >> lastID;
        for (int j = 1; j < m; j++) {
            int id;
            cin >> id;
            line[{lastID, id}] = i + 1, line[{id, lastID}] = i + 1;
            g[lastID].emplace_back(id), g[id].emplace_back(lastID);
            lastID = id;
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int src, dst;
        cin >> src >> dst;
        bfs(src);
        minTrans = minDist = INT_MAX;
        res.clear(), temp.clear();
        dfs(dst, src);
        print(res);
    }

    return 0;
}
// @pintia code=end
