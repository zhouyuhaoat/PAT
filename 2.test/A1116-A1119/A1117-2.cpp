/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:32:04
 *	modified:	2023-04-03 18:58:22
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805354762715136 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1117 Eddington Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805354762715136
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    sort(dist.begin(), dist.end(), greater<int>());
    dist.emplace_back(0); // add a dummy element for the last day
    int res = 0;
    for (int i = 0; i <= n; i++) {
        if (dist[i] <= i + 1) { // the day that one rides less and equal than E miles
            res = i;
            break;
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
