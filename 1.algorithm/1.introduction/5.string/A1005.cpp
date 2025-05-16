/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 19:59:19
 *	modified:	2023-03-23 20:07:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805519074574336 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1005 Spell It Right
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805519074574336
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int sum = 0;
    for (char ch : s) {
        sum += ch - '0';
    }
    s = to_string(sum);
    string alphabet[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < (int)s.size(); i++) {
        cout << alphabet[(s[i] - '0')];
        i < (int)s.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
