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

    int base = 13;
    string mars1[base] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string mars2[base] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    unordered_map<string, int> earth1, earth2; // mars -> earth
    for (int i = 0; i < base; i++) {
        earth1[mars1[i]] = i;
        earth2[mars2[i]] = i;
    }
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0])) { // earth -> mars
            int num = stoi(s);
            if (num < 13) {
                cout << mars1[num] << "\n";
            } else if (num % 13 == 0) {
                cout << mars2[num / base] << "\n";
            } else {
                cout << mars2[num / base] << " " << mars1[num % base] << "\n";
            }
        } else { // mars -> earth
            if (s.size() > 3) {
                cout << earth2[s.substr(0, 3)] * base + earth1[s.substr(4, 3)] << "\n";
            } else {
                if (earth1[s] != 0) { // earth1[s] exists
                    cout << earth1[s] << "\n";
                } else { // earth2[s] exists
                    cout << earth2[s] * 13 << "\n";
                }
            }
        }
    }

    return 0;
}
// @pintia code=end
