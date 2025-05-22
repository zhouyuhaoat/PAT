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
#include <vector>

using namespace std;

int gcd(int a, int b) { // greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    m %= n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (m != 0) {
        /*
            cycle (permutation): a sequence of positions where
            - elements are moved in a circular manner, forming a closed loop
            1. original: [1, 2, 3, 4, 5, 6]
            2. cycle  1: [5, 2, 1, 4, 3, 6]
            3. cycle  2: [5, 6, 1, 2, 3, 4]
        */
        int cycle = gcd(n, m);
        for (int i = 0; i < cycle; i++) {
            int now = i, temp = a[now];
            do {
                int next = (now + m) % n;
                swap(temp, a[next]); // temp = a[now] -> a[next] -> a[next[next]] -> ... -> a[now]
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
