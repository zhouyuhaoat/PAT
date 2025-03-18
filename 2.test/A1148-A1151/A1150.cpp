/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 17:29:05
 *	modified:	2023-04-04 18:22:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=1038430013544464384 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1150 Travelling Salesman Problem
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038430013544464384
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    // Traveling Salesman Problem, TSP: find the shortest path that visits each vertex exactly once
    // TS simple cycle: start and end at the same vertex, and visit each vertex exactly once
    // TS cycle: start and end at the same vertex, and visit each vertex at least once
    // Not a TS cycle: not start and end at the same vertex, or visit some vertex more than once
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        d[a][b] = d[b][a] = dist;
    }
    int k;
    cin >> k;
    int minid = -1, mindist = INT_MAX;
    for (int q = 0; q < k; q++) {
        set<int> path;
        int nv, st;
        cin >> nv >> st;
        int lastid = st, en, dist = 0;
        bool isrea = true;
        for (int i = 1; i < nv; i++) {
            cin >> en;
            dist += d[lastid][en];
            if (d[lastid][en] == 0) { // not reachable
                isrea = false;
            }
            path.emplace(en);
            lastid = en;
        }
        bool issic = false, iscyc = false;
        if (st == en && isrea) {
            if (nv == n + 1 && (int)path.size() == n) { // TS simple cycle
                issic = true;
            } else if (nv > n + 1 && (int)path.size() == n) { // TS cycle
                iscyc = true;
            }
        }
        bool notsic = !issic && !iscyc; // not a TS cycle
        cout << "Path " << q + 1 << ": ";
        if (isrea) {
            cout << dist;
            if (!notsic && dist < mindist) {
                mindist = dist;
                minid = q + 1;
            }
        } else {
            cout << "NA";
        }
        if (issic) {
            cout << " (TS simple cycle)\n";
        } else if (iscyc) {
            cout << " (TS cycle)\n";
        } else {
            cout << " (Not a TS cycle)\n";
        }
    }
    cout << "Shortest Dist(" << minid << ") = " << mindist << "\n";

    return 0;
}
// @pintia code=end