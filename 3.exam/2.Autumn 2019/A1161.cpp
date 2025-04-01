/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:33:11
 *	modified:	2023-04-05 20:57:47
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1478635524918910976 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1161 Merging Linked Lists
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635524918910976
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int addr, data, next;
};

vector<node> d(1e5);

int main(int argc, char const *argv[]) {

    int l1, l2, n;
    cin >> l1 >> l2 >> n;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id >> d[id].data >> d[id].next;
        d[id].addr = id;
    }
    vector<node> d1, d2;
    do {
        d1.emplace_back(d[l1]);
        l1 = d[l1].next;
    } while (l1 != -1);
    do {
        d2.emplace_back(d[l2]);
        l2 = d[l2].next;
    } while (l2 != -1);
    if (d1.size() < d2.size()) { // merge the shorter one into the longer one
        swap(d1, d2);
    }
    vector<node> ans;
    int idx = d2.size() - 1; // reverse order
    for (int i = 0; i < (int)d1.size(); i++) {
        ans.emplace_back(d1[i]);
        if ((i + 1) % 2 == 0 && idx >= 0) { // each two elements
            ans.emplace_back(d2[idx--]);
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << setfill('0') << setw(5) << ans[i].addr << " " << ans[i].data << " ";
        if (i < (int)ans.size() - 1) {
            cout << setfill('0') << setw(5) << ans[i + 1].addr << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
// @pintia code=end