/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 20:25:34
 *	modified:	2023-03-27 20:43:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805427332562944 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1051 Pop Sequence
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805427332562944
*/

// @pintia code=start
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n, k;
    cin >> m >> n >> k;
    for (int c = 0; c < k; c++) {
        vector<int> d(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            d[i] = i + 1;
            int num;
            cin >> num;
            q.emplace(num);
        }
        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.emplace(d[i]);
            if ((int)s.size() > m) break;
            while (!s.empty() && s.top() == q.front()) {
                s.pop(), q.pop();
            }
        }
        if (!s.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
// @pintia code=end