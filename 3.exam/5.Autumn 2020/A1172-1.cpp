/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 13:57:59
 *	modified:	2023-04-14 19:15:20
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1172 Panda and PP Milk
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173568
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> weight(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    vector<int> left(n + 1), right(n + 1);
    // count of strict decreases in a non-increasing sequence
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n && weight[j] >= weight[j + 1]; j++) { // right-ward
            if (weight[j] > weight[j + 1]) {
                right[i]++;
            }
        }
    }
    for (int i = n; i > 1; i--) {
        for (int j = i; j > 1 && weight[j] >= weight[j - 1]; j--) { // left-ward
            if (weight[j] > weight[j - 1]) {
                left[i]++;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += max(left[i], right[i]) * 100 + 200;
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
