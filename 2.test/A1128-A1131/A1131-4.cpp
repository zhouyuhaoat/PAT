/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 23:27:37
 *	modified:	2025-04-19 10:00:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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
#include <vector>

using namespace std;

const int maxn = 1e4;

vector<bool> vis(maxn);
vector<vector<int>> g(maxn);
map<pair<int, int>, int> line;

int minStop = INT_MAX, minTrans = INT_MAX;
vector<int> res, temp;

int transfer(vector<int>& path) {
    int cnt = 0;
    for (int i = 1; i < (int)path.size() - 1; i++) {
        if (line[{path[i], path[i - 1]}] != line[{path[i], path[i + 1]}]) {
            cnt++;
        }
    }
    return cnt;
}

void dfs(int u, int dst, int stop) {
    vis[u] = true;
    temp.emplace_back(u);
    if (u == dst) {
        if (stop < minStop) {
            minStop = stop;
            minTrans = transfer(temp);
            res = temp;
        } else if (stop == minStop) {
            int trans = transfer(temp);
            if (trans < minTrans) {
                minTrans = trans;
                res = temp;
            }
        }
        vis[u] = false;
        temp.pop_back();
        return;
    }
    if (stop >= minStop) {
        vis[u] = false;
        temp.pop_back();
        return;
    }
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, dst, stop + 1);
        }
    }
    vis[u] = false;
    temp.pop_back();
}

void print(vector<int>& path) {
    cout << path.size() - 1 << "\n";
    cout << "Take Line#" << line[{path[0], path[1]}] << " from ";
    cout << setfill('0') << setw(4) << path[0] << " to ";
    for (int i = 1; i < (int)path.size() - 1; i++) {
        if (line[{path[i], path[i + 1]}] != line[{path[i], path[i - 1]}]) {
            cout << setfill('0') << setw(4) << path[i] << ".\n";
            cout << "Take Line#" << line[{path[i], path[i + 1]}] << " from ";
            cout << setfill('0') << setw(4) << path[i] << " to ";
        }
    }
    cout << setfill('0') << setw(4) << path[path.size() - 1] << ".\n";
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
        fill(vis.begin(), vis.end(), false);
        minStop = minTrans = INT_MAX;
        res.clear(), temp.clear();
        dfs(src, dst, 0); // mark source in dfs
        print(res);
    }

    return 0;
}
// @pintia code=end
