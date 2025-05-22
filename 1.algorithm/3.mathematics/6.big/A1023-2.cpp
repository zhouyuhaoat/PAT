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
#include <algorithm>
#include <iostream>

using namespace std;

string add(string a, string b) {
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        a[i] = sum % 10 + '0'; // in-place update
        carry = sum / 10;
    }
    if (carry != 0) {
        a = char(carry + '0') + a;
    }
    return a;
}

int main(int argc, char const *argv[]) {

    string s1;
    cin >> s1;
    string s2 = add(s1, s1);
    is_permutation(s1.begin(), s1.end(), s2.begin()) ? cout << "Yes\n" : cout << "No\n";
    cout << s2 << "\n";

    return 0;
}
// @pintia code=end
