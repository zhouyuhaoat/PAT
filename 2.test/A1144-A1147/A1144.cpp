/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 14:22:21
 *	modified:	2023-04-04 14:24:51
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805343463260160 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1144 The Missing Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343463260160
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        exist[v] = true;
    }
    for (int i = 1; i < 1e6; i++) {
        if (!exist[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end
