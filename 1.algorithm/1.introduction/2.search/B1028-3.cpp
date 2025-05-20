/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:32:00
 *	modified:	2024-04-27 15:35:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805293282607104 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1028 人口普查
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805293282607104
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt = 0;
    string lo = "1814/09/05", hi = "2014/09/07"; // compare string of date directly
    pair<string, string> old = {"", hi}, young = {"", lo}; // {name, date}
    for (int i = 0; i < n; i++) {
        pair<string, string> p;
        cin >> p.first >> p.second;
        if (p.second > lo && p.second < hi) {
            cnt++;
            if (p.second > young.second) {
                young = p;
            }
            if (p.second < old.second) {
                old = p;
            }
        }
    }
    if (cnt != 0) {
        cout << cnt << " " << old.first << " " << young.first << "\n";
    } else {
        cout << cnt << "\n";
    }

    return 0;
}
// @pintia code=end
