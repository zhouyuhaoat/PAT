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

vector<vector<int>> e;

bool isClique(vector<int>& s, int k) {
    // clique: every two vertices are adjacent
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < i; j++) {
            if (e[s[i]][s[j]] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isMaximalClique(vector<int>& s, int k, int nv, vector<bool>& vis) {
    // maximal clique: cannot add any vertex to form a larger clique
    for (int i = 1; i <= nv; i++) {
        if (!vis[i]) {
            bool more = true; // extended by including one more
            for (int j = 1; j <= k; j++) {
                if (e[i][s[j]] != 1) {
                    more = false;
                    break;
                }
            }
            if (more) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int nv, ne; // vertices, edges
    cin >> nv >> ne;
    e.resize(nv + 1, vector<int>(nv + 1, 0)); // adjacency matrix
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
        vector<int> s(k + 1);
        vector<bool> vis(nv + 1);
        for (int i = 1; i <= k; i++) {
            cin >> s[i];
            vis[s[i]] = true;
        }
        if (!isClique(s, k)) {
            cout << "Not a Clique\n";
        } else {
            if (!isMaximalClique(s, k, nv, vis)) {
                cout << "Not Maximal\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
