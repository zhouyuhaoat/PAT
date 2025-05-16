/*
 *	author:		zhouyuhao
 *	created:	2025-05-15 18:51:28
 *	modified:	2025-05-15 19:05:27
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805435700199424 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1046 Shortest Distance
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805435700199424
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<long long> dist(n + 2); // dist[n + 1] is the total distance
    for (int i = 2; i < n + 2; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1]; // prefix sum
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int src, dst;
        cin >> src >> dst;
        if (src > dst) {
            swap(src, dst);
        }
        long long dis = dist[dst] - dist[src];
        cout << min(dis, dist[n + 1] - dis) << "\n";
    }

    return 0;
}
// @pintia code=end
