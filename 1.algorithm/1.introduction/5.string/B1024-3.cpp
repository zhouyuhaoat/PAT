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
    if (sign == '-') {
        res.push_back(sign);
    }

    if (exp >= (int)decimal.size()) {
        res.push_back(integer);
        res.append(decimal);
        res.append(exp - decimal.size(), '0');
    } else if (exp >= 0) {
        res.push_back(integer);
        res.append(decimal, 0, exp); // append nothing if exp == 0
        res.push_back('.');
        res.append(decimal, exp);
    } else if (exp < 0) {
        res += "0.";
        res.append(abs(exp) - 1, '0');
        res.push_back(integer);
        res.append(decimal);
    }

    cout << res << "\n";

    return 0;
}
// @pintia code=end
