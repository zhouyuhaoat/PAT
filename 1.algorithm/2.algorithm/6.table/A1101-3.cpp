/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:30:00
 *	modified:	2024-04-28 19:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805366343188480 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1101 Quick Sort
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805366343188480
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> original(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted.begin(), sorted.end());
    vector<int> res;
    int leftMax = 0; // max value in the left part of the original array
    for (int i = 0; i < n; i++) {
        if (original[i] == sorted[i]) { // sorted: candidate of pivot
            if (original[i] > leftMax) { // data > left + sorted => data < right
                res.emplace_back(original[i]);
            }
        }
        leftMax = max(leftMax, original[i]);
    }
    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i < (int)res.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
