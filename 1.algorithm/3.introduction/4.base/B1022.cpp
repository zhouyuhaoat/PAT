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
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

    int a, b, d;
    cin >> a >> b >> d;
    int c = a + b;
    stack<int> r;
    do {
        r.emplace(c % d);
        c /= d;
    } while (c != 0);
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }
    cout << "\n";

    return 0;
}
// @pintia code=end