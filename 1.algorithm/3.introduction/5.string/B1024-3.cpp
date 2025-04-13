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
#include <regex>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;

    // format: [+-][1-9].[0-9]+E[+-][0-9]+
    // sign integer . decimal E exp
    regex pattern(R"(([+-])([1-9])\.([0-9]+)E([+-][0-9]+))");
    smatch m;
    regex_match(s, m, pattern);
    string sign = m[1], integer = m[2], decimal = m[3];
    int exp = stoi(m[4]);

    string res;
    if (sign == "-") {
        res.push_back(sign[0]);
    }
    if (exp >= (int)decimal.size()) {
        res.push_back(integer[0]);
        res.append(decimal);
        res.append(exp - decimal.size(), '0');
    } else if (exp >= 0) {
        res.push_back(integer[0]);
        res.append(decimal, 0, exp);
        res.push_back('.');
        res.append(decimal, exp);
    } else if (exp < 0) {
        res += "0.";
        res.append(abs(exp) - 1, '0');
        res.push_back(integer[0]);
        res.append(decimal);
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
