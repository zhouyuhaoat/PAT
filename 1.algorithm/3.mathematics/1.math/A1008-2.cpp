/*
 *	author:		zhouyuhao
 *	created:	2024-04-29 10:01:00
 *	modified:	2024-04-29 10:10:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805511923286016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1008 Elevator
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805511923286016
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int now = 0, next = 0, time = 0;
    cin >> next;
    while (cin >> next) { // online
        if (next > now) {
            time += (next - now) * 6;
        } else {
            time += (now - next) * 4;
        }
        time += 5;
        now = next;
    }
    cout << time << "\n";

    return 0;
}
// @pintia code=end
