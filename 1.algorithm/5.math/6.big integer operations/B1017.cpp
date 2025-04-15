/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:39:17
 *	modified:	2023-04-11 09:49:24
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805305181847552 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1017 A除以B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805305181847552
*/

// @pintia code=start
#include <iostream>

using namespace std;

pair<string, int> divide(string a, int b) {
    string c;
    int mod = 0; // dividend remainder
    for (int i = 0; i < (int)a.size(); i++) {
        int n = a[i] - '0' + mod * 10;
        c += n / b + '0'; // quotient
        mod = n % b;
    }
    c.erase(0, c.find_first_not_of('0')); // erase leading zeros
    return c.empty() ? make_pair("0", mod) : make_pair(c, mod);
}

int main(int argc, char const *argv[]) {

    string a;
    int b;
    cin >> a >> b;
    auto [c, mod] = divide(a, b);
    cout << c << " " << mod << "\n";

    return 0;
}
// @pintia code=end
