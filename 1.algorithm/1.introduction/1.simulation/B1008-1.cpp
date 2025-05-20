/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:29:18
 *	modified:	2023-03-22 16:38:11
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805316250615808 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1008 数组元素循环右移问题
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805316250615808
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& vec, int lo, int hi, int& cnt) {
    for (int i = lo; i < hi; i++) {
        cout << vec[i];
        --cnt > 0 ? cout << " " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    m %= n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = n; // count of elements to be printed
    print(a, n - m, n, cnt); // the last m elements
    print(a, 0, n - m, cnt); // the first n - m elements

    return 0;
}
// @pintia code=end
