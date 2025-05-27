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
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    /*
        Traveling Salesman Problem, TSP: find the shortest path that visits each vertex exactly once
        1. TS simple cycle: start and end at the same vertex, and visit each vertex exactly once
        2. TS cycle: start and end at the same vertex, and visit each vertex at least once
        3. Not a TS cycle: not start and end at the same vertex, or visit some vertex more than once
    */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int a, b, dis;
        cin >> a >> b >> dis;
        dist[a][b] = dist[b][a] = dis;
    }
    int k;
    cin >> k;
    int minID = -1, minDist = INT_MAX;
    for (int q = 0; q < k; q++) {
        int N, src;
        cin >> N >> src;
        int last = src, dst, dis = 0;
        bool reachable = true;
        unordered_set<int> path;
        for (int i = 1; i < N; i++) {
            cin >> dst;
            dis += dist[last][dst];
            if (dist[last][dst] == 0) {
                reachable = false;
            }
            path.emplace(dst);
            last = dst;
        }
        bool simpleCycle = false, cycle = false;
        if (src == dst && reachable) { // start and end at the same vertex
            if ((int)path.size() == n) { // TS cycle: visit each vertex at least once
                cycle = true;
                if (N == n + 1) { // TS simple cycle: visit each vertex exactly once
                    simpleCycle = true;
                }
            }
        }
        cout << "Path " << q + 1 << ": ";
        if (reachable) {
            cout << dis;
            if ((simpleCycle || cycle) && dis < minDist) {
                minDist = dis;
                minID = q + 1;
            }
        } else {
            cout << "NA";
        }
        if (simpleCycle) {
            cout << " (TS simple cycle)\n";
        } else if (cycle) {
            cout << " (TS cycle)\n";
        } else {
            cout << " (Not a TS cycle)\n";
        }
    }
    cout << "Shortest Dist(" << minID << ") = " << minDist << "\n";

    return 0;
}
// @pintia code=end
