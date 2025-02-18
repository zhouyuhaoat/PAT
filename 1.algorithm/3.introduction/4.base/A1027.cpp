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
#include <map>

using namespace std;

map<int, char> m = {{10, 'A'}, {11, 'B'}, {12, 'C'}};
char trans(int n) {
    if (n >= 10) {
        return m[n];
    }
    return n + '0';
};

int main(int argc, char const *argv[]) {

    cout << "#";
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        cout << trans(n / 13) << trans(n % 13);
    }
    cout << "\n";

    return 0;
}
// @pintia code=end