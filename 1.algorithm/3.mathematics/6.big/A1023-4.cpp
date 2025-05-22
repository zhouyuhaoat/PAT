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

    const int DIGIT = 10;
    string s;
    cin >> s;
    vector<int> cnt(DIGIT);
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        cnt[s[i] - '0']++;
        int sum = (s[i] - '0') * 2 + carry;
        s[i] = sum % 10 + '0';
        carry = sum / 10;
        cnt[sum % 10]--;
    }
    if (carry > 0) {
        s = char(carry + '0') + s;
        cnt[carry]--;
    }
    bool flag = true;
    for (int i = 0; i < DIGIT; i++) {
        if (cnt[i] != 0) {
            flag = false;
            break;
        }
    }
    flag ? cout << "Yes\n" : cout << "No\n";
    cout << s << "\n";

    return 0;
}
// @pintia code=end
