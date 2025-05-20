/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 18:51:28
 *	modified:	2023-03-22 19:05:27
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    vector<long long> dist(n + 1); // dist[i]: prefix sum, the distance from 1 to i
    long long total = 0;
    for (int i = 1; i < n + 1; i++) {
        dist[i] = total;
        int d;
        cin >> d;
        total += d;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int src, dst; // source -> destination
        cin >> src >> dst;
        if (src > dst) { // ensure src <= dst
            swap(src, dst);
        }
        long long d = dist[dst] - dist[src];
        cout << min(d, total - d) << "\n"; // cycle: another direction
    }

    return 0;
}
// @pintia code=end
