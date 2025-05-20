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

vector<int> convert(int n, int base) {
    vector<int> stk; // stack -> vector for reverse order
    do {
        stk.emplace_back(n % base);
        n /= base;
    } while (n != 0);
    return stk;
}

bool isPalindrome(vector<int> s) {
    for (int lo = 0, hi = s.size() - 1; lo < hi; lo++, hi--) {
        if (s[lo] != s[hi]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n, base;
    cin >> n >> base;
    vector<int> stk = convert(n, base);
    isPalindrome(stk) ? cout << "Yes\n" : cout << "No\n";
    for (int i = stk.size() - 1; i >= 0; i--) {
        cout << stk[i];
        i > 0 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
