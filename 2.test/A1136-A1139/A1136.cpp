/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:23:46
 *	modified:	2023-04-04 09:23:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805345732378624 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1136 A Delayed Palindrome
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345732378624
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

string sum(string a, string b) { // sum of two string
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        if (sum >= 10) {
            carry = sum / 10;
            sum %= 10;
        } else {
            carry = 0;
        }
        b[i] = sum + '0';
    }
    if (carry > 0) {
        b = char(carry + '0') + b;
    }
    return b;
}

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    string c = s;
    reverse(c.begin(), c.end());
    if (s == c) {
        cout << s << " is a palindromic number.\n";
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        string a = s, b = s;
        reverse(b.begin(), b.end());
        s = sum(a, b);
        cout << a << " + " << b << " = " << s << "\n";
        c = s;
        reverse(c.begin(), c.end());
        if (c == s) {
            cout << s << " is a palindromic number.\n";
            return 0;
        }
    }
    cout << "Not found in 10 iterations.\n";

    return 0;
}
// @pintia code=end