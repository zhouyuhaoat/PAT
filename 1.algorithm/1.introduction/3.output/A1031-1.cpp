/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:17:38
 *	modified:	2023-03-22 21:29:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805462535356416 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1031 Hello World for U
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805462535356416
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int n = s.size(); // calculate manually
    int n1 = 0, n2 = 0, n3 = 0; // left vertical, bottom, right vertical
    for (n2 = 3; n2 <= n; n2++) { // assume
        int vert = n + 2 - n2; // 2 for corners
        if (vert % 2 == 0 && vert / 2 <= n2) {
            n1 = n3 = vert / 2;
            break;
        }
    }
    for (int i = 0; i < n1 - 1; i++) {
        cout << s[i] << string(n2 - 2, ' ') << s[s.size() - 1 - i] << "\n";
    }
    for (int i = 0; i < n2; i++) {
        cout << s[n1 - 1 + i];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
