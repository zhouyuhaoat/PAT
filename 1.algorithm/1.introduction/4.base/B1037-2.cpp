/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:30:21
 *	modified:	2023-03-22 21:38:06
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805284923359232 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1037 在霍格沃茨找零钱
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805284923359232
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int p1, p2, p3;
    scanf("%d.%d.%d", &p1, &p2, &p3);
    int a1, a2, a3;
    scanf("%d.%d.%d", &a1, &a2, &a3);
    if (p1 > a1 || (p1 == a1 && p2 > a2) || (p1 == a1 && p2 == a2 && p3 > a3)) {
        cout << "-";
        swap(p1, a1), swap(p2, a2), swap(p3, a3);
    }
    int c1 = a1 - p1, c2 = a2 - p2, c3 = a3 - p3;
    if (c3 < 0) { // borrowing
        c3 += 29, c2--;
    }
    if (c2 < 0) {
        c2 += 17, c1--;
    }
    cout << c1 << "." << c2 << "." << c3 << "\n";

    return 0;
}
// @pintia code=end
