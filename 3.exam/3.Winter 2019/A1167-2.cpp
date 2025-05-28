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
map<int, int> res; // index -> value

void inTra(int index, int inL, int inH) {
    if (inL > inH) return;
    int inR = min_element(in.begin() + inL, in.begin() + inH + 1) - in.begin();
    res[index] = in[inR];
    inTra(index * 2, inL, inR - 1);
    inTra(index * 2 + 1, inR + 1, inH);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    inTra(1, 0, n - 1);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << it->second;
        next(it) != res.end() ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
