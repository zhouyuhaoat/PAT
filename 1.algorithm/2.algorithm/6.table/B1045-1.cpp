/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:09:50
 *	modified:	2023-03-26 21:32:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805278589960192 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1045 快速排序
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805278589960192
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
    cin >> data[0];
    vector<int> leftMax(n, INT_MIN), rightMin(n, INT_MAX);
    for (int i = 1; i < n; i++) {
        cin >> data[i];
        leftMax[i] = max(leftMax[i - 1], data[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], data[i + 1]);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (data[i] > leftMax[i] && data[i] < rightMin[i]) { // pivot: left < data < right
            res.emplace_back(data[i]); // increasing sequence since leftMax is asecending
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i < (int)res.size() - 1) cout << " ";
    }
    cout << "\n"; // also need to print a new line if there is no element

    return 0;
}
// @pintia code=end
