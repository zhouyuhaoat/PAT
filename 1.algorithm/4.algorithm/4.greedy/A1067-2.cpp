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
    unordered_map<int, int> loc;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        loc[d] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (loc[i] != i) { // out-of-place element
            while (loc[0] != 0) {
                swap(loc[0], loc[loc[0]]);
                cnt++;
            }
            if (loc[i] != i) { // still out-of-place after swap(0, i)
                swap(loc[0], loc[i]); // swap 0 with the out-of-place element
                // next swap(0, i) will make 0 at index 0, and i at index i
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
