/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 13:57:00
 *	modified:	2024-04-27 14:00:00
 *	item:		Programming Ability Test
 *	site:		Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805316250615808 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1008 数组元素循环右移问题
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805316250615808
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    m %= n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /*
        right cyclic shift, rotation (right)
        1. reverse the first n - m elements
        2. reverse the last m elements
        3. reverse the whole array
    */
    reverse(a.begin(), a.begin() + n - m);
    reverse(a.begin() + n - m, a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
