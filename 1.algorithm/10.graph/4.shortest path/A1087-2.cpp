/*
 *	author:		zhouyuhao
 *	created:	2023-03-31 09:36:52
 *	modified:	2023-03-31 10:14:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805379664297984 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1087 All Roads Lead to Rome
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805379664297984
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct city {
    int v, cost;
    city(int v, int cost) : v(v), cost(cost) {
    }
    friend bool operator<(city a, city b) {
        return a.cost > b.cost;
    }
};

vector<bool> vis;
vector<int> h, c, pre, num, sum, cnt;
vector<vector<city>> g;

void dijkstra(int s) {
    c[s] = 0, num[s] = 1, sum[s] = h[s];
    priority_queue<city> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        city t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (!vis[v]) {
                if (c[u] + g[u][i].cost < c[v]) {
                    c[v] = c[u] + g[u][i].cost;
                    pre[v] = u;
                    num[v] = num[u];
                    sum[v] = sum[u] + h[v];
                    cnt[v] = cnt[u] + 1;
                    q.emplace(v, c[v]);
                } else if (c[u] + g[u][i].cost == c[v]) {
                    num[v] += num[u];
                    if (sum[u] + h[v] > sum[v]) {
                        sum[v] = sum[u] + h[v];
                        pre[v] = u;
                        cnt[v] = cnt[u] + 1;
                    } else if (sum[u] + h[v] == sum[v]) {
                        if ((float)(sum[u] + h[v]) / (cnt[u] + 1) > (float)sum[v] / cnt[v]) {
                            pre[v] = u;
                            cnt[v] = cnt[u] + 1;
                        }
                    }
                }
            }
        }
    }
}

vector<int> ans;
void dfs(int s, int v) {
    if (v == s) {
        ans.emplace_back(v);
        return;
    }
    dfs(s, pre[v]);
    ans.emplace_back(v);
}

int main(int argc, char const *argv[]) {

    int n, k;
    string s;
    cin >> n >> k >> s;
    c.resize(n, INT_MAX), vis.resize(n, false);
    h.resize(n), pre.resize(n), num.resize(n);
    sum.resize(n), cnt.resize(n), g.resize(n);
    map<string, int> mid;
    map<int, string> mstr;
    mid[s] = 0, mstr[0] = s;
    for (int i = 1; i < n; i++) {
        string c;
        cin >> c >> h[i];
        mid[c] = i, mstr[i] = c;
    }
    for (int i = 0; i < k; i++) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g[mid[c1]].emplace_back(mid[c2], cost);
        g[mid[c2]].emplace_back(mid[c1], cost);
    }
    dijkstra(mid[s]);
    int e = mid["ROM"];
    cout << num[e] << " " << c[e] << " " << sum[e] << " " << sum[e] / cnt[e] << "\n";
    dfs(mid[s], e);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << mstr[ans[i]];
        i < (int)ans.size() - 1 ? cout << "->" : cout << "\n";
    }

    return 0;
}
// @pintia code=end