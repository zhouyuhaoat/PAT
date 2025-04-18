/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 10:16:08
 *	modified:	2023-04-14 10:22:51
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805357258326016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1113 Integer Set Partition
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805357258326016
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
    nth_element(d.begin(), d.begin() + n / 2, d.end()); // set partition
    int res = 0;
    for (int i = 0; i < n / 2; i++) {
        res += d[n - i - 1] - d[i];
    }
    if (n % 2 == 1) {
        res += d[n / 2];
    }
    cout << n % 2 << " " << res << "\n";

    return 0;
}
// @pintia code=end
