/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 11:16:27
 *	modified:	2023-04-11 11:31:57
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805511923286016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1008 Elevator
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805511923286016
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> l(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> l[i + 1];
    }
    int sum = 0;
    for (int i = 0; i < (int)l.size() - 1; i++) {
        int now = l[i], next = l[i + 1];
        if (next > now) {
            sum += (next - now) * 6;
        } else {
            sum += (now - next) * 4;
        }
        sum += 5;
    }
    cout << sum << "\n";

    return 0;
}
// @pintia code=end
