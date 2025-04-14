/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 11:12:11
 *	modified:	2023-03-26 12:37:52
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805403651522560 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1067 Sort with Swap(0, i)
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805403651522560
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<int, int> l;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        l[d] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i != l[i]) {
            while (l[0] != 0) {
                swap(l[0], l[l[0]]);
                cnt++;
            }
            if (i != l[i]) {
                swap(l[0], l[i]);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
