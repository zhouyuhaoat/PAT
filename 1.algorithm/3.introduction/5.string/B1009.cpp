/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:51:38
 *	modified:	2023-03-22 11:55:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805314941992960 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1009 说反话
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805314941992960
*/

// @pintia code=start
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

    stack<string> s;
    string w;
    while (cin >> w) {
        s.emplace(w);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        !s.empty() ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
