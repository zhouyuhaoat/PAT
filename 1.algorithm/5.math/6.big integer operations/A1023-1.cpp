/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:27:24
 *	modified:	2023-04-11 15:36:40
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805478658260992 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1023 Have Fun with Numbers
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805478658260992
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    string s1;
    cin >> s1;
    vector<int> cnt_s1(10);
    for (int i = 0; i < (int)s1.size(); i++) {
        cnt_s1[s1[i] - '0']++;
    }
    string s2;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        int sum = (s1[i] - '0') * 2 + carry;
        s2 = char(sum % 10 + '0') + s2;
        carry = sum / 10;
    }
    if (carry != 0) {
        s2 = char(carry + '0') + s2;
    }
    vector<int> cnt_s2(10);
    for (int i = 0; i < (int)s2.size(); i++) {
        cnt_s2[s2[i] - '0']++;
    }
    cnt_s1 == cnt_s2 ? cout << "Yes\n" : cout << "No\n";
    cout << s2 << "\n";

    return 0;
}
// @pintia code=end
