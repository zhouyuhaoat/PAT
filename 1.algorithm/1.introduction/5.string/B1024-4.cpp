/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-18 12:59:53
 * 	 modified: 	2025-02-18 13:04:04
 * 	 project: 	Programming Ability Test
 * 	 venue: 	914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805297229447168 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1024 科学计数法
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805297229447168
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;

    char sign = s[0], integer = s[1];
    int posE = s.find('E');
    string decimal = s.substr(3, posE - 3);
    int exp = stoi(s.substr(posE + 1));

    string res;
    if (exp >= (int)decimal.size()) {
        res = integer + decimal + string(exp - decimal.size(), '0');
    } else if (exp >= 0) {
        res = integer + decimal.substr(0, exp) + '.' + decimal.substr(exp);
    } else if (exp < 0) {
        res = "0." + string(abs(exp) - 1, '0') + integer + decimal;
    }
    if (sign == '-') {
        res = '-' + res;
    }

    cout << res << "\n";

    return 0;
}
// @pintia code=end
