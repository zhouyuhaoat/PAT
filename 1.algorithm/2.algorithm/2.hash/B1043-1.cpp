/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:38:38
 *	modified:	2023-03-25 21:47:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805280074743808 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1043 输出PATest
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805280074743808
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    unordered_map<char, int> cnt; // char -> frequency
    for (char ch : s) {
        cnt[ch]++;
    }
    string symbol = "PATest", res;
    bool done = false; // whether output all symbols
    while (!done) {
        done = true; // assume all symbols are output
        for (int i = 0; i < 6; i++) {
            if (cnt[symbol[i]] != 0) {
                res += symbol[i];
                cnt[symbol[i]]--;
                done = false;
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
