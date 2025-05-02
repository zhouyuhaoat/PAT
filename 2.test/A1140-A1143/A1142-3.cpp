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

bool isClique(vector<int>& seq) {
    for (int i = 1; i < (int)seq.size(); i++) {
        for (int j = 1; j < i; j++) {
            if (edge[seq[i]][seq[j]] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isMaximalClique(vector<int>& seq, int k, int v, vector<bool>& vis) {
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            seq.emplace_back(i); // add vertex i to the sequence
            if (isClique(seq)) {
                seq.pop_back();
                return false; // found a larger clique
            }
            seq.pop_back();
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
        if (!isClique(seq)) {
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
