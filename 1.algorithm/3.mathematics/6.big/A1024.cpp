/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:37:06
 *	modified:	2023-04-11 16:06:46
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805476473028608 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1024 Palindromic Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805476473028608
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

    string n;
    int k;
    cin >> n >> k;
    int cnt = 0;
    while (k--) {
        string temp = n;
        reverse(temp.begin(), temp.end());
        if (n == temp) {
            break;
        }
        n = add(n, temp);
        cnt++;
    }
    cout << n << "\n" << cnt << "\n";

    return 0;
}
// @pintia code=end
