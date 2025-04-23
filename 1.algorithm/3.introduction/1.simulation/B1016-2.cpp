/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 13:30:00
 *	modified:	2024-04-27 13:35:00
 *	item:		Programming Ability Test
 *	site:		Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805306310115328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1016 部分A+B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805306310115328
*/

// @pintia code=start
#include <iostream>

using namespace std;

int convert(string s, char ch) {
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ch) {
            res = res * 10 + (s[i] - '0');
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {

    string a, b;
    char da, db;
    cin >> a >> da >> b >> db;
    int pa = convert(a, da), pb = convert(b, db);
    cout << pa + pb << "\n";

    return 0;
}
// @pintia code=end
