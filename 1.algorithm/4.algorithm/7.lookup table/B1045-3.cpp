/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:30:00
 *	modified:	2024-04-28 19:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805278589960192 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1045 快速排序
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805278589960192
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    vector<int> res;
    int lm = 0; // left max
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] > lm) {
            res.emplace_back(b[i]);
        }
        lm = max(lm, b[i]);
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
