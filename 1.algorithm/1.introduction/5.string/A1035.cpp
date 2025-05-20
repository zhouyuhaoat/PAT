/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 20:07:58
 *	modified:	2023-03-23 20:29:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805454989803520 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1035 Password
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805454989803520
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<pair<string, string>> account; // {name, password}
    unordered_map<char, char> replace = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
    for (int i = 0; i < n; i++) {
        string name, pwd;
        cin >> name >> pwd;
        bool modified = false;
        for (int j = 0; j < (int)pwd.size(); j++) {
            if (replace.find(pwd[j]) != replace.end()) {
                pwd[j] = replace[pwd[j]];
                modified = true;
            }
        }
        if (modified) {
            account.emplace_back(name, pwd);
        }
    }
    if (!account.empty()) {
        cout << account.size() << "\n";
        for (auto [name, pwd] : account) {
            cout << name << " " << pwd << "\n";
        }
    } else {
        if (n == 1) {
            cout << "There is 1 account and no account is modified\n";
        } else {
            cout << "There are " << n << " accounts and no account is modified\n";
        }
    }

    return 0;
}
// @pintia code=end
