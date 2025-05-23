/*
 *	author:		zhouyuhao
 *	created:	2025-05-18 20:25:34
 *	modified:	2025-05-18 20:43:03
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805427332562944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1051 Pop Sequence
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805427332562944
*/

// @pintia code=start
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n, k;
    cin >> m >> n >> k;
    while (k--) {
        stack<int> stk;
        int val = 1; // next value to be pushed
        bool flag = true; // assume the sequence is valid
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            /*
                To pop 'num' from the stack, all elements less than 'num' must be pushed first.
                1. Push elements into the stack until reach 'num' or the stack is full.
                2. If the top element is greater than 'num', cannot pop 'num' and the sequence is invalid.
            */
            while (stk.empty() || (stk.top() < num && (int)stk.size() < m)) { // less
                stk.emplace(val++);
            }
            // the stack must not be empty at the moment
            if (stk.top() == num) { // equal
                stk.pop();
            } else { // greater
                flag = false;
            }
        }
        flag ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
