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
    string quotient;
    int remainder = 0;
    for (char ch : a) {
        int n = ch - '0' + remainder * 10;
        quotient += n / b + '0';
        remainder = n % b;
    }
    quotient.erase(0, quotient.find_first_not_of('0')); // erase leading zeros
    return {quotient.empty() ? "0" : quotient, remainder};
}

int main(int argc, char const *argv[]) {

    string a;
    int b;
    cin >> a >> b;
    auto [quotient, remainder] = divide(a, b);
    cout << quotient << " " << remainder << "\n";

    return 0;
}
// @pintia code=end
