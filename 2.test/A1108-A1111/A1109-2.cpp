/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:10:27
 *	modified:	2023-04-02 22:27:58
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805360043343872 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1109 Group Photo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct People {
    string id;
    int height;
};

int main(int argc, char const *argv[]) {

    int n, row;
    cin >> n >> row;
    vector<People> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].id >> people[i].height;
    }
    sort(people.begin(), people.end(), [](People a, People b) {
        if (a.height != b.height) {
            return a.height > b.height;
        } else {
            return a.id < b.id;
        }
    });
    for (int lo = 0, hi = n / row + n % row; lo < n; lo = hi, hi += n / row) {
        vector<string> res(hi - lo);
        int mi = res.size() / 2;
        for (int i = lo; i < hi; i++) {
            if ((i - lo) % 2 == 0) { // center, or then right
                // e.g. i = lo, index = mi, center position
                res[mi + (i - lo) / 2] = people[i].id;
            } else { // left firstly
                // e.g. i = lo + 1, index = mi - 1
                res[mi - (i - lo + 1) / 2] = people[i].id;
            }
        }
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i];
            i < (int)res.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
