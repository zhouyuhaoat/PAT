/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 19:57:35
 *	modified:	2023-03-27 20:19:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805279328157696 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1044 火星数字
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805279328157696
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    const int base = 13;
    string Mars1[base] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string Mars2[base] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    unordered_map<string, int> Earth; // Mars -> Earth
    for (int i = 0; i < base; i++) { // initialize mapping table manually
        Earth[Mars1[i]] = i;
        if (i > 0) {
            Earth[Mars2[i]] = i * base;
        }
    }
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0])) { // Earth -> Mars
            int num = stoi(s);
            if (num < base) {
                cout << Mars1[num] << "\n";
            } else if (num % base == 0) {
                cout << Mars2[num / base] << "\n";
            } else {
                cout << Mars2[num / base] << " " << Mars1[num % base] << "\n";
            }
        } else { // Mars -> Earth
            if (s.size() > 3) {
                cout << Earth[s.substr(0, 3)] + Earth[s.substr(4, 3)] << "\n";
            } else {
                cout << Earth[s] << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
