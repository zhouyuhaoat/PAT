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

vector<int> convert(int n, int d) {
    vector<int> s;
    do {
        s.emplace_back(n % d);
        n /= d;
    } while (n != 0);
    return s;
}

int main(int argc, char const *argv[]) {

    int a, b, d;
    cin >> a >> b >> d;
    int c = a + b;
    vector<int> s = convert(c, d);
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
