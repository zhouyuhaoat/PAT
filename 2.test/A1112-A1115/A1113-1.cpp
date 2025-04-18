/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 09:54:07
 *	modified:	2023-04-02 10:20:46
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
    }
    sort(d.begin(), d.end());
    int sumL = 0; // set partition
    for (int i = 0; i <= n / 2 - 1; i++) {
        sumL += d[i];
    }
    cout << n % 2 << " " << sum - 2 * sumL << "\n";

    return 0;
}
// @pintia code=end
