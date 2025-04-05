/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 22:25:16
 *	modified:	2023-03-30 23:12:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805396953219072 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1072 Gas Station
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805396953219072
*/

// @pintia code=start
#include <climits>
#include <cmath>
#include <iomanip>
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
vector<int> d;
vector<vector<sta>> g;

void dijkstra(int s) {
    fill(d.begin(), d.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
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
                    q.emplace(v, d[v]);
                }
            }
        }
    }
}

int getid(string s, int n) {
    int id = 0;
    if (!isdigit(s[0])) {
        s.erase(0, 1);
        id += n; // gas station
    }
    return id + stoi(s);
}

int main(int argc, char const *argv[]) {

    int n, m, k, ds;
    cin >> n >> m >> k >> ds;
    d.resize(n + m + 1), vis.resize(n + m + 1);
    g.resize(n + m + 1);
    for (int i = 0; i < k; i++) {
        string p1, p2;
        int dist;
        cin >> p1 >> p2 >> dist;
        int id1 = getid(p1, n), id2 = getid(p2, n);
        g[id1].emplace_back(id2, dist);
        g[id2].emplace_back(id1, dist);
    }
    int maxdis = -1, can = -1;
    double avedis = -1;
    // traverse all gas stations
    for (int s = n + 1; s <= n + m; s++) {
        dijkstra(s);
        int dis = INT_MAX, sumdis = 0;
        bool islaw = true;
        for (int i = 1; i <= n; i++) {
            dis = min(dis, d[i]);
            sumdis += d[i];
            if (d[i] > ds) { // out of range
                islaw = false;
                break;
            }
        }
        if (islaw) {
            if (dis > maxdis) {
                maxdis = dis;
                avedis = (double)sumdis / n;
                can = s;
            } else if (dis == maxdis) {
                if ((double)sumdis / n < avedis) {
                    avedis = (double)sumdis / n;
                    can = s;
                }
            }
        }
    }
    if (can != -1) {
        cout << "G" << can - n << "\n";
        cout << fixed << setprecision(1) << (double)maxdis << " ";
        cout << fixed << setprecision(1) << round(avedis * 10) / 10 << "\n";
    } else {
        cout << "No Solution\n";
    }

    return 0;
}
// @pintia code=end