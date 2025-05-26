/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 01:51:08
 *	modified:	2023-04-03 01:55:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805352925609984 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1120 Friend Numbers
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805352925609984
*/

// @pintia code=start
#include <iostream>
#include <set>

using namespace std;

int convert(int n) { // sum of each digit
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    set<int> res;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        res.emplace(convert(num));
    }
    cout << res.size() << "\n";
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it;
        next(it) != res.end() ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
