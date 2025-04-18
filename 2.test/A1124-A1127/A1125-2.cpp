/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:54:39
 *	modified:	2023-04-03 02:59:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805350316752896 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1125 Chain the Ropes
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805350316752896
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = (ans + d[i]) / 2;
    }
    cout << ans << "\n";

    return 0;
}
// @pintia code=end
