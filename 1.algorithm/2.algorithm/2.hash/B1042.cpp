/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:30:48
 *	modified:	2023-03-25 21:38:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805280817135616 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1042 字符统计
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805280817135616
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    string a;
    getline(cin, a);
    unordered_map<char, int> cnt; // char -> frequency
    pair<char, int> res = {' ', -1}; // space (ASCII 32): the smallest printable character
    for (char ch : a) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (++cnt[ch] > res.second) {
                res = {ch, cnt[ch]};
            } else if (cnt[ch] == res.second) {
                res.first = min(res.first, ch); // alphabetical order
            }
        }
    }
    cout << res.first << " " << res.second << "\n";

    return 0;
}
// @pintia code=end
