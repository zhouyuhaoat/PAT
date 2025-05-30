/*
 *	author:		zhouyuhao
 *	created:	2025-05-12 07:42:10
 *	modified:	2025-05-12 08:08:52
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805514284679168 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1007 Maximum Subsequence Sum
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805514284679168
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    vector<int> data(k);
    int res = -1, sum = 0; // space optimization -> Kadane's algorithm
    int first = 0, last = k - 1, id = 0;
    for (int i = 0; i < k; i++) {
        cin >> data[i];
        sum += data[i];
        if (sum > res) {
            res = sum;
            first = id, last = i;
        } else if (sum < 0) {
            sum = 0;
            id = i + 1;
        }
    }
    if (res < 0) res = 0;
    cout << res << " " << data[first] << " " << data[last] << "\n";

    return 0;
}
// @pintia code=end
