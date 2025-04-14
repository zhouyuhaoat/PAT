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

    string a;
    cin >> a;
    unordered_map<char, int> cnt;
    for (int i = 0; i < (int)a.size(); i++) {
        cnt[a[i]]++;
    }
    const string symbol = "PATest";
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = 0; j < 6; j++) {
            if (cnt[symbol[j]] != 0) {
                cout << symbol[j];
                cnt[symbol[j]]--;
                flag = true;
            }
        }
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
