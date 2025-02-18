/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 18:24:00
 *	modified:	2024-04-27 18:30:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
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
    // calculate by as squared as possible
    int n = s.size() + 2;
    int n1 = n / 3, n3 = n1, n2 = n - n1 - n3;
    for (int i = 0; i < n1 - 1; i++) { // vertical
        for (int j = 0; j < n2; j++) {
            if (j == 0) {
                cout << s[i];
            } else if (j == n2 - 1) {
                cout << s[s.size() - 1 - i];
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < n2; i++) { // bottom
        cout << s[n1 + i - 1];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end