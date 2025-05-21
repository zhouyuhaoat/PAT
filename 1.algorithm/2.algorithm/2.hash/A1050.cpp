/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:59:55
 *	modified:	2023-03-25 22:00:08
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805429018673152 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1050 String Subtraction
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805429018673152
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string a, b;
    getline(cin, a), getline(cin, b);
    string sub;
    for (char ch : a) {
        if (b.find(ch) == string::npos) { // a - b
            sub += ch;
        }
    }
    cout << sub << "\n";

    return 0;
}
// @pintia code=end
