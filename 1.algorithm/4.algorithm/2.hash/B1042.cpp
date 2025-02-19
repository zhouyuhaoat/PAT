/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:30:48
 *	modified:	2023-03-25 21:38:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805280817135616 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1042 字符统计
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805280817135616
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    string a;
    getline(cin, a);
    map<char, int> cnt;
    int mc = -1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (isalpha(a[i])) {
            a[i] = tolower(a[i]);
            if (++cnt[a[i]] > mc) {
                mc = cnt[a[i]];
            }
        }
    }
    for (auto it : cnt) {
        if (it.second == mc) {
            cout << it.first << " " << it.second << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end