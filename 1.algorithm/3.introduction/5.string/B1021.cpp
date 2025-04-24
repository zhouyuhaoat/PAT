/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:19:04
 *	modified:	2023-03-22 22:21:55
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805300404535296 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1021 个位数统计
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805300404535296
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    map<char, int> cnt;
    for (char ch : s) {
        cnt[ch]++;
    }
    for (auto [ch, freq] : cnt) {
        cout << ch << ":" << freq << "\n";
    }

    return 0;
}
// @pintia code=end
