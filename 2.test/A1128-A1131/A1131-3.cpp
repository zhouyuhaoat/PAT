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
#include <unordered_map>
#include <vector>

using namespace std;

const int ID = 1e4;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>{}(((long long)p.first << 16) | p.second);
    }
};

vector<bool> vis(ID);
vector<vector<int>> g(ID);
unordered_map<pair<int, int>, int, PairHash> line;

int minStop = INT_MAX, minTrans = INT_MAX; // minDist -> minStop
vector<int> res, temp;

void dfs(int u, int dst, int stop, int trans) {
    if (u == dst) {
        if (stop < minStop) {
            minStop = stop;
            minTrans = trans;
            res = temp;
        } else if (stop == minStop && trans < minTrans) {
            minTrans = trans;
            res = temp;
        }
        return;
    }
    if (stop >= minStop) return;
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = true, temp.emplace_back(v);
            int newTrans = trans; // each branch starts with the same original, as expands in bfs
            if (temp.size() >= 3) { // not the first or last node
                int pre = temp[temp.size() - 3], cur = temp[temp.size() - 2], next = v;
                if (line[{cur, pre}] != line[{cur, next}]) {
                    newTrans++;
                }
            }
            dfs(v, dst, stop + 1, newTrans);
            vis[v] = false, temp.pop_back();
        }
    }
}

void print(vector<int>& path) {
    cout << path.size() - 1 << "\n";
    int cur = line[{path[0], path[1]}];
    cout << "Take Line#" << cur << " from ";
    cout << setfill('0') << setw(4) << path[0] << " to ";
    for (int i = 1; i < (int)path.size() - 1; i++) {
        int next = line[{path[i], path[i + 1]}];
        if (next != cur) {
            cout << setfill('0') << setw(4) << path[i] << ".\n";
            cout << "Take Line#" << next << " from ";
            cout << setfill('0') << setw(4) << path[i] << " to ";
            cur = next;
        }
    }
    cout << setfill('0') << setw(4) << path.back() << ".\n";
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
        fill(vis.begin(), vis.end(), false);
        minStop = minTrans = INT_MAX;
        res.clear(), temp.clear();
        vis[src] = true, temp.emplace_back(src); // source
        dfs(src, dst, 0, 0);
        print(res);
    }

    return 0;
}
// @pintia code=end
