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
    while (k--) {
        /*
            stack permutation, stack sequence, pop sequence
            - push n numbers in the order of 1, 2, 3, ..., n and pop randomly
        */
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            q.emplace(num);
        }
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            stk.emplace(i + 1); // push orderly
            if ((int)stk.size() > m) { // out of stack
                break;
            }
            while (!stk.empty() && stk.top() == q.front()) { // pop as much as possible
                stk.pop(), q.pop();
            }
        }
        stk.empty() ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
