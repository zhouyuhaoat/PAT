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
    vector<int> d(n);
    cin >> d[0];
    vector<int> leftmax(n, INT_MIN), rightmin(n, INT_MAX);
    for (int i = 1; i < n; i++) {
        cin >> d[i];
        leftmax[i] = max(leftmax[i - 1], d[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightmin[i] = min(rightmin[i + 1], d[i + 1]);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (d[i] > leftmax[i] && d[i] < rightmin[i]) {
            res.emplace_back(d[i]); // increasing sequence since leftmax is asecending
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
