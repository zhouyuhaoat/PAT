/*
 *	author:		zhouyuhao
 *	created:	2025-04-17 17:14:38
 *	modified:	2025-04-17 17:30:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805360043343872 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1109 Group Photo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
*/

// @pintia code=start
#include <algorithm>
#include <deque>
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
        deque<string> res; // double-ended queue: alternate, zig-zag, left & right
        for (int i = lo; i < hi; i++) {
            if ((i - lo) % 2 == 0) { // center, or right
                res.emplace_back(people[i].id);
            } else { // left
                res.emplace_front(people[i].id);
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
