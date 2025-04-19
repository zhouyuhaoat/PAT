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

struct sta {
    int id, dis; // distance = 1 for each edge
    sta(int id, int dis) : id(id), dis(dis) { // constructor
    }
    friend bool operator<(sta a, sta b) { // overload operator< for priority_queue
        return a.dis > b.dis;
    }
};

vector<bool> vis(maxn);
vector<int> d(maxn);
vector<vector<int>> pre(maxn);
vector<vector<sta>> g(maxn);
map<pair<int, int>, int> line;

void dijkstra(int st) {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INT_MAX);
    pre.clear();
    priority_queue<sta> q;
    d[st] = 0, q.emplace(st, 0);
    while (!q.empty()) {
        sta t = q.top();
        q.pop();
        int u = t.id;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].id;
            if (!vis[v]) {
                if (d[u] + g[u][i].dis < d[v]) { // relax
                    d[v] = d[u] + g[u][i].dis;
                    pre[v].clear();
                    pre[v].emplace_back(u);
                    q.emplace(v, d[v]);
                } else if (d[u] + g[u][i].dis == d[v]) { // multiple shortest paths
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}

int transfer(vector<int>& path) {
    int cnt = 0;
    for (int i = 1; i < (int)path.size() - 1; i++) { // traverse the path wholely
        if (line[{path[i - 1], path[i]}] != line[{path[i], path[i + 1]}]) {
            cnt++;
        }
    }
    return cnt;
}

int minDis = INT_MAX, minTrans = INT_MAX;
vector<int> ans, temp;
void dfs(int s, int v) { // backtracking by dfs
    if (v == s) {
        temp.emplace_back(v);
        int cnt = transfer(temp); // count of transfer
        if ((int)temp.size() < minDis) {
            minDis = temp.size();
            minTrans = cnt;
            ans = temp;
        } else if ((int)temp.size() == minDis && cnt < minTrans) {
            minTrans = cnt;
            ans = temp;
        }
        temp.pop_back();
        return;
    }
    temp.emplace_back(v);
    for (int i = 0; i < (int)pre[v].size(); i++) {
        dfs(s, pre[v][i]);
    }
    temp.pop_back();
}

void print(vector<int>& path) {
    cout << path.size() - 1 << "\n"; // the number of stations
    cout << "Take Line#" << line[{path[path.size() - 1], path[path.size() - 2]}] << " from ";
    cout << setfill('0') << setw(4) << path[path.size() - 1] << " to ";
    for (int i = path.size() - 2; i > 0; i--) { // traverse the path wholely
        if (line[{path[i], path[i - 1]}] != line[{path[i + 1], path[i]}]) { // transfer
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
        int lastID; // previous station id
        cin >> lastID;
        for (int j = 1; j < m; j++) {
            int id;
            cin >> id;
            line[{lastID, id}] = i + 1, line[{id, lastID}] = i + 1; // bidirectional
            g[lastID].emplace_back(id, 1), g[id].emplace_back(lastID, 1);
            lastID = id;
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int src, dst;
        cin >> src >> dst;
        dijkstra(src);
        minDis = minTrans = INT_MAX;
        ans.clear(), temp.clear();
        dfs(src, dst);
        print(ans);
    }

    return 0;
}
// @pintia code=end
