/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 14:36:06
 *	modified:	2023-03-31 14:06:38
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805456881434624 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1034 Head of a Gang
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805456881434624
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<bool> vis;
vector<int> pw;
vector<vector<int>> g, w, ans;

void dfs(vector<int>& tmp, int s) {
    vis[s] = true;
    tmp.emplace_back(s);
    for (int i = 0; i < (int)g[s].size(); i++) {
        if (!vis[g[s][i]]) {
            dfs(tmp, g[s][i]);
        }
    }
}

int cnt = 1;
map<string, int> mid;
map<int, string> mstr;
void getid(string s) {
    if (mid[s] == 0) {
        mid[s] = cnt;
        mstr[cnt] = s;
        ++cnt;
    }
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int t;
        cin >> n1 >> n2 >> t;
        getid(n1), getid(n2);
        d[i].insert(d[i].end(), {mid[n1], mid[n2], t});
    }
    g.resize(cnt), pw.resize(cnt);
    w.resize(cnt, vector<int>(cnt));
    for (int i = 0; i < n; i++) {
        g[d[i][0]].emplace_back(d[i][1]);
        g[d[i][1]].emplace_back(d[i][0]);
        pw[d[i][0]] += d[i][2];
        pw[d[i][1]] += d[i][2];
        w[d[i][0]][d[i][1]] += d[i][2];
        w[d[i][1]][d[i][0]] += d[i][2];
    }
    vis.resize(cnt, false);
    for (int i = 1; i <= cnt - 1; i++) {
        if (!vis[i]) {
            vector<int> tmp; // connected component
            dfs(tmp, i);
            ans.emplace_back(tmp);
        }
    }
    map<string, int> gang;
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i].size() > 2) {
            int sum = 0; // each pair of people
            for (int j = 0; j < (int)ans[i].size(); j++) {
                for (int k = j + 1; k < (int)ans[i].size(); k++) {
                    sum += w[ans[i][j]][ans[i][k]];
                }
            }
            if (sum > k) {
                // head of gang
                sort(ans[i].begin(), ans[i].end(), [](int a, int b) -> bool {
                    if (pw[a] != pw[b]) {
                        return pw[a] > pw[b];
                    } else {
                        return mstr[a] < mstr[b];
                    }
                });
                gang[mstr[ans[i][0]]] = ans[i].size();
            }
        }
    }
    cout << gang.size() << "\n";
    for (auto it : gang) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}
// @pintia code=end