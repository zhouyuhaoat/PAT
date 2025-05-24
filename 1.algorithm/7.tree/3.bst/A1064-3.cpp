/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 19:17:01
 *	modified:	2023-03-29 20:17:54
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805407749357568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1064 Complete Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805407749357568
*/

// @pintia code=start
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> in, level;

void levelTra(int inL, int inH, int id) {
    if (inL > inH) return;
    int size = inH - inL + 1;
    int height = log(size + 1) / log(2);
    int left = pow(2, height - 1) - 1; // left subtree
    int lastLevel = size - (pow(2, height) - 1);
    int inR = inL + left + min(lastLevel, (int)pow(2, height) / 2);
    // 2^height: the number of nodes in the last level if it is full
    // at most half of 2^height nodes in the left subtree
    level[id] = in[inR];
    levelTra(inL, inR - 1, 2 * id + 1);
    levelTra(inR + 1, inH, 2 * id + 2);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    level.resize(n);
    levelTra(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
