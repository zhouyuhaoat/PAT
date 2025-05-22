/*
 *	author:		zhouyuhao
 *	created:	2024-05-02 19:29:46
 *	modified:	2024-05-02 19:41:46
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805316250615808 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1008 数组元素循环右移问题
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805316250615808
*/

// @pintia code=start
#include <iostream>
#include <numeric>
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
    if (m != 0) {
        int cycle = gcd(n, m);
        for (int i = 0; i < cycle; i++) {
            int now = i, temp = a[now];
            do {
                int next = (now + m) % n;
                swap(temp, a[next]);
                now = next;
            } while (now != i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
