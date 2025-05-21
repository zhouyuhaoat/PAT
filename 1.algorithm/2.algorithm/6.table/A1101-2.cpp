/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:09:50
 *	modified:	2023-03-26 21:32:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805366343188480 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1101 Quick Sort
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805366343188480
*/

// @pintia code=start
#include <climits>
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
    vector<int> leftMax(n, INT_MIN), rightMin(n, INT_MAX);
    for (int i = 1; i < n; i++) { // two pass -> one pass
        leftMax[i] = max(leftMax[i - 1], data[i - 1]);
        rightMin[n - 1 - i] = min(rightMin[n - i], data[n - i]);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (data[i] > leftMax[i] && data[i] < rightMin[i]) {
            res.emplace_back(data[i]);
        }
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
