/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 13:13:21
 *	modified:	2023-04-04 13:28:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805343979159552 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1142 Maximal Clique
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343979159552
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int nv, ne; // vertices, edges
    cin >> nv >> ne;
    vector<vector<int>> e(nv + 1, vector<int>(nv + 1)); // adjacency matrix
    for (int i = 0; i < ne; i++) {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        int k;
        cin >> k;
        vector<int> s(k);
        vector<bool> vis(nv);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
            vis[s[i]] = true;
        }
        bool isclq = true; // clique: every two vertices are adjacent
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (e[s[i]][s[j]] != 1) {
                    isclq = false;
                    break;
                }
            }
            if (!isclq) {
                break;
            }
        }
        if (!isclq) {
            cout << "Not a Clique\n";
            continue;
        }
        bool ismax = true;
        // maximal clique: cannot add any vertex to form a larger clique
        for (int i = 1; i <= nv; i++) {
            if (!vis[i]) {
                bool iscnt = true;
                for (int j = 0; j < k; j++) {
                    if (e[i][s[j]] != 1) {
                        iscnt = false;
                        break;
                    }
                }
                if (iscnt) {
                    ismax = false;
                    break;
                }
            }
        }
        if (!ismax) {
            cout << "Not Maximal\n";
            continue;
        }
        cout << "Yes\n";
    }

    return 0;
}
// @pintia code=end