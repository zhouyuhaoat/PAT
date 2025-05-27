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

vector<vector<int>> edge; // adjacency matrix

bool isClique(vector<int>& seq) {
    // clique: every two vertices are adjacent
    for (int i = 1; i < (int)seq.size(); i++) {
        for (int j = 1; j < i; j++) {
            int u = seq[i], v = seq[j];
            if (edge[u][v] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isMaximalClique(vector<int>& seq, int V, vector<bool>& vis) {
    // maximal clique: cannot add any vertex to form a larger clique
    for (int v = 1; v <= V; v++) {
        if (!vis[v]) {
            bool more = true; // extended by including one more
            for (int j = 1; j < (int)seq.size(); j++) {
                int u = seq[j];
                if (edge[u][v] != 1) {
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

    int V, E; // vertices, edges
    cin >> V >> E;
    edge.resize(V + 1, vector<int>(V + 1));
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = edge[v][u] = 1; // undirected graph
    }
    int m;
    cin >> m;
    while (m--) {
        int K;
        cin >> K;
        vector<int> seq(K + 1);
        vector<bool> vis(V + 1);
        for (int i = 1; i <= K; i++) {
            cin >> seq[i];
            vis[seq[i]] = true;
        }
        if (!isClique(seq)) {
            cout << "Not a Clique\n";
        } else {
            if (!isMaximalClique(seq, V, vis)) {
                cout << "Not Maximal\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
