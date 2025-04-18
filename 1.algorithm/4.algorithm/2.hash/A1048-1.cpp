/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 15:21:14
 *	modified:	2023-03-27 15:28:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805432256675840 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1048 Find Coins
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805432256675840
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    unordered_map<int, int> p;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        p[d[i]]++;
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (p[m - d[i]] > 0 && !(d[i] == m / 2 && p[d[i]] == 1)) {
            s.emplace(d[i]);
        }
    }
    if (s.empty()) {
        cout << "No Solution\n";
    } else {
        cout << *s.begin() << " " << m - *s.begin() << "\n";
    }

    return 0;
}
// @pintia code=end
