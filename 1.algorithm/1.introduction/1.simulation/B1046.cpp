/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:23:39
 *	modified:	2023-03-22 16:28:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805277847568384 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1046 划拳
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805277847568384
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0; // lose => drink
    for (int i = 0; i < n; i++) {
        int m1, h1, m2, h2; // mouth, hand
        cin >> m1 >> h1 >> m2 >> h2;
        int sum = m1 + m2;
        if (h1 == sum && h2 != sum) { // 1 wins, 2 loses
            cnt2++;
        } else if (h1 != sum && h2 == sum) { // 1 loses, 2 wins
            cnt1++;
        }
    }
    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}
// @pintia code=end
