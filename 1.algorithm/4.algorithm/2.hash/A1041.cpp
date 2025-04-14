/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:52:17
 *	modified:	2023-03-25 21:57:08
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805444361437184 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1041 Be Unique
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805444361437184
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    for (int it : d) {
        if (cnt[it] == 1) {
            cout << it << "\n";
            return 0;
        }
    }
    cout << "None\n";

    return 0;
}
// @pintia code=end
