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
    unordered_map<char, int> cnt;
    string symbol = "PATest";
    for (char ch : s) {
        if (symbol.find(ch) != string::npos) { // only count PATest
            cnt[ch]++;
        }
    }
    string res;
    while (!cnt.empty()) {
        for (int j = 0; j < 6; j++) {
            if (cnt.find(symbol[j]) != cnt.end()) {
                res += symbol[j];
                if (--cnt[symbol[j]] == 0) { // remove the symbol if done
                    cnt.erase(symbol[j]);
                }
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
