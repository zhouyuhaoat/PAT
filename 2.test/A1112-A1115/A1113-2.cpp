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
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    nth_element(data.begin(), data.begin() + n / 2, data.end());
    // [0, n) -> partition -> [0, n / 2) + [n / 2, n)
    int res = 0;
    for (int i = 0; i < n / 2; i++) {
        res += data[n - 1 - i] - data[i]; // right - left
    }
    if (n % 2 == 1) { // odd -> middle
        res += data[n / 2];
    }
    cout << n % 2 << " " << res << "\n";

    return 0;
}
// @pintia code=end
