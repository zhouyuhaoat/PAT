/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:41:17
 *	modified:	2023-03-22 11:51:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805299301433344 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1022 D进制的A+B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805299301433344
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<int> convert(int n, int base) {
    vector<int> stk; // stack -> vector for reverse order
    do {
        stk.emplace_back(n % base);
        n /= base;
    } while (n != 0);
    return stk;
}

int main(int argc, char const *argv[]) {

    int a, b, base;
    cin >> a >> b >> base;
    vector<int> stk = convert(a + b, base);
    for (int i = stk.size() - 1; i >= 0; i--) {
        cout << stk[i];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
