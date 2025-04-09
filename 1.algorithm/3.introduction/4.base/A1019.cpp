/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:47:26
 *	modified:	2023-03-22 21:54:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805487143337984 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1019 General Palindromic Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805487143337984
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<int> convert(int n, int b) {
    vector<int> s;
    do {
        s.emplace_back(n % b);
        n /= b;
    } while (n != 0);
    return s;
}

bool isPalindrome(vector<int> s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
    // return s == vector<int>(s.rbegin(), s.rend());
    // return equal(s.begin(), s.begin() + n / 2, s.rbegin());
}

int main(int argc, char const *argv[]) {

    int n, b;
    cin >> n >> b;
    vector<int> s = convert(n, b);
    isPalindrome(s) ? cout << "Yes\n" : cout << "No\n";
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
        i > 0 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
