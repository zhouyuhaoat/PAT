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

    string n1;
    cin >> n1;
    vector<int> cnt_n1(10);
    for (int i = 0; i < (int)n1.size(); i++) {
        ++cnt_n1[n1[i] - '0'];
    }
    string n2;
    int carry = 0;
    for (int i = n1.size() - 1; i >= 0; i--) {
        int sum = (n1[i] - '0') * 2 + carry;
        n2 = char(sum % 10 + '0') + n2;
        carry = sum / 10;
    }
    if (carry != 0) {
        n2 = char(carry + '0') + n2;
    }
    vector<int> cnt_n2(10);
    for (int i = 0; i < (int)n2.size(); i++) {
        ++cnt_n2[n2[i] - '0'];
    }
    if (cnt_n1 == cnt_n2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    cout << n2 << "\n";

    return 0;
}
// @pintia code=end