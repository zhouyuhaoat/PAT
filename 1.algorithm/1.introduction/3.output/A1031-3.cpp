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
    int n = s.size() + 2;
    int n1 = n / 3, n3 = n1, n2 = n - n1 - n3;
    int lo = 0, hi = s.size() - 1; // two ends of U-shape string
    for (; lo < n1 - 1; lo++, hi--) {
        cout << s[lo] << string(n2 - 2, ' ') << s[hi] << "\n";
    }
    while (lo <= hi) {
        cout << s[lo++];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
