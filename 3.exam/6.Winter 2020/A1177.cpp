/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 20:39:06
 *	modified:	2023-04-14 20:42:25
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1729419732192542721 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1177 Subsequence in Substring
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542721
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s, p;
    cin >> s >> p;
    int sta = 0, minl = 10001;
    for (int i = 0; i <= (int)s.size() - (int)p.size(); i++) {
        if (s[i] == p[0]) { // possibly the start of a subsequence
            int k = 0;
            for (int j = i; j < (int)s.size(); j++) {
                if (j - i + 1 >= minl) {
                    break;
                }
                if (s[j] == p[k]) {
                    k++; // subsequence, not substring
                    if (k == (int)p.size() && j - i + 1 < minl) {
                        sta = i;
                        minl = j - i + 1;
                    }
                }
            }
        }
    }
    cout << s.substr(sta, minl) << "\n";

    return 0;
}
// @pintia code=end