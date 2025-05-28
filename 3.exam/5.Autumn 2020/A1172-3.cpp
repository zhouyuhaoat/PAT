/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 13:57:59
 *	modified:	2023-04-14 19:15:20
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1172 Panda and PP Milk
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173568
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> weight(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    vector<int> milk(n + 1, 200);
    for (int i = 2; i <= n; i++) { // left -> right
        if (weight[i] > weight[i - 1]) {
            milk[i] = milk[i - 1] + 100;
        } else if (weight[i] == weight[i - 1]) {
            milk[i] = milk[i - 1];
        }
    }
    for (int i = n - 1; i >= 1; i--) { // right -> left
        if (weight[i] > weight[i + 1]) {
            milk[i] = max(milk[i], milk[i + 1] + 100);
        } else if (weight[i] == weight[i + 1]) {
            milk[i] = max(milk[i], milk[i + 1]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += milk[i];
    }
    cout << sum << "\n";

    return 0;
}
// @pintia code=end
