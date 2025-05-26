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
    vector<int> data(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sum += data[i];
    }
    sort(data.begin(), data.end());
    int left = 0;
    for (int i = 0; i < n / 2; i++) { // n / 2 elements in the left set
        left += data[i];
    }
    int right = sum - left; // n / 2 + n % 2 elements in the right set
    cout << n % 2 << " " << right - left << "\n";

    return 0;
}
// @pintia code=end
