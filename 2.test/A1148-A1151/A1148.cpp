/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 16:47:21
 *	modified:	2024-05-15 16:58:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1038429808099098624 compiler=GXX
    ProblemSet: Simple Version - PAT (Advanced Level) Practice
    Title: 1148 Werewolf
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038429808099098624
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> say(n + 1); // positive for human and negative for werewolf
    for (int i = 1; i <= n; i++) {
        cin >> say[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, wolf(n + 1, 1);
            wolf[i] = wolf[j] = -1; // assume i and j are werewolves
            for (int k = 1; k <= n; k++) {
                if (say[k] * wolf[abs(say[k])] < 0) { // liar
                    lie.emplace_back(k);
                }
            }
            if (lie.size() == 2 && wolf[lie[0]] + wolf[lie[1]] == 0) {
                // if there are exactly 2 liars and one of them is a werewolf
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << "No Solution\n";

    return 0;
}
// @pintia code=end
