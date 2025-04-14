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
    unordered_map<int, int> l; // location
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        l[d] = i;
    }
    int cnt = 0, mismatch = 0;
    bool sorted = false;
    while (!sorted) {
        while (l[0] != 0) {
            swap(l[0], l[l[0]]); // sort with swap(0, i)
            cnt++;
        }
        // 0 is at the proper place
        // but the rest of the elements are possibly not sorted
        sorted = true;
        for (int i = mismatch; i < n; i++) { // find the first unsorted element
            if (l[i] != i) {
                swap(l[i], l[0]); // move 0 to the unsorted element
                cnt++;
                mismatch = i; // for the next round
                sorted = false;
                break;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
