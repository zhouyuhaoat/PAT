/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:55:11
 *	modified:	2023-03-22 22:01:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805470349344768 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1027 Colors in Mars
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805470349344768
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string Mars = "0123456789ABC";
    cout << "#";
    for (int i = 0; i < 3; i++) {
        int color;
        cin >> color;
        cout << Mars[color / 13] << Mars[color % 13];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
