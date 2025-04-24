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
    unordered_map<int, int> loc; // location
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        loc[d] = i;
    }
    int cnt = 0, idx = 0;
    bool sorted = false;
    while (!sorted) {
        while (loc[0] != 0) { // permutation cycle that involves 0
            swap(loc[0], loc[loc[0]]); // sort with swap(0, i)
            cnt++;
        }
        // 0 is at the proper place (index 0), but the rest of the elements are possibly not sorted
        sorted = true;
        for (int i = idx; i < n; i++) {
            if (loc[i] != i) { // the first out-of-place element
                swap(loc[0], loc[i]); // swap 0 (index 0) with the first out-of-place element
                // subsequent swaps must can move the out-of-place element to its proper place
                // reverse thinking: since the out-of-place element i is at index 0,
                // if we need to make 0 to index 0, we must previously make 0 to index i
                // so we can swap 0 with i to make 0 at index 0, and i at index i
                cnt++;
                idx = i;
                sorted = false;
                break;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
