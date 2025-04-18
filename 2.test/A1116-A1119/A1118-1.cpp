/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:40:19
 *	modified:	2023-04-03 00:50:34
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805354108403712 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1118 Birds in Forest
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805354108403712
*/

// @pintia code=start
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> f(1e4 + 1); // disjoint set union

int find(int x) {
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) { // path compression
        int z = a;
        a = f[a], f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        f[fa] = fb;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int b = 0;
    iota(f.begin(), f.end(), 0);
    for (int i = 0; i < n; i++) {
        int k, b1;
        cin >> k >> b1;
        b = max(b, b1);
        for (int j = 1; j < k; j++) {
            int b2;
            cin >> b2;
            joint(b1, b2);
            b = max(b, b2);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= b; i++) {
        if (f[i] == i) {
            cnt++;
        }
    }
    cout << cnt << " " << b << "\n";
    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++) {
        int b1, b2;
        cin >> b1 >> b2;
        if (find(b1) == find(b2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end
