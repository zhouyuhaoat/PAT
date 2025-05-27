/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 11:46:30
 *	modified:	2023-04-03 11:53:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805347145859072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1132 Cut Integer
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805347145859072
*/

// @pintia code=start
#include <iostream>

using namespace std;

bool isCut(string s) {
    int z = stoi(s), size = s.size() / 2;
    int a = stoi(s.substr(0, size)), b = stoi(s.substr(size));
    if (a * b != 0 && z % (a * b) == 0) {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        isCut(s) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
