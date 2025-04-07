/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:24:58
 *	modified:	2023-04-05 23:55:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1478636026017230848 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1167 Cartesian Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478636026017230848
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> in;
map<int, int> ans; // level -> value

void dfs(int index, int s, int e) {
    if (s > e) return;
    int pos = min_element(in.begin() + s, in.begin() + e + 1) - in.begin();
    // position of the minimum value in the range [s, e]
    ans[index] = in[pos];
    dfs(index * 2, s, pos - 1);
    dfs(index * 2 + 1, pos + 1, e);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    dfs(1, 0, n - 1);
    for (auto it : ans) {
        if (it.first != 1) cout << " ";
        cout << it.second;
    }

    return 0;
}
// @pintia code=end