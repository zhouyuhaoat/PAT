/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:06:59
 *	modified:	2023-03-22 16:13:04
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805306310115328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1016 部分A+B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805306310115328
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

int convert(string s, char ch) {
    int cnt = count(s.begin(), s.end(), ch);
    string res = string(cnt, ch);
    if (!res.empty()) {
        return stoi(res);
    }
    return 0;
}

int main(int argc, char const *argv[]) {

    string a, b;
    char da, db; // digit
    cin >> a >> da >> b >> db;
    int pa = convert(a, da), pb = convert(b, db); // partial
    cout << pa + pb << "\n";

    return 0;
}
// @pintia code=end
