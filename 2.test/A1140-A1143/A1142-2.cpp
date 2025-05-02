/*
 *	author:		zhouyuhao
 *	created:	2025-04-02 13:13:21
 *	modified:	2025-05-02 13:28:21
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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

vector<vector<int>> edge;

bool isConnected(vector<int>& seq, int k, int v) {
    // check if vertex v is connected to all vertices in seq[1..k]
    for (int i = 1; i <= k; i++) {
        if (edge[v][seq[i]] != 1) {
            return false;
        }
    }
    return true;
}

bool isClique(vector<int>& seq, int k) {
    for (int i = 1; i <= k; i++) {
        if (!isConnected(seq, i - 1, seq[i])) { // all previous vertices
            return false;
        }
    }
    return true;
}

bool isMaximalClique(vector<int>& seq, int k, int v, vector<bool>& vis) {
    for (int i = 1; i <= v; i++) {
        if (!vis[i] && isConnected(seq, k, i)) { // all vertices
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int v, e;
    cin >> v >> e;
    edge.resize(v + 1, vector<int>(v + 1));
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = edge[v][u] = 1;
    }
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        int k;
        cin >> k;
        vector<int> seq(k + 1);
        vector<bool> vis(v + 1);
        for (int i = 1; i <= k; i++) {
            cin >> seq[i];
            vis[seq[i]] = true;
        }
        if (!isClique(seq, k)) {
            cout << "Not a Clique\n";
        } else {
            if (!isMaximalClique(seq, k, v, vis)) {
                cout << "Not Maximal\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
