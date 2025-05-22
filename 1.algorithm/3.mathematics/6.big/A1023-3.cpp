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

string add(string a, string b) {
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        a[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry != 0) {
        a = char(carry + '0') + a;
    }
    return a;
}

int main(int argc, char const *argv[]) {

    const int DIGIT = 10;
    string s1;
    cin >> s1;
    vector<int> cnt1(DIGIT);
    for (char ch : s1) {
        cnt1[ch - '0']++;
    }
    string s2 = add(s1, s1);
    vector<int> cnt2(DIGIT);
    for (char ch : s2) {
        cnt2[ch - '0']++;
    }
    cnt1 == cnt2 ? cout << "Yes\n" : cout << "No\n";
    cout << s2 << "\n";

    return 0;
}
// @pintia code=end
