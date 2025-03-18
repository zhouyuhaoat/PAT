/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 13:53:09
 *	modified:	2023-04-04 12:57:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805344490864640 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1140 Look-and-say Sequence
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344490864640
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string d;
    int n;
    cin >> d >> n;
    for (int q = 0; q < n - 1; q++) {
        string s;
        for (int i = 0; i < (int)d.size(); i++) {
            int j = i, cnt = 0; // count the number of the same digit
            while (d[j] == d[i] && j++ < (int)d.size()) {
                ++cnt;
            }
            i = j - 1;
            s += d[i] + to_string(cnt);
        }
        d = s;
    }
    cout << d << "\n";

    return 0;
}
// @pintia code=end