/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:54:39
 *	modified:	2023-04-03 02:59:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805350316752896 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1125 Chain the Ropes
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805350316752896
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    // greedy: minimum loss => maximum gain
    sort(data.begin(), data.end());
    stack<int> stk;
    stk.emplace(data[0]);
    for (int i = 1; i < n; i++) {
        int top = stk.top();
        stk.pop();
        stk.emplace((top + data[i]) / 2);
    }
    cout << stk.top() << "\n";

    return 0;
}
// @pintia code=end
